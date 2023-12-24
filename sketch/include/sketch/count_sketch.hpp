#ifndef COUNT_SKETCH_HPP_
#define COUNT_SKETCH_HPP_


#include <memory>
#include <vector>
#include <iostream>
#include <functional>
#include <type_traits>

#include "base_sketch.hpp"

namespace datasketches {

#define MIN(a, b) a<b?a:b

#define MAX(a, b) a>b?a:b

    template<class T, class W, class A>
    class count_sketch;


    template<class T, class W, class A>
    bool cm_intersection(count_sketch<T, W, A> &cm1, count_sketch<T, W, A> &cm2, count_sketch<T, W, A> &cm_put);


    template<class T, class W, class A>
    class count_sketch : public BaseSketch<T, W, A> {
    private:


        uint32_t width, depth;


        double eps;


        double confidence;


        double total;


        W **table;


        uint32_t *hash;


        uint32_t *mapseeds;

        bool _tableExist = false;

        inline void initializer(uint32_t dep, uint32_t wid, uint32_t seed);


    public:

        count_sketch() = default;

        explicit count_sketch(int depth_, int width_, int seed_);

        explicit count_sketch(uint32_t depth_, uint32_t width_, uint32_t seed_);

        explicit count_sketch(double eps_, double confidence_, uint32_t seed_);

        explicit count_sketch(uint32_t depth_, uint32_t width_, double total_, uint32_t *hash_, uint32_t *mapseedsA,
                              W **table_);


        W update(const T &item, A weight);

        W update(T &&item, A weight);


        W update_with_asketch(const T &item, A weight);

        W update_with_asketch_bak(const T &item, A weight);


        uint32_t get_width() {
            return width;
        }

        uint32_t get_depth() {
            return depth;
        }

        double getRelativeError() {
            return eps;
        }

        double getConfidence() {
            return confidence;
        }

        uint32_t *get_hash() {
            return hash;
        }

        void reset() {
            for (uint32_t i = 0; i < depth; i++) {
                for (uint32_t j = 0; j < width; j++) {
                    table[i][j] = 0;
                }
            }


            uint i = 0;

            while (i < depth) {
                hash[i++] = (uint32_t) rand();
            }
            total = 0;
        }

        W **get_table() {
            return table;
        }

        void print_sketch();


        double totalcount() {
            return total;
        }


        count_sketch<T, W, A> &operator=(const count_sketch<T, W, A> &st);


        W estimate(const T &item);

        int32_t estimate_to_int(const T &item);

        int32_t query(const T &item) {
            return estimate_to_int(item);
        }


        count_sketch(const count_sketch<T, W, A> &s);


        double identify_rate(FlowRecordList <T, uint32_t> &flowrecordlist, int top_k);

        double decode_sketch(FlowRecordList <T, uint32_t> &flowrecordlist, int top_k);

        double
        decode_sketch(FlowRecordList <T, uint32_t> &flowrecordlist, datasketches::EstimateTotalCountList &estimatelist);


        ~count_sketch();

        friend bool
        cm_intersection<>(count_sketch<T, W, A> &cm1, count_sketch<T, W, A> &cm2, count_sketch<T, W, A> &cm_put);
    };

}

#include "count_sketch_impl.hpp"

#endif