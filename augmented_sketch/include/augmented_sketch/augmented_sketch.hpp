#ifndef AUGMENTED_SKETCH_HPP_
#define AUGMENTED_SKETCH_HPP_

#include <cstdint>


#include <memory>

namespace datasketches {


    template<class T, class W1, class W2, class F, class S>
    class AugmentedSketch {

    private:

        uint32_t totalcount_;

        uint32_t number_of_insert_sketch_;

        uint32_t filter_size_;
        uint32_t sketch_depth_;
        uint32_t sketch_width_;
        uint32_t sketch_seed_;


        datasketches::BaseFilter<T, W1, int32_t> *p_filter_;

        datasketches::BaseSketch<T, W2, int32_t> *p_sketch_;

    public:

        AugmentedSketch() = default;

        AugmentedSketch(int filter_size, int sketch_depth, int sketch_width, int sketch_seed);

        AugmentedSketch(const AugmentedSketch &that);

        AugmentedSketch<T, W1, W2, F, S> &operator=(const AugmentedSketch<T, W1, W2, F, S> &that);

        void print_filter();

        void print_sketch();

        int32_t query(T key);

        int32_t queryFromFilter(T key);

        int32_t queryFromSketch(T key);

        void reset();

        bool update_asketch(T new_id, int32_t new_count);

        bool update(T new_id, int32_t new_count);

        int get_filter_size();

        uint32_t get_totalcount();


        void get_hhs(vector <std::pair<T, uint32_t>> &vec);

        bool checkmembership_in_filter(const T &new_id);

        void get_element_in_filter_with_index(int index, T &id, W1 &value);

        uint32_t get_number_of_insert_sketch_() {
            return number_of_insert_sketch_;
        }

        ~AugmentedSketch();
    };


}

#include "augmented_sketch_impl.hpp"

#endif