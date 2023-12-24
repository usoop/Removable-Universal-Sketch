


#ifndef CUCKOO_PREFILTER_GLOBAL_VAR_HPP
#define CUCKOO_PREFILTER_GLOBAL_VAR_HPP

#include <stdint.h>
#include <cmath>

uint32_t tail = 0;
constexpr double decay_factor = 1.02;
constexpr double decay_ctrl_factor = 300;


namespace cuckoofilter {


    constexpr size_t kMaxCuckooCount = 10;

    constexpr size_t kTagsPerBucket = 4;

}

#endif
