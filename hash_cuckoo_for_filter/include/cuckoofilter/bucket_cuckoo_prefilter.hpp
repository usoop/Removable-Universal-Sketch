


#ifndef BUCKET_CUCKOO_PREFILTER_H
#define BUCKET_CUCKOO_PREFILTER_H


#include <cmath>
#include <cstring>
#include "counter_cuckoo_prefilter.hpp"

namespace cuckoofilter {
    extern const size_t kTagsPerBucket;


    class Bucket {
    public:
        HISTOGRAM &histogram;

        Bucket(const size_t kBytesPerBucket, HISTOGRAM &hist) : histogram(hist) {
            bits_ = new char[kBytesPerBucket];
            counter = new Counter[kTagsPerBucket];
            memset(bits_, 0, kBytesPerBucket);
        }

        ~Bucket() {
            delete[] bits_;
            delete[] counter;
        }

        size_t GetTopTagIndex() const { return counter[0].tag_idx; }

        bool IsTopEmpty() const { return (counter[0].new_freq == 0); }

        bool IsSlotEmpty(const uint16_t heap_index) const {
            return (counter[heap_index].new_freq == 0);
        }

        inline uint16_t ConvertHeapIdxToTagIdx(const size_t heap_index) {
            return counter[heap_index].tag_idx;
        }

        int32_t ConvertTagIdxToHeapIdx(const uint16_t tag_index);


        inline double GetTopValue() const { return counter[0].new_freq; };

        Counter const &GetCounterRef(const uint16_t heap_index);

        void InsertCounter(const uint16_t tag_index, const Counter &ctr,
                           const bool is_top_empty);


        void InsertCounter(const uint16_t tag_index, const int32_t old_freq, const int32_t new_freq);


        bool UpdateCounterByIncrement(const uint16_t tag_index, const int32_t update_value);

        bool UpdateCounterByReplacement_ByTagindex(const uint16_t tag_index, const int32_t update_value);


        double QueryNewFreq(const uint16_t tag_index);

        void QueryFreqByTagindex(const uint16_t tag_index, uint32_t &new_freq, uint32_t &old_freq);

        void QueryFreqByHeapindex(const uint16_t heap_index, uint32_t &new_freq, uint32_t &old_freq);


        char *bits_;
        Counter *counter;


        bool UpdateCounterByReplacement_ByHeapindex(const uint16_t heap_index, const int32_t update_value);

    private:
        bool heap_priority(const uint16_t i, const uint16_t j) const;

        uint16_t sink_down(uint16_t i);

        uint16_t sink_up(uint16_t i);

        void AdjustNewFreqByIncrement(const uint16_t heap_idx, const int32_t update_value);

        bool AdjustNewFreqByReplacement(const uint16_t heap_idx, const int32_t update_to_value);


    } __attribute__((__packed__));
}

#include "bucket_cuckoo_prefilter_impl.hpp"

#endif
