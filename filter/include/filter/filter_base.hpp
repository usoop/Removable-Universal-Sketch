#ifndef FILTER_BASE_H_
#define FILTER_BASE_H_

#include <cstdint>

namespace datasketches {

    template<class T, class W, class A>
    class BaseFilter {
    public:
        virtual void reset() = 0;

        virtual void print_filter() = 0;


        virtual bool has_old() = 0;

        virtual ~BaseFilter() = 0;


        virtual bool isFull() = 0;


        virtual int check_membership(const T &new_id) = 0;


        virtual int get_filter_size() = 0;


        virtual void replace_min_element(T new_id, W new_count) = 0;

        virtual void replace_min_element(T new_id, W new_count, W old_count) {};


        virtual void get_element_with_index(int index, T &out_id, W &out_value) = 0;


        virtual void top(T &out_id, W &new_value, W &old_value) = 0;


        virtual W update_existing_element_with_index(int index, A increment_value) = 0;

        virtual T get_key_with_index(int index) = 0;

        virtual W get_value_with_index(int index) = 0;

        virtual void set_value_with_index(int index, W new_size) = 0;

        virtual void set_uint32_value_with_index(int index, uint32_t new_size) = 0;


        virtual void replace_element_with_index(T new_id, A new_count, int index) = 0;


        virtual bool insert_in_filter(T new_id, A new_count = 1) = 0;


        virtual bool insert_in_post_filter(T new_id, A new_estimate_count) = 0;

        virtual bool insert_in_filter_with_lus(T new_id, A new_estimate_count, bool &is_kick, T &kicked_element_id,
                                               W &kicked_element_value) = 0;


        virtual W
        insert_in_filter_with_sketch(bool &is_insert, bool &is_heavy, T &min_element_id, W &min_element_value, T new_id,
                                     A new_count = 1) = 0;


    };

    template<class T, class W, class A>
    BaseFilter<T, W, A>::~BaseFilter() {
    }


}
#endif
