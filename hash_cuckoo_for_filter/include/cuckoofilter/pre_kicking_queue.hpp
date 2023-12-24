#ifndef CUCKOO_FILTER_PRE_KICKING_QUEUE_H_
#define CUCKOO_FILTER_PRE_KICKING_QUEUE_H_

#include <cstddef>
#include <cstdint>
#include <vector>
#include "assert.h"
#include "counter_cuckoo_prefilter.hpp"

namespace cuckoofilter {

    class PreKickingQueue {
    public:
        explicit PreKickingQueue(const size_t length)
                : maxlen(length),
                  curlen(0),
                  queue(length, 0) {
            queue.shrink_to_fit();
        }

        inline void Enqueue(const size_t bkt_idx) {


            assert(curlen != maxlen);
            if (curlen < maxlen) {
                queue[curlen] = bkt_idx;
                curlen++;
            }
        }


        inline size_t GetItemByIndex(const size_t index) const {

            return queue[index];
        }


        inline void Clear() {
            curlen = 0;
        }

        void reset() {
            curlen = 0;
            queue.clear();
        }

        inline size_t GetSize() const { return curlen; }


    private:
        size_t maxlen;
        size_t curlen;
        ::std::vector<size_t> queue;
    };

}

#endif
