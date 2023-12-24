


#ifndef MOMENT_ESTIMATION_SKETCHWITHCUCKOOPREFILTER_HPP
#define MOMENT_ESTIMATION_SKETCHWITHCUCKOOPREFILTER_HPP


template<class SketchTYPE, class FilterCounterTYPE, class SketchCounterTYPE>
class SketchWithCuckooPreFilter {
private:
    uint32_t depth_;
    uint32_t width_;
    uint32_t filterSize_;
    double totalCount_;
    uint32_t seed_;

    datasketches::CuckooHeavyHitterFilter <uint32_t, FilterCounterTYPE, int32_t> *ptr_filter_;
    datasketches::BaseSketch <uint32_t, SketchCounterTYPE, int32_t> *ptr_sketch_;

public:

    SketchWithCuckooPreFilter() = default;

    SketchWithCuckooPreFilter(uint32_t depth, uint32_t width, uint32_t filterSize, uint32_t seed) {
        depth_ = depth;
        width_ = width;
        filterSize_ = filterSize;
        seed_ = seed;
        ptr_filter_ = new datasketches::CuckooHeavyHitterFilter<uint32_t, FilterCounterTYPE, int32_t>(filterSize_);
        ptr_sketch_ = new SketchTYPE(depth_, width_, seed_);
        totalCount_ = 0;
    }


    SketchWithCuckooPreFilter(const SketchWithCuckooPreFilter &that) {
        depth_ = that.depth_;
        width_ = that.width_;
        filterSize_ = that.filterSize_;
        seed_ = that.seed_;
        ptr_filter_ = new datasketches::CuckooHeavyHitterFilter<uint32_t, FilterCounterTYPE, int32_t>(filterSize_);
        *ptr_filter_ = *that.ptr_filter_;
        ptr_sketch_ = new SketchTYPE(depth_, width_, seed_);
        *ptr_sketch_ = *that.ptr_sketch_;
        totalCount_ = that.totalCount_;
    }

    SketchWithCuckooPreFilter &operator=(const SketchWithCuckooPreFilter &that) {
        if (this == &that) {
            return *this;
        }

        depth_ = that.depth_;
        width_ = that.width_;
        filterSize_ = that.filterSize_;
        seed_ = that.seed_;
        ptr_filter_ = new datasketches::CuckooHeavyHitterFilter<uint32_t, FilterCounterTYPE, int32_t>(filterSize_);
        *ptr_filter_ = *that.ptr_filter_;
        ptr_sketch_ = new SketchTYPE(depth_, width_, seed_);
        *ptr_sketch_ = *that.ptr_sketch_;
        totalCount_ = that.totalCount_;

        return *this;

    }

    ~SketchWithCuckooPreFilter() {
        delete ptr_filter_;
        delete ptr_sketch_;
    }

    bool update(uint32_t id, int32_t weight) {
        totalCount_ += weight;
        bool is_heavy = false;
        bool is_insert_filter = false;
        FilterCounterTYPE min_element_value;

        int32_t int_min_element_value;
        FilterCounterTYPE queryValue;


        ptr_filter_->insert_filter_before_sketch(is_insert_filter, is_heavy,
                                                 min_element_value, id, weight);
        int_min_element_value = datasketches::get_value_to_int32t(min_element_value);
        if (is_insert_filter == false) {


            SketchCounterTYPE estimate_in_sketch;

            int32_t int_estimate_in_sketch;
            estimate_in_sketch = ptr_sketch_->update(id, weight);

            int_estimate_in_sketch = datasketches::get_value_to_int32t(estimate_in_sketch);
            if (int_estimate_in_sketch > int_min_element_value) {


                FilterCounterTYPE estimate_in_sketch_filterCounterType;
                estimate_in_sketch_filterCounterType = int_estimate_in_sketch;
                uint32_t kickedItem;
                cuckoofilter::Counter kickedCounter;
                int is_inserted = ptr_filter_->insert_filter_after_sketch(id, estimate_in_sketch_filterCounterType,
                                                                          kickedItem, kickedCounter);
                if (is_inserted) {
                    int32_t updateValueofKickedItem = kickedCounter.new_freq - kickedCounter.old_freq;
                    ptr_sketch_->update(kickedItem, datasketches::get_value_to_int32t(updateValueofKickedItem));
                    return true;
                } else {
                    return false;
                }
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    }

    void reset() {
        ptr_filter_->reset();
        ptr_sketch_->reset();
        totalCount_ = 0;
        seed_ = rand();
    }

    bool queryFromFilter(uint32_t key, int32_t &value) {
        int32_t queryResult = ptr_filter_->queryValue(key);
        if (queryResult != -1) {
            value = queryResult;
            return true;
        } else {
            return false;
        }
    }

    int32_t queryFromSketch(uint32_t key) {
        int value = datasketches::get_value_to_int32t(ptr_sketch_->estimate(key));
        return value;
    }

    int32_t query(uint32_t key) {
        int value = 0;
        bool isQueried = queryFromFilter(key, value);
        if (!isQueried) {
            value = queryFromSketch(key);
        }
        return value;
    }

    void get_hhs(vector <std::pair<uint32_t, uint32_t>> &vec) {

        ptr_filter_->getAllHHs(vec);
    }

    void get_hhs_by_eps(double eps, vector <std::pair<uint32_t, uint32_t>> &vec) {
        vector <std::pair<uint32_t, uint32_t>> tmpVec;
        get_hhs(tmpVec);
        double threshold = eps * totalCount_;
        for (auto i: tmpVec) {
            if (i.second > threshold) {
                vec.emplace_back(make_pair(i.first, i.second));
            }
        }
    }


    double get_totalcount() {
        return totalCount_;
    }


    void print_filter() {
        ptr_filter_->print_filter();
    }

};

#endif
