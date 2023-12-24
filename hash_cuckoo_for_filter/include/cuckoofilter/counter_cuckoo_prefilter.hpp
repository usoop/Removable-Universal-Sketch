


#ifndef CUCKOO_PREFILTER_CUCKOO_PREFILTER_COUNTER_H
#define CUCKOO_PREFILTER_CUCKOO_PREFILTER_COUNTER_H

#include <cstdint>
#include "global_var.hpp"

namespace cuckoofilter {


    class Counter {
    public:
        Counter()
                : tag_idx(kTagsPerBucket),
                  new_freq(0),
                  old_freq(0) {}

        ~Counter() = default;

        uint16_t tag_idx;
        int32_t new_freq;
        int32_t old_freq;
    };

}

#include "counter_cuckoo_prefilter_impl.hpp"

#endif
