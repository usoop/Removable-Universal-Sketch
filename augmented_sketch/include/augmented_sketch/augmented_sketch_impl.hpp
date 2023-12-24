#ifndef AUGMENTED_SKETCH_IMPL_HPP_
#define AUGMENTED_SKETCH_IMPL_HPP_

#include <cstdint>

namespace datasketches {

    template<class T, class W1, class W2, class F, class S>
    AugmentedSketch<T, W1, W2, F, S>::AugmentedSketch(int filter_size, int sketch_depth, int sketch_width,
                                                      int sketch_seed) {
        totalcount_ = 0;
        number_of_insert_sketch_ = 0;
        filter_size_ = filter_size;


        sketch_depth_ = sketch_depth;
        sketch_width_ = sketch_width;
        sketch_seed_ = sketch_seed;
        p_filter_ = new F(filter_size);

        p_sketch_ = new S(sketch_depth, sketch_width, sketch_seed);
    }

    template<class T, class W1, class W2, class F, class S>
    AugmentedSketch<T, W1, W2, F, S>::AugmentedSketch(const AugmentedSketch <T, W1, W2, F, S> &that) {
        totalcount_ = that.totalcount_;

        number_of_insert_sketch_ = that.number_of_insert_sketch_;

        filter_size_ = that.filter_size_;
        sketch_depth_ = that.sketch_depth_;
        sketch_width_ = that.sketch_width_;
        sketch_seed_ = that.sketch_seed_;
        p_filter_ = new F(filter_size_);
        *p_filter_ = *that.p_filter_;

        p_sketch_ = new S(sketch_depth_, sketch_width_, sketch_seed_);
        *p_sketch_ = *that.p_sketch_;

    }

    template<class T, class W1, class W2, class F, class S>
    AugmentedSketch <T, W1, W2, F, S> &
    AugmentedSketch<T, W1, W2, F, S>::operator=(const AugmentedSketch <T, W1, W2, F, S> &that) {
        if (this == &that) {
            return *this;
        }
        totalcount_ = that.totalcount_;
        number_of_insert_sketch_ = that.number_of_insert_sketch_;
        filter_size_ = that.filter_size_;
        sketch_depth_ = that.sketch_depth_;
        sketch_width_ = that.sketch_width_;
        sketch_seed_ = that.sketch_seed_;
        p_filter_ = new F(filter_size_);
        *p_filter_ = *that.p_filter_;
        p_sketch_ = new S(sketch_depth_, sketch_width_, sketch_seed_);
        *p_sketch_ = *that.p_sketch_;
        return *this;
    }


    template<class T, class W1, class W2, class F, class S>
    void AugmentedSketch<T, W1, W2, F, S>::print_filter() {
        p_filter_->print_filter();
    }

    template<class T, class W1, class W2, class F, class S>
    void AugmentedSketch<T, W1, W2, F, S>::reset() {
        p_filter_->reset();
        p_sketch_->reset();
        totalcount_ = 0;
        number_of_insert_sketch_ = 0;
    }


    template<class T, class W1, class W2, class F, class S>
    void AugmentedSketch<T, W1, W2, F, S>::print_sketch() {
        p_sketch_->print_sketch();
    }

    template<class T, class W1, class W2, class F, class S>
    int32_t AugmentedSketch<T, W1, W2, F, S>::query(T key) {
        int value = queryFromFilter(key);
        if (value == -1) {
            value = queryFromSketch(key);
        }
        return value;
    }

    template<class T, class W1, class W2, class F, class S>
    int32_t AugmentedSketch<T, W1, W2, F, S>::queryFromFilter(T key) {

        int index = p_filter_->check_membership(key);
        if (index != -1) {
            W1 value = 0;
            value = p_filter_->get_value_with_index(index);
            return get_value_to_int32t(value);
        } else {
            return -1;
        }
    }


    template<class T, class W1, class W2, class F, class S>
    int32_t AugmentedSketch<T, W1, W2, F, S>::queryFromSketch(T key) {
        int value = get_value_to_int32t(p_sketch_->estimate(key));
        return value;
    }

    template<class T, class W1, class W2, class F, class S>
    int AugmentedSketch<T, W1, W2, F, S>::get_filter_size() {
        return p_filter_->get_filter_size();
    }

    template<class T, class W1, class W2, class F, class S>
    void AugmentedSketch<T, W1, W2, F, S>::get_element_in_filter_with_index(int index, T &id, W1 &value) {
        p_filter_->get_element_with_index(index, id, value);
    }


    template<class T, class W1, class W2, class F, class S>
    bool AugmentedSketch<T, W1, W2, F, S>::update_asketch(T new_id, int32_t new_count) {
        totalcount_ = totalcount_ + new_count;
        bool is_heavy = false;
        bool is_insert_filter = false;
        T min_element_id;
        W1 min_element_value;

        int32_t uint_min_element_value;
        p_filter_->insert_in_filter_with_sketch(is_insert_filter, is_heavy, min_element_id, min_element_value, new_id,
                                                new_count);

        uint_min_element_value = min_element_value;
        if (is_insert_filter == false) {
            number_of_insert_sketch_++;
            W2 estimate_in_sketch;

            int32_t uint_estimate_in_sketch;
            estimate_in_sketch = p_sketch_->update(new_id, new_count);
            uint_estimate_in_sketch = estimate_in_sketch;
            if (uint_estimate_in_sketch > uint_min_element_value) {
                p_filter_->replace_min_element(new_id, uint_estimate_in_sketch);
                p_sketch_->update_with_asketch(min_element_id, uint_min_element_value);
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    }

    template<class T, class W1, class W2, class F, class S>
    bool AugmentedSketch<T, W1, W2, F, S>::update(T new_id, int32_t new_count) {
        update_asketch(new_id, new_count);
        return true;
    }


    template<class T, class W, class A, class F, class S>
    bool AugmentedSketch<T, W, A, F, S>::checkmembership_in_filter(const T &new_id) {
        if (p_filter_->check_membership(new_id) == -1)
            return 0;

        return 1;
    }

    template<class T, class W, class A, class F, class S>
    uint32_t AugmentedSketch<T, W, A, F, S>::get_totalcount() {
        return totalcount_;
    }

    template<class T, class W1, class W2, class F, class S>

    void AugmentedSketch<T, W1, W2, F, S>::get_hhs(vector <std::pair<T, uint32_t>> &vec) {
        W1 value;

        T id;
        for (int j = 0; j != filter_size_; j++) {
            p_filter_->get_element_with_index(j, id, value);
            auto pr = make_pair(id, value);
            vec.push_back(pr);
        }
    }


    template<class T, class W, class A, class F, class S>
    AugmentedSketch<T, W, A, F, S>::~AugmentedSketch() {

        delete p_filter_;
        delete p_sketch_;
    }

}
#endif