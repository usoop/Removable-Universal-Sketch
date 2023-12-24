


#ifndef MOMENT_ESTIMATION_FILTER_CUCKOOFILTER_HPP
#define MOMENT_ESTIMATION_FILTER_CUCKOOFILTER_HPP

#include "filter_base.hpp"

using namespace std;
double LOAD_FACTOR = 0.95;
namespace datasketches {

    template<class T, class W, class A>
    class CuckooHeavyHitterFilter {
    private:
        cuckoofilter::CuckooPreFilter<T, 32, cuckoofilter::SingleTable_preFilter,
                cuckoofilter::XXHash64> *cuckoo_;


        int filter_size_;
        double load_factor_;
        int table_size_;


    public:

        CuckooHeavyHitterFilter() = default;

        explicit CuckooHeavyHitterFilter(int filter_size);

        CuckooHeavyHitterFilter(int filter_size, double load_factor);

        CuckooHeavyHitterFilter(const CuckooHeavyHitterFilter<T, W, A> &that);

        ~CuckooHeavyHitterFilter();

        void reset();

        void print_filter();

        void getAllHHs(vector <pair<T, uint32_t>> &HHs);

        bool isFull();

        inline bool has_old() {
            return true;
        }

        int check_membership(const T &new_id);

        int check_membership_and_get_index_tagindex(const T &new_id, size_t &index, uint16_t &tag_index);


        int32_t queryValue(T id) {
            int32_t new_freq, old_freq;

            cuckoofilter::Status status = cuckoo_->GetValues(id, new_freq, old_freq);
            if (status == cuckoofilter::Ok) {
                return new_freq;
            } else {
                return -1;
            }

        }


        int32_t queryValueByIndex_tagIndex(size_t &index, uint16_t &tag_index) {
            int32_t new_freq, old_freq;

            cuckoofilter::Status status = cuckoo_->GetValues(index, new_freq, old_freq);
            if (status == cuckoofilter::Ok) {
                return new_freq;
            } else {
                return -1;
            }

        }

        int get_filter_size();


        int insert_filter_after_sketch(T new_id, W new_count, T &kickedItem, cuckoofilter::Counter &kickedCounter);


        void set_value_with_index_heapindex(size_t index, uint16_t heap_index, W new_freq);


        CuckooHeavyHitterFilter<T, W, A> &operator=(const CuckooHeavyHitterFilter<T, W, A> &that);


        void
        insert_filter_before_sketch(bool &is_insert, bool &is_heavy, W &min_element_value, T new_id, A new_count = 1);

        bool insert_in_post_filter(T new_id, A new_estimate_count);

        bool insert_in_filter_with_lus(T new_id, A new_estimate_count, bool &is_kick, T &kicked_element_id,
                                       W &kicked_element_value);


        int get_value_by_index_tagindex(size_t index, uint16_t tag_index);

        int check_membership_and_get_index_heapindex(const T &new_id, size_t &index, uint16_t &heap_index);

        uint32_t get_value_by_index_heapindex(size_t index, uint16_t heap_index);

        uint32_t get_min_from_histogram();

        int bucket_has_empty(size_t index, uint32_t tag);

        int try_insert_to_empty(size_t index, uint32_t tag, int32_t new_freq);

        int try_kick(size_t index, uint32_t tag, uint32_t f_size_int,
                     T &kicked_item, uint32_t &kicked_new_freq, uint32_t &kicked_old_freq);
    };

    template<class T, class W, class A>
    int CuckooHeavyHitterFilter<T, W, A>::bucket_has_empty(size_t index, uint32_t tag) {
        cuckoofilter::Status status = cuckoo_->bucketHasEmpty(index, tag);
        if (status == cuckoofilter::Ok) {
            return 1;
        }
        return 0;
    }

    template<class T, class W, class A>
    int CuckooHeavyHitterFilter<T, W, A>::try_insert_to_empty(size_t index, uint32_t tag, int32_t new_freq) {
        cuckoofilter::Status status = cuckoo_->insertNew(index, tag, new_freq);
        if (status == cuckoofilter::Ok) {
            return 1;
        }
        return 0;
    }

    template<class T, class W, class A>
    int CuckooHeavyHitterFilter<T, W, A>::try_kick(size_t index, uint32_t tag, uint32_t f_size_int,
                                                   T &kicked_item, uint32_t &kicked_new_freq,
                                                   uint32_t &kicked_old_freq) {
        cuckoofilter::Counter kicked_counter;
        cuckoofilter::Status status = cuckoo_->AddByKick(index, tag, f_size_int, f_size_int, kicked_counter,
                                                         kicked_item);
        if (status == cuckoofilter::Ok) {
            kicked_new_freq = kicked_counter.new_freq;
            kicked_old_freq = kicked_counter.old_freq;
            return 1;
        }
        return 0;
    }

    template<class T, class W, class A>
    void
    CuckooHeavyHitterFilter<T, W, A>::set_value_with_index_heapindex(size_t index, uint16_t heap_index, W new_freq) {
        cuckoo_->updateByReplacement_ByIndexHeapindex(index, heap_index, new_freq);
    }


    template<class T, class W, class A>
    int CuckooHeavyHitterFilter<T, W, A>::check_membership_and_get_index_tagindex(const T &new_id,
                                                                                  size_t &index,
                                                                                  uint16_t &tag_index) {


        cuckoofilter::Status status = cuckoo_->ContainWithIndexTagindex(new_id, index, tag_index);

        if (status == cuckoofilter::Ok) {
            return 1;
        } else {
            return -1;
        }
    }


    template<class T, class W, class A>
    int CuckooHeavyHitterFilter<T, W, A>::check_membership_and_get_index_heapindex(const T &new_id,
                                                                                   size_t &index,
                                                                                   uint16_t &heap_index) {


        cuckoofilter::Status status = cuckoo_->ContainWithIndexHeapindex(new_id, index, heap_index);

        if (status == cuckoofilter::Ok) {
            return 1;
        } else {
            return -1;
        }
    }

    template<class T, class W, class A>
    int CuckooHeavyHitterFilter<T, W, A>::get_value_by_index_tagindex(size_t index,
                                                                      uint16_t tag_index) {


        uint32_t new_freq;
        uint32_t old_freq;
        cuckoofilter::Status status = cuckoo_->GetValuesByIndexTagindex(index, tag_index, new_freq, old_freq);

        if (status == cuckoofilter::Ok) {
            return new_freq;
        } else {
            return -1;
        }
    }


    template<class T, class W, class A>
    uint32_t CuckooHeavyHitterFilter<T, W, A>::get_value_by_index_heapindex(size_t index,
                                                                            uint16_t heap_index) {


        uint32_t new_freq;
        uint32_t old_freq;
        cuckoofilter::Status status = cuckoo_->GetValuesByIndexHeapindex(index, heap_index, new_freq, old_freq);

        if (status == cuckoofilter::Ok) {
            return new_freq;
        } else {
            return 0;
        }
    }

    template<class T, class W, class A>
    uint32_t CuckooHeavyHitterFilter<T, W, A>::get_min_from_histogram() {
        return 1 << (cuckoo_->histogram.min_bar_index);
    }

    template<class T, class W, class A>
    int CuckooHeavyHitterFilter<T, W, A>::check_membership(const T &new_id) {
        cuckoofilter::Status status = cuckoo_->Contain(new_id);


        if (status == cuckoofilter::Ok) {
            return 1;
        } else {
            return -1;
        }
    }


    template<class T, class W, class A>
    CuckooHeavyHitterFilter<T, W, A>::CuckooHeavyHitterFilter(int filter_size) {
        filter_size_ = filter_size;
        load_factor_ = LOAD_FACTOR;
        table_size_ = int(double(filter_size_) / LOAD_FACTOR);
        cuckoo_ = new cuckoofilter::CuckooPreFilter<T, 32, cuckoofilter::SingleTable_preFilter,
                cuckoofilter::XXHash64>(table_size_);


    }


    template<class T, class W, class A>
    CuckooHeavyHitterFilter<T, W, A>::~CuckooHeavyHitterFilter() {
        delete cuckoo_;


    }

    template<class T, class W, class A>
    void CuckooHeavyHitterFilter<T, W, A>::reset() {
        cuckoo_->reset();
    }

    template<class T, class W, class A>
    void CuckooHeavyHitterFilter<T, W, A>::getAllHHs(vector <pair<T, uint32_t>> &HHs) {
        vector < pair < uint32_t, pair < uint32_t, uint32_t>>> results;
        cuckoo_->getAllItems(results);
        T id;
        uint32_t new_freq;
        for (int i = 0; i != results.size(); i++) {
            id = results[i].first;
            new_freq = results[i].second.first;
            auto pr = make_pair(id, new_freq);
            HHs.emplace_back(pr);
        }
    }


    template<class T, class W, class A>
    void CuckooHeavyHitterFilter<T, W, A>::print_filter() {
        vector < pair < uint32_t, pair < uint32_t, uint32_t>>> results;
        cuckoo_->getAllItems(results);
        for (int i = 0; i != results.size(); i++) {
            cout << "ID:" << results[i].first << "," << " new_freq:" << results[i].second.first << ","
                 << " old_freq:" << results[i].second.first;
            if (i % 8 == 0) {
                cout << endl;
            }
        }
    }


    template<class T, class W, class A>
    int CuckooHeavyHitterFilter<T, W, A>::get_filter_size() {
        return filter_size_;
    }

    template<class T, class W, class A>
    int CuckooHeavyHitterFilter<T, W, A>::insert_filter_after_sketch(T new_id, W new_count, T &kickedItem,
                                                                     cuckoofilter::Counter &kickedCounter) {
        cuckoofilter::Status status = cuckoo_->AddFromSketch(new_id, new_count, kickedCounter, kickedItem);

        if (status == cuckoofilter::Ok & kickedCounter.new_freq != 0) {
            return 1;
        } else {
            return 0;
        }


    }


    template<class T, class W, class A>
    void
    CuckooHeavyHitterFilter<T, W, A>::insert_filter_before_sketch(bool &is_insert, bool &is_heavy, W &min_element_value,
                                                                  T new_id, A new_count) {
        is_insert = true;
        is_heavy = true;

        min_element_value = 0;
        W estimate_value = 0;

        cuckoofilter::Status status = cuckoo_->AddFromStream(new_id, new_count);
        if (status == cuckoofilter::InsertFailed) {
            is_insert = false;
            is_heavy = false;
            min_element_value = 1 << (cuckoo_->histogram.min_bar_index);
        }
    }

    template<class T, class W, class A>
    bool CuckooHeavyHitterFilter<T, W, A>::insert_in_post_filter(T new_id,
                                                                 A new_estimate_count) {
        return false;
    }

    template<class T, class W, class A>
    bool CuckooHeavyHitterFilter<T, W, A>::insert_in_filter_with_lus(T new_id, A new_estimate_count, bool &is_kick,
                                                                     T &kicked_element_id, W &kicked_element_value) {
        return 1;
    }

}
#endif
