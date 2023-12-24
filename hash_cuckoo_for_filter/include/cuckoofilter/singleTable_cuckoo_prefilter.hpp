


#ifndef CUCKOO_PREFILTER_SINGLETABLE_CUCKOO_PREFILTER_H
#define CUCKOO_PREFILTER_SINGLETABLE_CUCKOO_PREFILTER_H


#include <cassert>

#include <sstream>
#include <cstring>
#include <memory>
#include <vector>
#include <utility>


#include "bucket_cuckoo_prefilter.hpp"

using namespace std;

namespace cuckoofilter {
    extern const size_t kTagsPerBucket;


    template<size_t bits_per_tag>
    class SingleTable_preFilter {

        const size_t kBytesPerBucket =
                (bits_per_tag * kTagsPerBucket + 7) >> 3;
        const uint32_t kTagMask = (1ULL << bits_per_tag) - 1;


        const size_t kPaddingBuckets =
                ((((kBytesPerBucket + 7) / 8) * 8) - 1) / kBytesPerBucket;


        std::allocator<Bucket> alloc;
        Bucket *buckets_;
        const size_t num_buckets_;


        inline uint64_t HasTagInBucket(const size_t i, const uint32_t tag,
                                       bool &macro_support) const {

            uint64_t hv = 0;
            if (bits_per_tag == 4 && kTagsPerBucket == 4) {
                macro_support = true;
                const char *p = buckets_[i].bits_;
                uint64_t v = *(uint64_t *) p;
                hv = hasvalue4(v, tag);
            } else if (bits_per_tag == 8 && kTagsPerBucket == 4) {
                macro_support = true;
                const char *p = buckets_[i].bits_;
                uint64_t v = *(uint64_t *) p;
                hv = hasvalue8(v, tag);
            } else if (bits_per_tag == 12 && kTagsPerBucket == 4) {
                macro_support = true;
                const char *p = buckets_[i].bits_;
                uint64_t v = *(uint64_t *) p;
                hv = hasvalue12(v, tag);
            } else if (bits_per_tag == 16 && kTagsPerBucket == 4) {
                macro_support = true;
                const char *p = buckets_[i].bits_;
                uint64_t v = *(uint64_t *) p;
                hv = hasvalue16(v, tag);
            }
            return hv;
        }

    public:
        HISTOGRAM &histogram;

        explicit SingleTable_preFilter(const size_t num, HISTOGRAM &hist)
                : num_buckets_(num), histogram(hist) {


            buckets_ = alloc.allocate(num_buckets_ + kPaddingBuckets);
            for (uint32_t i = 0; i < num_buckets_ + kPaddingBuckets; i++) {
                alloc.construct(buckets_ + i, kBytesPerBucket, histogram);
            }
        }

        void reset() {

            for (uint32_t i = 0; i < num_buckets_ + kPaddingBuckets; i++) {
                alloc.destroy(buckets_ + i);
            }
            alloc.deallocate(buckets_, num_buckets_ + kPaddingBuckets);

            buckets_ = alloc.allocate(num_buckets_ + kPaddingBuckets);
            for (uint32_t i = 0; i < num_buckets_ + kPaddingBuckets; i++) {
                alloc.construct(buckets_ + i, kBytesPerBucket, histogram);
            }
        }

        ~SingleTable_preFilter() {
            for (uint32_t i = 0; i < num_buckets_ + kPaddingBuckets; i++) {
                alloc.destroy(buckets_ + i);
            }
            alloc.deallocate(buckets_, num_buckets_ + kPaddingBuckets);
        }

        void getAllItems(vector <pair<uint32_t, pair < uint32_t, uint32_t>>

        > &results){
            uint32_t fingerprint = 0;
            uint32_t new_freq = 0;
            uint32_t old_freq = 0;
            for (int i = 0; i < num_buckets_; i++) {
                for (int j = 0; j < kTagsPerBucket; j++) {
                    fingerprint = ReadTag(i, j);
                    if (fingerprint == 0) {
                        continue;
                    }
                    int32_t state = GetValueFromBucket(i, fingerprint, new_freq, old_freq);
                    if (state == 1) {
                        pair <uint32_t, uint32_t> p_freq = pair(new_freq, old_freq);
                        pair <uint32_t, pair<uint32_t, uint32_t>> p1 = pair(fingerprint, p_freq);
                        results.emplace_back(p1);
                    }

                }
            }
        }

        size_t NumBuckets() const {
            return num_buckets_;
        }

        size_t SizeInBytes() const {
            return kBytesPerBucket * num_buckets_;
        }

        size_t SizeInTags() const {
            return kTagsPerBucket * num_buckets_;
        }

        size_t GetTagsNumPerBucket() const {
            return kTagsPerBucket;
        }

        std::string Info() const {
            std::stringstream ss;
            ss << "SingleHashtable with tag size: " << bits_per_tag << " bits \n";
            ss << "\t\tAssociativity: " << kTagsPerBucket << "\n";
            ss << "\t\tTotal # of rows: " << num_buckets_ << "\n";
            ss << "\t\tTotal # slots: " << SizeInTags() << "\n";
            return ss.str();
        }


        inline uint32_t ReadTag(const size_t i, const size_t j) const {
            const char *p = buckets_[i].bits_;
            uint32_t tag;

            if (bits_per_tag == 2) {
                tag = *((uint8_t *) p) >> (j * 2);
            } else if (bits_per_tag == 4) {
                p += (j >> 1);
                tag = *((uint8_t *) p) >> ((j & 1) << 2);
            } else if (bits_per_tag == 8) {
                p += j;
                tag = *((uint8_t *) p);
            } else if (bits_per_tag == 12) {
                p += j + (j >> 1);
                tag = *((uint16_t *) p) >> ((j & 1) << 2);
            } else if (bits_per_tag == 16) {
                p += (j << 1);
                tag = *((uint16_t *) p);
            } else if (bits_per_tag == 32) {
                tag = ((uint32_t *) p)[j];
            }
            return tag & kTagMask;
        }


        inline void WriteTag(const size_t i, const size_t j, const uint32_t t) {
            char *p = buckets_[i].bits_;
            uint32_t tag = t & kTagMask;

            if (bits_per_tag == 2) {
                *((uint8_t *) p) |= tag << (2 * j);
            } else if (bits_per_tag == 4) {
                p += (j >> 1);
                if ((j & 1) == 0) {
                    *((uint8_t *) p) &= 0xf0;
                    *((uint8_t *) p) |= tag;
                } else {
                    *((uint8_t *) p) &= 0x0f;
                    *((uint8_t *) p) |= (tag << 4);
                }
            } else if (bits_per_tag == 8) {
                ((uint8_t *) p)[j] = tag;
            } else if (bits_per_tag == 12) {
                p += (j + (j >> 1));
                if ((j & 1) == 0) {
                    ((uint16_t *) p)[0] &= 0xf000;
                    ((uint16_t *) p)[0] |= tag;
                } else {
                    ((uint16_t *) p)[0] &= 0x000f;
                    ((uint16_t *) p)[0] |= (tag << 4);
                }
            } else if (bits_per_tag == 16) {
                ((uint16_t *) p)[j] = tag;
            } else if (bits_per_tag == 32) {
                ((uint32_t *) p)[j] = tag;
            }
        }

        inline bool FindTagInBuckets(const size_t i1, const size_t i2,
                                     const uint32_t tag) const {
            const char *p1 = buckets_[i1].bits_;
            const char *p2 = buckets_[i2].bits_;

            uint64_t v1 = *((uint64_t *) p1);
            uint64_t v2 = *((uint64_t *) p2);


            if (bits_per_tag == 4 && kTagsPerBucket == 4) {
                return hasvalue4(v1, tag) || hasvalue4(v2, tag);
            } else if (bits_per_tag == 8 && kTagsPerBucket == 4) {
                return hasvalue8(v1, tag) || hasvalue8(v2, tag);
            } else if (bits_per_tag == 12 && kTagsPerBucket == 4) {
                return hasvalue12(v1, tag) || hasvalue12(v2, tag);
            } else if (bits_per_tag == 16 && kTagsPerBucket == 4) {
                return hasvalue16(v1, tag) || hasvalue16(v2, tag);
            } else {
                for (size_t j = 0; j < kTagsPerBucket; j++) {
                    if ((ReadTag(i1, j) == tag) || (ReadTag(i2, j) == tag)) {
                        return true;
                    }
                }
                return false;
            }
        }

        inline bool FindTagInBucket(const size_t i, const uint32_t tag) const {

            bool macro_support = false;
            uint64_t hv = HasTagInBucket(i, tag, macro_support);
            if (macro_support) {
                return hv;
            } else {
                for (size_t j = 0; j < kTagsPerBucket; j++) {
                    if (ReadTag(i, j) == tag) {
                        return true;
                    }
                }
                return false;
            }
        }


        inline int32_t GetTagIndexInBucket(const size_t i, const uint32_t tag) const {
            bool macro_support = false;
            uint64_t hv = HasTagInBucket(i, tag, macro_support);
            if (macro_support) {

                if (hv == 0) {
                    return -1;
                } else {


                    for (int j = 0; j < (int32_t) kTagsPerBucket; j++) {
                        size_t tmp = bits_per_tag * (j + 1) - 1;
                        if ((hv >> tmp) & 1)
                            return j;
                    }
                }
            } else {

                for (int j = 0; j < (int32_t) kTagsPerBucket; j++) {
                    if (ReadTag(i, j) == tag) return j;
                }
            }
            return -1;
        }


        inline bool InsertTagToBucket(const size_t i, const Counter &ctr,
                                      const uint32_t tag, const bool kickout) {
            uint16_t target_tag_index = kTagsPerBucket;
            if (buckets_[i].IsTopEmpty()) {
                for (uint16_t j = 0; j < kTagsPerBucket; j++) {
                    if (ReadTag(i, j) == 0) {
                        target_tag_index = j;
                        WriteTag(i, j, tag);
                        buckets_[i].InsertCounter(j, ctr, true);
                        break;
                    }
                }
            } else if (kickout) {

                target_tag_index = GetTopCounterTagIndex(i);
                WriteTag(i, target_tag_index, tag);
                buckets_[i].InsertCounter(target_tag_index, ctr, false);
            } else {

                SPDLOG_ERROR("ERROR!");
                return false;
            }

            return !kickout;
        }


        inline bool InsertTagToBucket(const size_t i, const uint32_t tag,
                                      int32_t old_freq, int32_t new_freq,
                                      const bool kickout) {


            if (buckets_[i].IsTopEmpty()) {
                for (uint16_t j = 0; j < kTagsPerBucket; j++) {
                    if (ReadTag(i, j) == 0) {

                        WriteTag(i, j, tag);


                        buckets_[i].InsertCounter(j, old_freq, new_freq);

                        break;

                    }
                }
            } else if (kickout) {


                size_t r = GetTopCounterTagIndex(i);
                WriteTag(i, r, tag);

                buckets_[i].InsertCounter(r, old_freq, new_freq);
            }
            return !kickout;
        }


        inline int32_t
        GetValueFromBucket(const size_t i, const uint32_t tag, uint32_t &new_freq, uint32_t &old_freq) const {
            int32_t index = GetTagIndexInBucket(i, tag);

            if (index == -1) {
                return -1;
            } else {
                buckets_[i].QueryFreqByTagindex(index, new_freq, old_freq);
                return 1;
            }

            return buckets_[i].QueryNewFreq(index);

        }


        inline int32_t GetValueFromIndexTagindex(const size_t i, const uint16_t tag_index, uint32_t &new_freq,
                                                 uint32_t &old_freq) const {


            buckets_[i].QueryFreqByTagindex(tag_index, new_freq, old_freq);
            return 1;

        }


        inline int32_t GetValueFromIndexHeapindex(const size_t i, const uint16_t heap_index, uint32_t &new_freq,
                                                  uint32_t &old_freq) const {

            buckets_[i].QueryFreqByHeapindex(heap_index, new_freq, old_freq);
            return 1;
        }


        inline size_t NumTagsInBucket(const size_t i) const {
            size_t num = 0;
            for (size_t j = 0; j < kTagsPerBucket; j++) {
                if (ReadTag(i, j) != 0) {
                    num++;
                }
            }
            return num;
        }

        inline bool updateInnerCounterByIncrement(const size_t i, const uint16_t tag_index,
                                                  int32_t update_value) {
            return buckets_[i].UpdateCounterByIncrement(tag_index, update_value);
        }


        inline bool updateInnerCounterByReplacement_byTagindex(const size_t i, const uint16_t tag_index,
                                                               int32_t update_value) {
            return buckets_[i].UpdateCounterByReplacement_ByTagindex(tag_index, update_value);
        }


        inline bool updateInnerCounterByReplacement_byHeapindex(const size_t i, const uint16_t heap_index,
                                                                int32_t update_value) {
            return buckets_[i].UpdateCounterByReplacement_ByHeapindex(heap_index, update_value);
        }

        inline uint16_t GetTopCounterTagIndex(const size_t i) const {
            return buckets_[i].ConvertHeapIdxToTagIdx(0);
        }

        inline Counter const &GetCounterRefInBkt(const size_t i,
                                                 const uint16_t tag_index) {
            uint16_t heap_index = buckets_[i].ConvertTagIdxToHeapIdx(tag_index);
            return buckets_[i].GetCounterRef(heap_index);
        }

        inline uint16_t GetHeapindexByTagindex(const size_t i,
                                               const uint16_t tag_index) {
            uint16_t heap_index = buckets_[i].ConvertTagIdxToHeapIdx(tag_index);
            return heap_index;
        }


        inline double GetTopCounterValue(const size_t i) const {
            return buckets_[i].GetTopValue();
        }

        inline bool IsTopCounterEmpty(const size_t i) const {
            return buckets_[i].IsTopEmpty();
        }
    };

}

#include "singleTable_cuckoo_prefilter_impl.hpp"

#endif
