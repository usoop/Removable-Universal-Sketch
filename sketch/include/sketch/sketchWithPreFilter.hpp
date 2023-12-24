#include "count_sketch.hpp"
#include "base_sketch.hpp"


template<class FilterTYPE, class SketchTYPE, class FilterCounterTYPE, class SketchCounterTYPE>
class SketchWithPreFilter {
private:
    uint32_t depth_;
    uint32_t width_;
    uint32_t filterSize_;
    double totalCount_;
    uint32_t seed_;

    datasketches::BaseFilter<uint32_t, FilterCounterTYPE, int32_t> *ptr_filter_;
    datasketches::BaseSketch<uint32_t, SketchCounterTYPE, int32_t> *ptr_sketch_;

public:

    SketchWithPreFilter() = default;

    SketchWithPreFilter(uint32_t depth, uint32_t width, uint32_t filterSize, uint32_t seed) {
        depth_ = depth;
        width_ = width;
        filterSize_ = filterSize;
        seed_ = seed;
        ptr_filter_ = new FilterTYPE(filterSize_);
        ptr_sketch_ = new SketchTYPE(depth_, width_, seed_);
        totalCount_ = 0;
    }


    SketchWithPreFilter(const SketchWithPreFilter &that) {
        depth_ = that.depth_;
        width_ = that.width_;
        filterSize_ = that.filterSize_;
        seed_ = that.seed_;
        ptr_filter_ = new FilterTYPE(filterSize_);
        *ptr_filter_ = *that.ptr_filter_;
        ptr_sketch_ = new SketchTYPE(depth_, width_, seed_);
        *ptr_sketch_ = *that.ptr_sketch_;
        totalCount_ = that.totalCount_;
    }

    SketchWithPreFilter &operator=(const SketchWithPreFilter &that) {
        if (this == &that) {
            return *this;
        }

        depth_ = that.depth_;
        width_ = that.width_;
        filterSize_ = that.filterSize_;
        seed_ = that.seed_;
        ptr_filter_ = new FilterTYPE(filterSize_);
        *ptr_filter_ = *that.ptr_filter_;
        ptr_sketch_ = new SketchTYPE(depth_, width_, seed_);
        *ptr_sketch_ = *that.ptr_sketch_;
        totalCount_ = that.totalCount_;

        return *this;

    }

    ~SketchWithPreFilter() {
        delete ptr_filter_;
        delete ptr_sketch_;
    }

    bool update(uint32_t id, int32_t weight) {
        totalCount_ += weight;
        bool is_heavy = false;
        bool is_insert_filter = false;
        uint32_t min_element_id;
        FilterCounterTYPE min_element_value;

        int32_t uint_min_element_value;
        FilterCounterTYPE queryValue;
        queryValue = ptr_filter_->insert_in_filter_with_sketch(is_insert_filter, is_heavy,
                                                               min_element_id, min_element_value, id, weight);
        uint_min_element_value = datasketches::get_value_to_int32t(min_element_value);
        if (is_insert_filter == false) {


            SketchCounterTYPE estimate_in_sketch;

            int32_t uint_estimate_in_sketch;
            estimate_in_sketch = ptr_sketch_->update(id, weight);

            uint_estimate_in_sketch = datasketches::get_value_to_int32t(estimate_in_sketch);
            if (uint_estimate_in_sketch > uint_min_element_value) {

                if (queryValue > 0) {

                    ptr_sketch_->update(min_element_id, datasketches::get_value_to_int32t(queryValue));
                }
                FilterCounterTYPE estimate_in_sketch_filterCounterType;
                estimate_in_sketch_filterCounterType = uint_estimate_in_sketch;
                ptr_filter_->replace_min_element(id, estimate_in_sketch_filterCounterType);

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
        int index = ptr_filter_->check_membership(key);
        if (index != -1) {
            value = ptr_filter_->get_value_with_index(index);
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
        FilterCounterTYPE value;

        uint32_t id;
        for (int j = 0; j != filterSize_; j++) {
            ptr_filter_->get_element_with_index(j, id, value);
            auto pr = make_pair(id, datasketches::get_value_to_int32t(value));
            vec.emplace_back(pr);
        }
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