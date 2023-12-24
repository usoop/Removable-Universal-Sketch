#include "count_sketch.hpp"
#include "base_sketch.hpp"


template<class FilterTYPE, class SketchTYPE, class FilterCounterTYPE, class SketchCounterTYPE>
class SketchWithPostFilter {
private:
    uint32_t depth_;
    uint32_t width_;
    uint32_t filterSize_;
    double totalCount_;
    uint32_t seed_;

    datasketches::BaseFilter<uint32_t, FilterCounterTYPE, int32_t> *ptr_filter_;
    datasketches::BaseSketch<uint32_t, SketchCounterTYPE, int32_t> *ptr_sketch_;

public:

    SketchWithPostFilter() = default;

    SketchWithPostFilter(uint32_t depth, uint32_t width, uint32_t filterSize, uint32_t seed) {
        depth_ = depth;
        width_ = width;
        filterSize_ = filterSize;
        seed_ = seed;
        ptr_filter_ = new FilterTYPE(filterSize_);
        ptr_sketch_ = new SketchTYPE(depth_, width_, seed_);
        totalCount_ = 0;
    }


    SketchWithPostFilter(datasketches::BaseSketch<uint32_t, int32_t, int32_t> *ptr_pointer, uint32_t filterSize,
                         uint32_t seed) {


        filterSize_ = filterSize;
        seed_ = seed;
        ptr_filter_ = new FilterTYPE(filterSize_);
        ptr_sketch_ = std::move(ptr_pointer);
        totalCount_ = 0;
    }

    SketchWithPostFilter(const SketchWithPostFilter &that) {
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

    SketchWithPostFilter &operator=(const SketchWithPostFilter &that) {
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

    ~SketchWithPostFilter() {
        delete ptr_filter_;
        delete ptr_sketch_;
    }

    void update(uint32_t id, int32_t weight) {
        totalCount_ += weight;
        int32_t new_value = datasketches::get_value_to_int32t(ptr_sketch_->update(id, weight));
        ptr_filter_->insert_in_post_filter(id, new_value);
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
        int32_t value;

        uint32_t id;
        for (int j = 0; j != filterSize_; j++) {
            ptr_filter_->get_element_with_index(j, id, value);
            auto pr = make_pair(id, value);
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
};