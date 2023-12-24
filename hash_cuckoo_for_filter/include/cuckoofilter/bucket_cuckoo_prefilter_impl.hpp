


#ifndef BUCKET_CUCKOO_PREFILTER_IMPL_H
#define BUCKET_CUCKOO_PREFILTER_IMPL_H


#include <cmath>
#include <cmath>
#include <cassert>
#include <cstring>
#include <utility>
#include <vector>
#include <cstdint>


extern const std::vector<double> global_win_vec;


extern const uint32_t win_num;

extern const double gp_alpha;
extern const double gp_beta;
extern const double gp_gamma;


namespace cuckoofilter {


    int32_t Bucket::ConvertTagIdxToHeapIdx(const uint16_t tag_index) {
        uint16_t heap_index = kTagsPerBucket;
        for (uint32_t j = 0; j < (uint32_t) kTagsPerBucket; j++) {
            if (counter[j].tag_idx == tag_index) {
                heap_index = j;
                break;
            }
        }


        assert(heap_index < kTagsPerBucket);
        return heap_index;
    }

    Counter const &Bucket::GetCounterRef(const uint16_t heap_index) {
        return counter[heap_index];
    }


    void Bucket::InsertCounter(const uint16_t tag_index, const Counter &ctr,
                               const bool is_top_empty) {
        if (is_top_empty) {

            counter[0].tag_idx = tag_index;
        }
        counter[0].new_freq = ctr.new_freq;
        counter[0].old_freq = ctr.old_freq;

        sink_down(0);
    }


    void Bucket::InsertCounter(const uint16_t tag_index, const int32_t old_freq, const int32_t new_freq) {
        counter[0].tag_idx = tag_index;
        counter[0].old_freq = old_freq;
        counter[0].new_freq = new_freq;
        sink_down(0);
    }


    bool Bucket::UpdateCounterByIncrement(const uint16_t tag_index, const int32_t update_value) {
        for (uint16_t heap_idx = 0; heap_idx < kTagsPerBucket; heap_idx++) {
            if (counter[heap_idx].tag_idx == tag_index) {

                AdjustNewFreqByIncrement(heap_idx, update_value);


                if (update_value > 0) {
                    sink_down(heap_idx);
                } else {
                    sink_up(heap_idx);
                }
                return true;
            }
        }

        return false;
    }


    bool Bucket::UpdateCounterByReplacement_ByTagindex(const uint16_t tag_index, const int32_t update_value) {
        bool biggerThanBefore;
        for (uint16_t heap_idx = 0; heap_idx < kTagsPerBucket; heap_idx++) {
            if (counter[heap_idx].tag_idx == tag_index) {

                biggerThanBefore = AdjustNewFreqByReplacement(heap_idx, update_value);


                if (biggerThanBefore) {
                    sink_down(heap_idx);
                } else {
                    sink_up(heap_idx);
                }
                return true;
            }
        }

        return false;
    }


    bool Bucket::UpdateCounterByReplacement_ByHeapindex(const uint16_t heap_index, const int32_t update_value) {
        bool biggerThanBefore;


        biggerThanBefore = AdjustNewFreqByReplacement(heap_index, update_value);


        if (biggerThanBefore) {
            sink_down(heap_index);
        } else {
            sink_up(heap_index);
        }
        return true;


        return false;
    }


    void Bucket::QueryFreqByTagindex(const uint16_t tag_index, uint32_t &new_freq, uint32_t &old_freq) {
        uint16_t heap_index = ConvertTagIdxToHeapIdx(tag_index);
        new_freq = counter[heap_index].new_freq;
        old_freq = counter[heap_index].new_freq;
    }

    void Bucket::QueryFreqByHeapindex(const uint16_t heap_index, uint32_t &new_freq, uint32_t &old_freq) {
        new_freq = counter[heap_index].new_freq;
        old_freq = counter[heap_index].new_freq;
    }


    double Bucket::QueryNewFreq(const uint16_t tag_index) {
        uint16_t heap_index = ConvertTagIdxToHeapIdx(tag_index);
        double ret_newfreq = counter[heap_index].new_freq;

        return ret_newfreq;
    }


    bool Bucket::heap_priority(const uint16_t i, const uint16_t j) const {
        if (IsSlotEmpty(i)) {
            return true;
        }

        if (IsSlotEmpty(j)) {
            return false;
        }

        if (counter[i].new_freq > counter[j].new_freq) {
            return false;
        } else {
            return true;
        }
    }


    uint16_t Bucket::sink_down(uint16_t i) {
        while (static_cast<size_t>(2 * i + 1) < kTagsPerBucket) {
            uint16_t j = 2 * i + 1;
            if (j < kTagsPerBucket - 1 && !heap_priority(j, j + 1)) {
                j++;
            }
            if (heap_priority(i, j)) {
                break;
            }
            std::swap(counter[i], counter[j]);
            i = j;
        }
        return i;
    }


    uint16_t Bucket::sink_up(uint16_t i) {
        while (static_cast<size_t>(i) != 0) {
            uint16_t j = i / 2;
            if (!heap_priority(i, j)) {
                break;
            }
            std::swap(counter[i], counter[j]);
            i = j;
        }
        return i;
    }


    void Bucket::AdjustNewFreqByIncrement(const uint16_t heap_idx, const int32_t update_value) {
        assert(counter[heap_idx].new_freq != 0);
        histogram.delete_hist(counter[heap_idx].new_freq);
        counter[heap_idx].new_freq += update_value;
        histogram.delete_hist(counter[heap_idx].new_freq);
    }


    bool Bucket::AdjustNewFreqByReplacement(const uint16_t heap_idx, const int32_t update_value) {
        assert(counter[heap_idx].new_freq != 0);
        bool biggerThanBefore;
        if (counter[heap_idx].new_freq <= update_value) {
            biggerThanBefore = true;
        } else {
            biggerThanBefore = false;
        }
        histogram.delete_hist(counter[heap_idx].new_freq);
        counter[heap_idx].new_freq = update_value;
        histogram.delete_hist(counter[heap_idx].new_freq);
        return biggerThanBefore;
    }

}


#endif
