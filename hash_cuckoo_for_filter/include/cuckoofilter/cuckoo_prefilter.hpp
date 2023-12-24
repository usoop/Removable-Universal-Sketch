


#ifndef CUCKOO_PREFILTER_CUCKOO_PREFILTER_H
#define CUCKOO_PREFILTER_CUCKOO_PREFILTER_H


#include <algorithm>
#include <cassert>
#include <iomanip>
#include <limits>
#include <vector>
#include <sstream>
#include <cstring>
#include "global_var.hpp"
#include "pre_kicking_queue.hpp"

#include "singleTable_cuckoo_prefilter.hpp"

using namespace std;


extern double first_ts;


namespace cuckoofilter {


    template<typename ItemType, size_t bits_per_item,
            template<size_t> class TableType = SingleTable_preFilter,
            typename HashFamily = TwoIndependentMultiplyShift>
    class CuckooPreFilter {

        TableType<bits_per_item> *table_;


        PreKickingQueue *pkqueue;


        size_t num_items_;

        HashFamily hasher_;


        inline size_t IndexHash(uint32_t hv) const {


            return hv & (table_->NumBuckets() - 1);
        }


        inline uint32_t TagHash(uint32_t hv) const {
            uint32_t tag;
            tag = hv & ((1ULL << bits_per_item) - 1);

            tag += (tag == 0);
            return tag;
        }

        inline void GenerateIndexTagHash(const ItemType &item, size_t *index,
                                         uint32_t *tag) const {
            const uint64_t hash = hasher_(item);


            *index = IndexHash(hash >> 32);


            *tag = uint32_t(item);
        }


        inline size_t AltIndex(const size_t index, const uint32_t tag) const {


            return IndexHash((uint32_t) (index ^ (tag * 0x5bd1e995)));
        }


        Status AddImpl(size_t i, uint32_t tag, int32_t new_freq, int32_t old_freq, Counter &kickedCounter,
                       ItemType &kicked_item);


        double LoadFactor() const { return 1.0 * Size() / table_->SizeInTags(); }

        double BitsPerItem() const { return 8.0 * table_->SizeInBytes() / Size(); }

    public:
        HISTOGRAM histogram;

        explicit CuckooPreFilter(const size_t max_num_keys)
                : num_items_(0), hasher_() {


            size_t assoc = kTagsPerBucket;

            size_t num_buckets = upperpower2(std::max<uint64_t>(1, max_num_keys / assoc));


            double frac = (double) max_num_keys / num_buckets / assoc;
            if (frac > 0.96) {
                num_buckets <<= 1;
            }

            histogram.init_hist(30);
            table_ = new TableType<bits_per_item>(num_buckets, histogram);

            pkqueue = new PreKickingQueue(kMaxCuckooCount);
            SPDLOG_DEBUG("cuckoo filter bucket number: {}", table_->NumBuckets());
        }

        ~CuckooPreFilter() {
            delete pkqueue;
            delete table_;
        }


        void reset() {
            histogram.init_hist(30);
            table_->reset();
            pkqueue->reset();

        }

        void getAllItems(vector<pair<uint32_t, pair<uint32_t, uint32_t>>> &results) {
            table_->getAllItems(results);
        }


        Status AddFromStream(const ItemType &item, int32_t update_value);

        Status Add(const ItemType &item, int32_t update_value, Counter &kickedCounter, ItemType &kicked_item);

        Status AddFromSketch(const ItemType &item, int32_t new_freq, Counter &kickedCounter, ItemType &kicked_item);


        Status Contain(const ItemType &item) const;

        Status ContainWithIndexTagindex(const ItemType &item, size_t &index, uint16_t &tag_index);

        Status GetIndex(const ItemType &item) const;


        int32_t GetValues(const ItemType &key, uint32_t &new_freq, uint32_t &old_freq) const;

        int32_t GetValuesByIndexTagindex(size_t index, uint16_t tag_index,
                                         uint32_t &new_freq, uint32_t &old_freq) const;

        int32_t
        GetValuesByIndexHeapindex(size_t index, uint16_t heap_index, uint32_t &new_freq, uint32_t &old_freq) const;

        std::string GetFlowInfo(const ItemType &key, const double ts) const;


        std::string Info() const;

        void UpdateTimeWindow(const uint64_t cur_ts);


        size_t Size() const { return num_items_; }


        size_t SizeInBytes() const { return table_->SizeInBytes(); }

        Status updateByIncrement_ByIndexTag(const size_t &index, const uint16_t &tag_index, int32_t update_value);

        Status updateByReplacement_ByIndexTag(const size_t &index, const uint16_t &tag_index, int32_t update_value);

        Status
        updateByIncrement_ByIndexHeapindex(const size_t &index, const uint16_t &heap_index, int32_t update_value);

        Status
        updateByReplacement_ByIndexHeapindex(const size_t &index, const uint16_t &heap_index, int32_t update_value);

        Status queryByIndexTag(const size_t &index, const uint16_t &tag_index);

        Status ContainWithIndexHeapindex(const ItemType &item, size_t &index, uint16_t &tag_index);


        Status insertNew(const size_t &index, const uint32_t &tag, int32_t update_value);

        Status AddByKick(const size_t i, const uint32_t tag, int32_t new_freq, int32_t old_freq, Counter &kickedCounter,
                         ItemType &kicked_item);

        Status bucketHasEmpty(const size_t &index, const uint32_t &tag);
    };


    template<typename ItemType, size_t bits_per_item,
            template<size_t> class TableType, typename HashFamily>
    Status CuckooPreFilter<ItemType, bits_per_item, TableType, HashFamily>::Add(
            const ItemType &item, int32_t update_value, Counter &kickedCounter, ItemType &kicked_item) {
        size_t i1, i2;
        uint32_t tag;


        GenerateIndexTagHash(item, &i1, &tag);

        i2 = AltIndex(i1, tag);
        int32_t slot_val;


        if ((slot_val = table_->GetTagIndexInBucket(i1, tag)) != -1) {
            SPDLOG_TRACE("item in bucket {} slot {}", i1, slot_val);
            table_->updateInnerCounterByIncrement(i1, (uint16_t) slot_val, update_value);
            return Ok;
        }


        if ((slot_val = table_->GetTagIndexInBucket(i2, tag)) != -1) {
            SPDLOG_TRACE("item in bucket {} slot {}", i1, slot_val);
            table_->updateInnerCounterByIncrement(i2, (uint16_t) slot_val, update_value);
            return Ok;
        }

        SPDLOG_DEBUG("New flow inserted");


        return AddImpl(i1, tag, update_value, 0, kickedCounter, kicked_item);
    }


    template<typename ItemType, size_t bits_per_item,
            template<size_t> class TableType, typename HashFamily>
    Status CuckooPreFilter<ItemType, bits_per_item, TableType,
            HashFamily>::ContainWithIndexTagindex(const ItemType &item, size_t &index, uint16_t &tag_index) {
        size_t i1, i2;
        uint32_t tag;
        GenerateIndexTagHash(item, &i1, &tag);
        i2 = AltIndex(i1, tag);
        int32_t slot_val;


        if ((slot_val = table_->GetTagIndexInBucket(i1, tag)) != -1) {
            index = i1;
            tag_index = slot_val;
            return Ok;
        }

        if ((slot_val = table_->GetTagIndexInBucket(i2, tag)) != -1) {
            index = i2;
            tag_index = slot_val;
            return Ok;
        }
        return NotFound;
    }


    template<typename ItemType, size_t bits_per_item,
            template<size_t> class TableType, typename HashFamily>
    Status CuckooPreFilter<ItemType, bits_per_item, TableType,
            HashFamily>::ContainWithIndexHeapindex(const ItemType &item, size_t &index, uint16_t &heap_index) {
        size_t i1, i2;
        uint32_t tag;
        GenerateIndexTagHash(item, &i1, &tag);
        i2 = AltIndex(i1, tag);
        int32_t slot_val;


        if ((slot_val = table_->GetTagIndexInBucket(i1, tag)) != -1) {
            index = i1;
            heap_index = table_->GetHeapindexByTagindex(index, slot_val);

            return Ok;
        }

        if ((slot_val = table_->GetTagIndexInBucket(i2, tag)) != -1) {
            index = i2;
            heap_index = table_->GetHeapindexByTagindex(index, slot_val);
            return Ok;
        }
        return NotFound;
    }


    template<typename ItemType, size_t bits_per_item,
            template<size_t> class TableType, typename HashFamily>
    Status CuckooPreFilter<ItemType, bits_per_item, TableType,
            HashFamily>::updateByReplacement_ByIndexTag(const size_t &index, const uint16_t &tag_index,
                                                        int32_t update_value) {
        table_->updateInnerCounterByReplacement_byTagindex(index, (uint16_t) tag_index, update_value);


        return Ok;
    }


    template<typename ItemType, size_t bits_per_item,
            template<size_t> class TableType, typename HashFamily>
    Status CuckooPreFilter<ItemType, bits_per_item, TableType,
            HashFamily>::updateByReplacement_ByIndexHeapindex(const size_t &index, const uint16_t &heap_index,
                                                              int32_t update_value) {
        table_->updateInnerCounterByReplacement_byHeapindex(index, (uint16_t) heap_index, update_value);


        return Ok;
    }


    template<typename ItemType, size_t bits_per_item,
            template<size_t> class TableType, typename HashFamily>
    Status CuckooPreFilter<ItemType, bits_per_item, TableType,
            HashFamily>::updateByIncrement_ByIndexTag(const size_t &index, const uint16_t &tag_index,
                                                      int32_t update_value) {
        table_->updateInnerCounterByIncrement(index, (uint16_t) tag_index, update_value);
        return Ok;
    }


    template<typename ItemType, size_t bits_per_item,
            template<size_t> class TableType, typename HashFamily>
    Status CuckooPreFilter<ItemType, bits_per_item, TableType,
            HashFamily>::insertNew(const size_t &index, const uint32_t &tag,
                                   int32_t update_value) {

        size_t curindex = index;


        int32_t old_freq = 0;
        int32_t new_freq = update_value;
        if (table_->IsTopCounterEmpty(curindex)) {
            ++num_items_;
            table_->InsertTagToBucket(curindex, tag, old_freq, new_freq, false);
            histogram.insert_hist(new_freq);
            return Ok;
        }
        curindex = AltIndex(curindex, tag);

        if (table_->IsTopCounterEmpty(curindex)) {

            ++num_items_;
            table_->InsertTagToBucket(curindex, tag, old_freq, new_freq, false);
            histogram.insert_hist(new_freq);
            return Ok;
        }
        return InsertFailed;
    }


    template<typename ItemType, size_t bits_per_item,
            template<size_t> class TableType, typename HashFamily>
    Status CuckooPreFilter<ItemType, bits_per_item, TableType,
            HashFamily>::bucketHasEmpty(const size_t &index, const uint32_t &tag) {

        size_t curindex = index;


        if (table_->IsTopCounterEmpty(curindex)) {
            return Ok;
        }
        curindex = AltIndex(curindex, tag);

        if (table_->IsTopCounterEmpty(curindex)) {

            return Ok;
        }
        return NotEnoughSpace;
    }


    template<typename ItemType, size_t bits_per_item,
            template<size_t> class TableType, typename HashFamily>
    Status CuckooPreFilter<ItemType, bits_per_item, TableType, HashFamily>::AddFromStream(
            const ItemType &item, int32_t update_value) {
        size_t i1, i2;
        uint32_t tag;


        GenerateIndexTagHash(item, &i1, &tag);

        i2 = AltIndex(i1, tag);
        int32_t slot_val;


        if ((slot_val = table_->GetTagIndexInBucket(i1, tag)) != -1) {
            SPDLOG_TRACE("item in bucket {} slot {}", i1, slot_val);
            table_->updateInnerCounterByIncrement(i1, (uint16_t) slot_val, update_value);
            return Ok;
        }


        if ((slot_val = table_->GetTagIndexInBucket(i2, tag)) != -1) {
            SPDLOG_TRACE("item in bucket {} slot {}", i1, slot_val);
            table_->updateInnerCounterByIncrement(i2, (uint16_t) slot_val, update_value);
            return Ok;
        }

        SPDLOG_DEBUG("New flow inserted");


        size_t curindex = i1;


        int32_t old_freq = 0;
        int32_t new_freq = update_value;
        if (table_->IsTopCounterEmpty(curindex)) {
            ++num_items_;
            table_->InsertTagToBucket(curindex, tag, old_freq, new_freq, false);
            histogram.insert_hist(new_freq);
            return Ok;
        }
        curindex = AltIndex(curindex, tag);

        if (table_->IsTopCounterEmpty(curindex)) {

            ++num_items_;
            table_->InsertTagToBucket(curindex, tag, old_freq, new_freq, false);
            histogram.insert_hist(new_freq);
            return Ok;
        }

        return InsertFailed;
    }


    template<typename ItemType, size_t bits_per_item,
            template<size_t> class TableType, typename HashFamily>
    Status CuckooPreFilter<ItemType, bits_per_item, TableType, HashFamily>::AddFromSketch(const ItemType &item,
                                                                                          int32_t new_freq,
                                                                                          Counter &kickedCounter,
                                                                                          ItemType &kicked_item) {

        size_t i1;
        uint32_t tag;


        GenerateIndexTagHash(item, &i1, &tag);

        return AddImpl(i1, tag, new_freq, new_freq, kickedCounter, kicked_item);
    }


    template<typename ItemType, size_t bits_per_item,
            template<size_t> class TableType, typename HashFamily>
    Status CuckooPreFilter<ItemType, bits_per_item, TableType,
            HashFamily>::AddByKick(const size_t i,
                                   const uint32_t tag,
                                   int32_t new_freq,
                                   int32_t old_freq,
                                   Counter &kickedCounter,
                                   ItemType &kicked_item) {

        size_t curindex = i;
        uint32_t curtag = tag;
        pkqueue->Clear();
        size_t count;

        for (count = 0; count < kMaxCuckooCount; count++) {
            SPDLOG_DEBUG("AddImpl: bucket {} enqueue", curindex);
            pkqueue->Enqueue(curindex);

            curtag = table_->ReadTag(curindex, table_->GetTopCounterTagIndex(curindex));
            curindex = AltIndex(curindex, curtag);

            if (table_->IsTopCounterEmpty(curindex)) {
                ++num_items_;
                size_t bkt_idx_prev = pkqueue->GetItemByIndex(count);
                uint16_t prev_tag_index = table_->GetTopCounterTagIndex(bkt_idx_prev);
                uint32_t tmp_tag = table_->ReadTag(bkt_idx_prev, prev_tag_index);
                Counter const &prev_counter =
                        table_->GetCounterRefInBkt(bkt_idx_prev, prev_tag_index);
                table_->InsertTagToBucket(curindex, prev_counter, tmp_tag, false);

                histogram.insert_hist(new_freq);

                break;
            }
        }
        SPDLOG_DEBUG("count: {}", count);

        bool kick_flag = false;
        if (count == kMaxCuckooCount) {
            kick_flag = true;

            size_t tmp_argmin;
            double min_val = std::numeric_limits<double>::max();
            for (tmp_argmin = 0; tmp_argmin < kMaxCuckooCount; tmp_argmin++) {
                double tmp_val =
                        table_->GetTopCounterValue(pkqueue->GetItemByIndex(tmp_argmin));
                if (min_val > tmp_val) {
                    min_val = tmp_val;
                    count = tmp_argmin;
                }
            }

            if (new_freq <= min_val) {
                return InsertFailed;
            }

            histogram.delete_hist(int32_t(min_val));

            histogram.insert_hist(new_freq);


            if (kick_flag) {
                size_t kicked_bkt_idx = pkqueue->GetItemByIndex(count);
                uint16_t kicked_tag_index = table_->GetTopCounterTagIndex(kicked_bkt_idx);
                kickedCounter = table_->GetCounterRefInBkt(kicked_bkt_idx, kicked_tag_index);
                kicked_item = table_->ReadTag(kicked_bkt_idx, kicked_tag_index);
            }
        }


        size_t bkt_idx;
        bkt_idx = pkqueue->GetItemByIndex(count);
        size_t bkt_idx_prev;
        uint16_t prev_tag_index;
        uint32_t tmp_tag;

        for (size_t j = count; j >= 1; j--) {

            bkt_idx = pkqueue->GetItemByIndex(j);


            bkt_idx_prev = pkqueue->GetItemByIndex(j - 1);
            prev_tag_index = table_->GetTopCounterTagIndex(bkt_idx_prev);
            tmp_tag = table_->ReadTag(bkt_idx_prev, prev_tag_index);
            Counter const &prev_counter =
                    table_->GetCounterRefInBkt(bkt_idx_prev, prev_tag_index);

            table_->InsertTagToBucket(bkt_idx, prev_counter, tmp_tag, true);
        }


        bkt_idx = pkqueue->GetItemByIndex(0);
        table_->InsertTagToBucket(bkt_idx, tag, old_freq, new_freq, true);


        return Ok;
    }


    template<typename ItemType, size_t bits_per_item,
            template<size_t> class TableType, typename HashFamily>
    Status CuckooPreFilter<ItemType, bits_per_item, TableType,
            HashFamily>::AddImpl(const size_t i,
                                 const uint32_t tag,
                                 int32_t new_freq,
                                 int32_t old_freq,
                                 Counter &kickedCounter,
                                 ItemType &kicked_item
    ) {
        size_t curindex = i;
        uint32_t curtag = tag;


        if (old_freq == 0) {

            if (table_->IsTopCounterEmpty(curindex)) {
                ++num_items_;
                table_->InsertTagToBucket(curindex, tag, old_freq, new_freq, false);
                histogram.insert_hist(new_freq);
                return Ok;
            }
            curindex = AltIndex(curindex, tag);

            if (table_->IsTopCounterEmpty(curindex)) {

                ++num_items_;
                table_->InsertTagToBucket(curindex, tag, old_freq, new_freq, false);
                histogram.insert_hist(new_freq);
                return Ok;
            }
        }


        curindex = i;

        pkqueue->Clear();
        size_t count;

        for (count = 0; count < kMaxCuckooCount; count++) {
            SPDLOG_DEBUG("AddImpl: bucket {} enqueue", curindex);
            pkqueue->Enqueue(curindex);

            curtag = table_->ReadTag(curindex, table_->GetTopCounterTagIndex(curindex));
            curindex = AltIndex(curindex, curtag);

            if (table_->IsTopCounterEmpty(curindex)) {
                ++num_items_;
                size_t bkt_idx_prev = pkqueue->GetItemByIndex(count);
                uint16_t prev_tag_index = table_->GetTopCounterTagIndex(bkt_idx_prev);
                uint32_t tmp_tag = table_->ReadTag(bkt_idx_prev, prev_tag_index);
                Counter const &prev_counter =
                        table_->GetCounterRefInBkt(bkt_idx_prev, prev_tag_index);
                table_->InsertTagToBucket(curindex, prev_counter, tmp_tag, false);

                histogram.insert_hist(new_freq);

                break;
            }
        }
        SPDLOG_DEBUG("count: {}", count);

        bool kick_flag = false;
        if (count == kMaxCuckooCount) {
            kick_flag = true;

            size_t tmp_argmin;
            double min_val = std::numeric_limits<double>::max();
            for (tmp_argmin = 0; tmp_argmin < kMaxCuckooCount; tmp_argmin++) {
                double tmp_val =
                        table_->GetTopCounterValue(pkqueue->GetItemByIndex(tmp_argmin));
                if (min_val > tmp_val) {
                    min_val = tmp_val;
                    count = tmp_argmin;
                }
            }

            if (new_freq <= min_val) {
                return InsertFailed;
            }

            histogram.delete_hist(int32_t(min_val));

            histogram.insert_hist(new_freq);


            if (kick_flag) {
                size_t kicked_bkt_idx = pkqueue->GetItemByIndex(count);
                uint16_t kicked_tag_index = table_->GetTopCounterTagIndex(kicked_bkt_idx);
                kickedCounter = table_->GetCounterRefInBkt(kicked_bkt_idx, kicked_tag_index);
                kicked_item = table_->ReadTag(kicked_bkt_idx, kicked_tag_index);
            }
        }


        size_t bkt_idx;
        bkt_idx = pkqueue->GetItemByIndex(count);
        size_t bkt_idx_prev;
        uint16_t prev_tag_index;
        uint32_t tmp_tag;

        for (size_t j = count; j >= 1; j--) {

            bkt_idx = pkqueue->GetItemByIndex(j);


            bkt_idx_prev = pkqueue->GetItemByIndex(j - 1);
            prev_tag_index = table_->GetTopCounterTagIndex(bkt_idx_prev);
            tmp_tag = table_->ReadTag(bkt_idx_prev, prev_tag_index);
            Counter const &prev_counter =
                    table_->GetCounterRefInBkt(bkt_idx_prev, prev_tag_index);

            table_->InsertTagToBucket(bkt_idx, prev_counter, tmp_tag, true);
        }


        bkt_idx = pkqueue->GetItemByIndex(0);
        table_->InsertTagToBucket(bkt_idx, tag, old_freq, new_freq, true);


        return Ok;
    }

    template<typename ItemType, size_t bits_per_item,
            template<size_t> class TableType, typename HashFamily>
    Status CuckooPreFilter<ItemType, bits_per_item, TableType,
            HashFamily>::Contain(const ItemType &key) const {
        size_t i1, i2;
        uint32_t tag;

        GenerateIndexTagHash(key, &i1, &tag);
        i2 = AltIndex(i1, tag);

        assert(i1 == AltIndex(i2, tag));

        if (table_->FindTagInBuckets(i1, i2, tag)) {
            return Ok;
        } else {
            return NotFound;
        }
    }


    template<typename ItemType, size_t bits_per_item,
            template<size_t> class TableType, typename HashFamily>
    Status CuckooPreFilter<ItemType, bits_per_item, TableType,
            HashFamily>::GetIndex(const ItemType &key) const {
        size_t i1, i2;
        uint32_t tag;

        GenerateIndexTagHash(key, &i1, &tag);
        i2 = AltIndex(i1, tag);

        assert(i1 == AltIndex(i2, tag));

        if (table_->FindTagInBuckets(i1, i2, tag)) {
            return Ok;
        } else {
            return NotFound;
        }
    }


    template<typename ItemType, size_t bits_per_item,
            template<size_t> class TableType, typename HashFamily>
    int32_t CuckooPreFilter<ItemType, bits_per_item, TableType, HashFamily>::GetValues(
            const ItemType &key, uint32_t &new_freq, uint32_t &old_freq) const {
        size_t i1, i2;
        uint32_t tag;


        int32_t state;
        GenerateIndexTagHash(key, &i1, &tag);
        i2 = AltIndex(i1, tag);

        assert(i1 == AltIndex(i2, tag));

        state = table_->GetValueFromBucket(i1, tag, new_freq, old_freq);
        if (state == -1) {
            state = table_->GetValueFromBucket(i2, tag, new_freq, old_freq);
        }
        return state;
    }


    template<typename ItemType, size_t bits_per_item,
            template<size_t> class TableType, typename HashFamily>
    int32_t CuckooPreFilter<ItemType, bits_per_item, TableType, HashFamily>::GetValuesByIndexTagindex(
            size_t index, uint16_t tag_index, uint32_t &new_freq, uint32_t &old_freq) const {

        Status status = table_->GetValueFromIndexTagindex(index, tag_index, new_freq, old_freq);
        if (status == Ok) {
            return 1;
        } else {
            return 0;
        }
    }


    template<typename ItemType, size_t bits_per_item,
            template<size_t> class TableType, typename HashFamily>
    int32_t CuckooPreFilter<ItemType, bits_per_item, TableType, HashFamily>::GetValuesByIndexHeapindex(
            size_t index, uint16_t heap_index, uint32_t &new_freq, uint32_t &old_freq) const {

        Status status = table_->GetValueFromIndexHeapindex(index, heap_index, new_freq, old_freq);
        if (status == Ok) {
            return 1;
        } else {
            return 0;
        }
    }

    template<typename ItemType, size_t bits_per_item,
            template<size_t> class TableType, typename HashFamily>
    std::string
    CuckooPreFilter<ItemType, bits_per_item, TableType, HashFamily>::GetFlowInfo(
            const ItemType &key, const double ts) const {
        size_t i1, i2;
        uint32_t tag;
        std::stringstream ss;

        SPDLOG_DEBUG("-----Generate Index-----");
        GenerateIndexTagHash(key, &i1, &tag);
        i2 = AltIndex(i1, tag);

        assert(i1 == AltIndex(i2, tag));

        size_t bucket_num = i1;
        int32_t tag_index = table_->GetTagIndexInBucket(i1, tag);
        if (tag_index == -1) {
            bucket_num = i2;
        }

        SPDLOG_DEBUG("bucket number: {}, tag: {}", bucket_num, tag);

        SPDLOG_DEBUG("-----Query bucket {}, tag index {}-----", bucket_num, tag_index);
        ss << "persis: " << std::fixed << std::setprecision(6) << table_->GetValueFromBucket(bucket_num, tag, ts)
           << "\n\n";
        return ss.str();
    }

    template<typename ItemType, size_t bits_per_item,
            template<size_t> class TableType, typename HashFamily>
    std::string CuckooPreFilter<ItemType, bits_per_item, TableType, HashFamily>::Info() const {


        std::stringstream ss;
        ss << "CuckooFilter Status:\n"

           << "\t\t" << table_->Info() << "\n"
           << "\t\tKeys stored: " << Size() << "\n"
           << "\t\tLoad factor: " << LoadFactor() << "\n"
           << "\t\tHashtable size: " << (table_->SizeInBytes() >> 10) << " KB\n";
        if (Size() > 0) {
            ss << "\t\tbit/key:   " << BitsPerItem() << "\n";
        } else {
            ss << "\t\tbit/key:   N/A\n";
        }
        return ss.str();
    }


}

#include "cuckoo_prefilter_impl.hpp"

#endif
