


#ifndef MOMENT_ESTIMATION_LUS_SKETCH_WITH_CUCKOO_PREFILTER_HPP
#define MOMENT_ESTIMATION_LUS_SKETCH_WITH_CUCKOO_PREFILTER_HPP

namespace datasketches {

    template<class T, class W1, class W2, class F, class S>
    class LusCuckooSketch {

    private:

        datasketches::CuckooHeavyHitterFilter<T, W1, int32_t> **ptr_filter_;


        datasketches::BaseSketch<T, W2, int32_t> **ptr_sketch_;


        double memory_access;

        double hash_access;
        int *ptr_levelTotalNum_;

        double cache_miss_one;

        double cache_miss_two;

        uint32_t level_;

        uint32_t seed_;

        int filter_size_;

        uint32_t sketch_depth_;

        uint32_t sketch_width_;

        int mem_size_;

        double epsilon_;


    public:
        long double value_sum;

        long double online_one_moment;
        long double online_zero_moment;
        long double online_two_moment;
        long double online_three_moment;
        long double online_four_moment;
        long double online_xlogx_moment;

        LusCuckooSketch() = default;

        LusCuckooSketch(const LusCuckooSketch &that);

        LusCuckooSketch(int level, int filter_size, int sketch_depth, int sketch_width, int sketch_seed);

        LusCuckooSketch(int level, int filter_size, int sketch_depth, int sketch_seed,
                        vector <int32_t> init_sketch_widths);

        LusCuckooSketch(int level, int filter_size, int sketch_depth, int sketch_seed,
                        vector <int32_t> init_sketch_widths,
                        vector <int32_t> init_filter_widths);

        LusCuckooSketch(int level, int filter_size, int sketch_depth, int sketch_width, int sketch_seed,
                        double epsilon);

        LusCuckooSketch &operator=(const LusCuckooSketch &st);

        uint32_t estimate_flow_size_at_level_k(T new_id, uint32_t new_count, int k);

        int sample_to_level(T new_id);

        long double get_totalcount();

        W2 estimate_flow_size_by_sketch_at_level_k(T new_id, uint32_t new_count, int k);


        void update(T new_id, int32_t new_count) {
            update_lus(new_id, new_count);
        };

        void update_lus(T new_id, int32_t new_count);

        void update_lus_with_online_query(T new_id, int32_t new_count);

        void print_filter();

        bool checkmembership_in_filter_at_level_k(const T &new_id, int k);

        long double compute_one_moment();

        long double compute_one_moment_by_eps();

        long double compute_one_moment2();

        long double compute_two_moment();

        long double compute_two_moment_by_eps();

        long double compute_three_moment();

        long double compute_three_moment_by_eps();

        long double compute_four_moment();

        long double compute_four_moment_by_eps();

        long double compute_zero_moment();

        long double compute_zero_moment_by_eps();

        long double compute_xlogx_moment();

        long double compute_xlogx_moment_by_eps();

        long double compute_moment2(long double(*f)(uint32_t x));

        long double compute_moment(long double(*f)(int32_t x));

        long double compute_moment_by_eps(long double(*f)(uint32_t x));

        void reset();

        void get_hhs(vector <std::pair<T, W1>> &vec);

        void get_hhs(vector <std::pair<T, uint32_t>> &vec);

        std::string get_class_name();

        int get_mem_size();

        double get_mem_access() {
            return memory_access;
        }

        double get_cache_miss_one() {
            return cache_miss_one;
        }

        double get_cache_miss_two() {
            return cache_miss_two;
        }

        double get_hash_access() {
            return hash_access;
        }

        ~LusCuckooSketch();

        uint32_t estimate_flow_size_at_level_k_by_cuckoo(T new_id, uint32_t new_count, int k);
    };

}

#include "lus_sketch_with_cuckoo_prefilter_impl.hpp"

#endif