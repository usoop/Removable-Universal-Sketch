#ifndef BASE_SKETCH_H_
#define BASE_SKETCH_H_

#include <cstdint>

namespace datasketches {


    template<class T, class W, class A>
    class BaseSketch {
    public:


        virtual W update(const T &item, A weight) = 0;


        virtual W update_with_asketch(const T &item, A weight) = 0;


        virtual void reset() = 0;


        virtual double totalcount() = 0;


        virtual W estimate(const T &item) = 0;


        virtual void print_sketch() = 0;

        virtual double decode_sketch(FlowRecordList <T, uint32_t> &flowrecordlist, int top_k) = 0;

        virtual double identify_rate(FlowRecordList <T, uint32_t> &flowrecordlist, int top_k) = 0;

        virtual ~BaseSketch() = 0;

    };

    template<class T, class W, class A>
    BaseSketch<T, W, A>::~BaseSketch() {
    }

}
#endif
