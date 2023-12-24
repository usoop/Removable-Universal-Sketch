#ifndef UTILS_ACTIVE_COUNTER_HPP_
#define UTILS_ACTIVE_COUNTER_HPP_

# include <iostream>
# include <cmath>
# include <cstdlib>
# include <ctime>
#include <immintrin.h>

namespace datasketches {


    int get_length_of_AVX(unsigned int n) {
        n = n + 1;
        uint32_t arr[] = {65535, 32768, 16384, 8192, 4096, 2048, 1024, 512};
        const __m256i __m_n = _mm256_set1_epi32(n);
        __m256i *__m_arr = (__m256i *) arr;
        __m256i a_part = _mm256_loadu_si256((__m256i *) &__m_arr[0]);
        __m256i f_comp = _mm256_cmpgt_epi32(__m_n, a_part);
        int found = _mm256_movemask_epi8(f_comp);
        int a = 17 - __builtin_ctz(found) / 4;
        return a;
    }


    int get_length_of_32_AVX(unsigned int n) {
        n = n + 1;

        uint32_t arr[] = {256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65535, 131072, 262144, 524288, 1048576,
                          2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912,
                          1073741824, 2147483648};
        const __m256i __m_n = _mm256_set1_epi32(n);
        __m256i *__m_arr = (__m256i *) arr;
        for (int i = 0; i != 3; i++) {
            __m256i a_part = _mm256_loadu_si256((__m256i *) &__m_arr[i]);
            __m256i f_comp = _mm256_cmpgt_epi32(a_part, __m_n);
            int found = _mm256_movemask_epi8(f_comp);

            if (found)
                return (8 + i * 8 + __builtin_ctz(found) / 4);
        }
        return 32;
    }

    int get_length_of_clz(unsigned int n) {


        return 32 - __builtin_clz(n);


    }

}


#endif