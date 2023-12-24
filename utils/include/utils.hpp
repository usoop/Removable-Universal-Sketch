#ifndef UTILS_H_
#define UTILS_H_

#include <cstdint>
#include <immintrin.h>
#include <cmath>
#include "xxhash.h"


namespace datasketches {


    inline int32_t get_value_to_int32t(int n) {
        return n;
    }

    inline int32_t get_value_to_int32t(GenericCounterTurnstile n) {
        return n.compute_the_value_of_active_counter_stochastic();
    }


    inline uint32_t get_value_to_uint32t(int n) {
        if (n > 2147483647)
            throw n;
        else if (n < 0) {
            n = 0;
        }
        return (uint32_t) n;
    }

    inline uint32_t get_value_to_uint32t(GenericCounterTurnstile n) {
        int t = n.compute_the_value_of_active_counter_stochastic();
        if (t > 2147483647)
            throw t;
        else if (t < 0) {
            t = 0;
        }
        return (uint32_t) t;
    }

    inline uint32_t get_value_to_uint32t(uint32_t n) {
        return n;
    }


    inline uint32_t get_longest_len_of_series_one(uint32_t a, uint32_t max_len) {
        uint32_t mask = 1;
        for (uint32_t i = 0; i != max_len; i++) {
            if ((a & mask) != 0) {
                mask = mask << 1;
            } else {
                return i;
            }
        }
        return max_len;
    }


    inline uint32_t get_longest_len_of_series_one(uint32_t a) {
        for (int i = 20; i != 0; i--) {
            if ((a % uint32_t(std::pow(2, i))) == (std::pow(2, i) - 1))
                return i;
        }
        return 0;

    }


    uint32_t XXH_H32(const void *input, size_t length, uint32_t seed) {
        return XXH32(input, length, seed);
    }

    void XXH_H32_RESET(uint32_t seed) {
        XXH32_state_t *const state = XXH32_createState();
        XXH32_reset(state, seed);
    }


    long double x_one_moment(int32_t x) {
        return x;
    }

    long double x_zero_moment(int32_t x) {
        if (x != 0) {
            return 1;
        } else {
            return 0;
        }
    }

    long double x_three_moment(int32_t x) {
        return std::pow(x, 3);
    }

    long double x_four_moment(int32_t x) {
        return (x < 0 ? -1 : 1) * std::pow(x, 4);
    }

    long double x_two_moment(int32_t x) {
        return (x < 0 ? -1 : 1) * std::pow(x, 2);
    }

    long double x_xlogx_moment(int32_t x) {
        if (x != 0) {
            return x * std::log(fabs(x));

        } else {
            return 0;
        }
    }


    template<class T>
    T set_sample_top_bit(T id) {
        int bit_len = sizeof(T) * 8;
        T b = pow(2, bit_len - 1);
        id = id | b;
        return id;
    }

    template<class T>
    T unset_sample_top_bit(T id) {
        int bit_len = sizeof(T) * 8;
        T b = pow(2, bit_len - 1);
        b = b - 1;
        id = id & b;
        return id;
    }

    template<class T>
    bool get_sample_top_bit(T id) {
        int bit_len = sizeof(T) * 8;
        T b = pow(2, bit_len - 1);
        id = id & b;
        if (id == b)
            return true;
        else
            return false;

    }

    template<class T>
    T set_sample_bottom_bit(T id) {
        int bit_len = sizeof(T) * 8;
        T b = pow(2, bit_len - 2);
        id = id | b;
        return id;
    }

    template<class T>
    bool get_sample_bottom_bit(T id) {
        int bit_len = sizeof(T) * 8;
        T b = pow(2, bit_len - 2);
        id = id & b;
        if (id == b)
            return true;
        else
            return false;

    }

    template<class T>
    T unset_sample_bottom_bit(T id) {
        int bit_len = sizeof(T) * 8;
        T b = pow(2, bit_len - 2) + pow(2, bit_len - 1);
        b = b - 1;
        id = id & b;
        return id;
    }


    template<class T>
    T get_raw_id(T id) {
        int bit_len = sizeof(T) * 8;
        T b = pow(2, bit_len - 2);
        b = b - 1;
        id = id & b;
        return id;
    }


    template<class W>
    int check_membership_SSE2(W *filter_id, W item, int length) {
        const __m128i s_item = _mm_set1_epi32(item);
        __m128i *filter = (__m128i *) filter_id;
        int batch_size = sizeof(__m128i) / sizeof(W);
        int batch_num = length / batch_size;


        for (int i = 0; i != batch_num; i++) {
            __m128i f_comp = _mm_cmpeq_epi32(s_item, filter[i]);
            int found = _mm_movemask_epi8(f_comp);
            if (found)
                return (i * batch_size + __builtin_ctz(found) / 4);
        }
        return -1;

    }

    template<class W>
    int check_membership_AVX(W *filter_id, W item, int length) {
        const __m256i s_item = _mm256_set1_epi32(item);
        __m256i *filter = (__m256i *) filter_id;
        int batch_size = sizeof(__m256i) / sizeof(uint32_t);
        int batch_num = (length - 1) / batch_size + 1;


        for (int i = 0; i != batch_num; i++) {
            __m256i a_part = _mm256_loadu_si256((__m256i *) &filter[i]);
            __m256i f_comp = _mm256_cmpeq_epi32(s_item, a_part);
            uint found = _mm256_movemask_epi8(f_comp);
            if (found) {
                int index = i * batch_size + __builtin_ctz(found) / 4;
                if (index < length) {

                    return index;
                } else {
                    return -1;
                }
            }
        }
        return -1;

    }


}
#endif
