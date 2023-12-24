#ifndef COUNT_SKETCH_IMPL_HPP_
#define COUNT_SKETCH_IMPL_HPP_


#define COUNT_BY_MEDIA_COUNTSKETCH


#ifdef COUNT_BY_MEDIA_COUNTSKETCH
#ifdef COUNT_BY_MEAN_COUNTSKETCH
#error
#endif
#endif


# include <iostream>
# include <cmath>
# include <cstdlib>
# include <ctime>
# include <limits>
# include "cstring"
#include <algorithm>
# include <vector>

namespace datasketches {

    template<class T, class W, class A>
    inline void count_sketch<T, W, A>::initializer(uint32_t dep, uint32_t wid, uint32_t seed) {
        uint i = 0;
        table = new W *[dep];
        for (uint32_t j = 0; j < dep; j++) {
            table[j] = new W[wid]();
        }

        hash = new uint32_t[dep];
        mapseeds = new uint32_t[dep];

        while (i < dep) {
            hash[i++] = (uint32_t) rand();
            mapseeds[i++] = (uint32_t) rand();
        }
        _tableExist = true;
    }


    template<class T, class W, class A>
    count_sketch<T, W, A>::count_sketch(uint32_t depth_, uint32_t width_, uint32_t seed_) {
        depth = depth_;
        width = width_;

        eps = 2.0 / width_;
        confidence = 1 - 1 / pow(2, depth_);

        total = 0;
        initializer(depth_, width_, seed_);

    }


    template<class T, class W, class A>
    count_sketch<T, W, A>::count_sketch(int depth_, int width_, int seed_) {
        depth = depth_;
        width = width_;

        eps = 2.0 / width_;
        confidence = 1 - 1 / pow(2, depth_);

        total = 0;
        initializer(depth_, width_, seed_);

    }


    template<class T, class W, class A>
    count_sketch<T, W, A>::count_sketch(double eps_, double confidence_, uint32_t seed_) {

        eps = eps_;
        confidence = confidence_;

        width = (uint32_t) ceil(2 / eps_);
        depth = (uint32_t) ceil(-log(1 - confidence_) / log(2));

        total = 0;
        initializer(depth, width, seed_);
    }


    template<class T, class W, class A>
    count_sketch<T, W, A>::count_sketch(uint32_t depth_, uint32_t width_, double total_, uint32_t *hashA,
                                        uint32_t *mapseedsA, W **tableA) {
        depth = depth_;
        width = width_;
        eps = 2.0 / width_;
        confidence = 1 - 1 / pow(2, depth_);
        total = total_;


        table = new W *[depth_];

        for (uint32_t i = 0; i < depth_; i++) {
            table[i] = new W[width_];
            for (uint32_t j = 0; j < width_; j++) {
                table[i][j] = tableA[i][j];
            }
        }

        hash = new uint32_t[depth_];
        mapseeds = new uint32_t[depth_];

        for (uint32_t i = 0; i < depth_; i++) {
            hash[i] = hashA[i];
            mapseeds[i] = mapseedsA[i];
        }
        _tableExist = true;

    }

    template<class T, class W, class A>
    count_sketch<T, W, A>::count_sketch(const count_sketch <T, W, A> &st) {
        width = st.width;
        depth = st.depth;
        eps = 2.0 / width;
        confidence = 1 - 1 / pow(2, depth);
        total = st.total;


        W **tableA = st.table;

        table = new W *[depth];


        for (uint32_t i = 0; i < depth; i++) {
            table[i] = new W[width];
            for (uint32_t j = 0; j < width; j++) {
                table[i][j] = tableA[i][j];
            }
        }

        tableA = 0;

        uint32_t *hashA = st.hash;
        uint32_t *mapseedsA = st.mapseeds;
        hash = new uint32_t[depth];
        mapseeds = new uint32_t[depth];

        for (uint32_t i = 0; i < depth; i++) {
            hash[i] = hashA[i];
            mapseeds[i] = mapseedsA[i];
        }

        hashA = 0;
        mapseedsA = 0;

    }


    template<class T, class W, class A>
    count_sketch<T, W, A>::~count_sketch() {

        for (uint32_t i = 0; i < depth; i++) {
            delete[] table[i];
        }
        delete[] table;
        delete[] hash;
        delete[] mapseeds;
    }

    template<class T, class W, class A>
    count_sketch <T, W, A> &count_sketch<T, W, A>::operator=(const count_sketch <T, W, A> &st) {

        if (this == &st)
            return *this;

        width = st.width;
        depth = st.depth;
        eps = 2.0 / width;
        confidence = 1 - 1 / pow(2, depth);
        total = st.total;


        if (_tableExist) {

            for (uint32_t i = 0; i < depth; i++) {
                delete[] table[i];
            }
            delete[] table;
            delete[] hash;
            delete[] mapseeds;
        }


        W **tableA = st.table;
        table = new W *[depth];

        for (uint32_t i = 0; i < depth; i++) {
            table[i] = new W[width];
            for (uint32_t j = 0; j < width; j++) {
                table[i][j] = tableA[i][j];
            }
        }

        tableA = 0;

        uint32_t *hashA = st.hash;
        uint32_t *mapseedsA = st.mapseeds;
        hash = new uint32_t[depth];
        mapseeds = new uint32_t[depth];

        for (uint32_t i = 0; i < depth; i++) {
            hash[i] = hashA[i];
            mapseeds[i] = mapseedsA[i];
        }

        hashA = 0;
        mapseedsA = 0;

        return *this;
    }


    template<class T, class W, class A>
    W count_sketch<T, W, A>::update(const T &item, const A c) {


        total = total + c;
#ifdef COUNT_BY_MEDIA_COUNTSKETCH
        W medianval;
        W arr[depth];
#endif

#ifdef COUNT_BY_MEAN_COUNTSKETCH
        W meanval;
        meanval = 0;
#endif


        int hashval_arr[depth];
        int mapval_arr[depth];
        for (uint32_t i = 0; i < depth; i++) {
            hashval_arr[i] = XXH32(&item, sizeof(item), *(hash + i)) % width;
            mapval_arr[i] = XXH32(&item, sizeof(item), *(mapseeds + i)) % 2;
        }
        for (uint32_t i = 0; i < depth; i++) {
            int hashval = hashval_arr[i];
            int mapval = mapval_arr[i];


            table[i][hashval] += (2 * mapval - 1) * c;

#ifdef COUNT_BY_MEDIA_COUNTSKETCH
            arr[i] = table[i][hashval] * (2 * mapval - 1);
#endif
#ifdef COUNT_BY_MEAN_COUNTSKETCH
            meanval = meanval +  tval * (2*mapval-1);

#endif
        }

#ifdef COUNT_BY_MEDIA_COUNTSKETCH
        if ((depth % 2) == 0) {

            sort(arr, arr + depth);
            medianval = get_value_to_int32t(arr[depth / 2] + arr[(depth / 2) - 1]) / 2.0;
        } else {

            std::nth_element(arr, arr + depth / 2, arr + depth);
            medianval = arr[(depth / 2)];
        }
        return medianval;
#endif


#ifdef COUNT_BY_MEAN_COUNTSKETCH




        W tmpG;
        tmpG = get_value_to_int32t(meanval)/ depth;
      return tmpG;


#endif
    }

    template<class T, class W, class A>
    W count_sketch<T, W, A>::update(T &&item, const A c) {


        total = total + c;
        cout << "over" << endl;
        W medianval = 0;
        W meanval = 0;
        W val;


        int hashval_arr[depth];
        int mapval_arr[depth];
        int values[depth];
        for (uint32_t i = 0; i < depth; i++) {
            hashval_arr[i] = XXH32(&item, sizeof(item), *(hash + i)) % width;
            mapval_arr[i] = XXH32(&item, sizeof(item), *(mapseeds + i)) % 2;
        }
        for (uint32_t i = 0; i < depth; i++) {
            int hashval = hashval_arr[i];
            int mapval = mapval_arr[i];
            W tval = table[i][hashval] + (2 * mapval - 1) * c;
            table[i][hashval] = tval;


            values[i] = (mapval * 2 - 1) * tval;

        }
        sort(values.begin(), values.end());
        if ((depth % 2) == 0)
            medianval = 0.5 * (values[depth / 2] + values[(depth / 2) + 1]);
        else
            medianval = values[(depth / 2)];

        return medianval;


    }


    template<class T, class W, class A>
    W count_sketch<T, W, A>::update_with_asketch(const T &item, const A c) {
        total = total + c;
        W minval;
        minval = 0;

        for (uint32_t i = 0; i < depth; i++) {
            int hashval = XXH32(&item, sizeof(item), *(hash + i)) % width;
            int mapval = XXH32(&item, sizeof(item), *(mapseeds + i)) % 2;


            if (table[i][hashval] * (2 * mapval - 1) < c * (2 * mapval - 1)) {

                table[i][hashval] = (2 * mapval - 1) * c;
            }
            if (i == 0) {
                minval = table[i][hashval];
            } else {

                if (table[i][hashval] < minval)
                    minval = table[i][hashval];
            }

        }
        return minval;

    }


    template<class T, class W, class A>
    W count_sketch<T, W, A>::estimate(const T &item) {


        if (depth == 0) {
            return (W) -1;
        }

        W medianval;
        W meanval = (W) 0;
        W val;
        int hashval_arr[depth];
        int mapval_arr[depth];


        vector <W> values;
        for (uint32_t i = 0; i < depth; i++) {
            hashval_arr[i] = XXH32(&item, sizeof(item), *(hash + i)) % width;
            mapval_arr[i] = XXH32(&item, sizeof(item), *(mapseeds + i)) % 2;
        }
        W tmp;
        for (uint32_t i = 0; i < depth; i++) {
            int hashval = hashval_arr[i];
            int mapval = mapval_arr[i];


            tmp = table[i][hashval] * (mapval * 2 - 1);

            values.push_back(tmp);

        }
        auto iter = values.end();
        std::nth_element(values.begin(), values.begin() + depth / 2, values.end());

        return values.at(depth / 2);


        return medianval;

    }


    template<class T, class W, class A>
    int32_t count_sketch<T, W, A>::estimate_to_int(const T &item) {


        if (depth == 0) {
            return -1;
        }
#ifdef COUNT_BY_MEDIA_COUNTSKETCH
        int32_t medianval;
        int arr[depth];
#endif
#ifdef COUNT_BY_MEAN_COUNTSKETCH
        int sum = 0;
#endif
        int hashVal;
        int mapVal;
        int tmpVal;

        for (uint32_t i = 0; i < depth; i++) {
            hashVal = XXH32(&item, sizeof(item), *(hash + i)) % width;
            mapVal = XXH32(&item, sizeof(item), *(mapseeds + i)) % 2;
            tmpVal = get_value_to_int32t(table[i][hashVal]) * (mapVal * 2 - 1);

#ifdef COUNT_BY_MEDIA_COUNTSKETCH
            arr[i] = tmpVal;
#endif
#ifdef COUNT_BY_MEAN_COUNTSKETCH
            sum += tmpVal;

#endif
        }


#ifdef COUNT_BY_MEDIA_COUNTSKETCH

        if ((depth % 2) == 0) {

            sort(arr, arr + depth);
            medianval = get_value_to_int32t(arr[depth / 2] + arr[(depth / 2) - 1]) / 2.0;
        } else {

            std::nth_element(arr, arr + depth / 2, arr + depth);
            medianval = arr[(depth / 2)];
        }
        return medianval;
#endif

#ifdef COUNT_BY_MEAN_COUNTSKETCH
        return sum / depth;


#endif
    }


    template<class T, class W, class A>
    void count_sketch<T, W, A>::print_sketch() {
        for (uint i = 0; i != depth; i++) {
            for (uint j = 0; j != width; j++) {
                std::cout << table[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    template<class T, class W, class A>
    double count_sketch<T, W, A>::decode_sketch(FlowRecordList <T, uint32_t> &flowrecordlist, int top_k) {
        uint32_t true_value;
        uint32_t uint_true_value;
        T true_key;
        W query_value;

        int32_t uint_query_value;


        double r_error = 0.0;
        double are = 0.0;

        double t;

        for (auto it = flowrecordlist.sorted_vecotr_.begin();
             it != flowrecordlist.sorted_vecotr_.begin() + top_k; it++) {
            true_key = it->first;
            true_value = it->second;
            query_value = estimate(true_key);
            uint_true_value = true_value;
            uint_query_value = get_value_to_int32t(query_value);
            if (uint_true_value >= uint_query_value) {
                t = ((double) (uint_true_value - uint_query_value) / (double) uint_true_value);
                r_error = r_error + t;
            } else {
                t = ((double) (uint_query_value - uint_true_value) / (double) uint_true_value);
                r_error = r_error + t;
            }
        }
        are = r_error / top_k;
        return are;
    }

    template<class T, class W, class A>
    double count_sketch<T, W, A>::identify_rate(FlowRecordList <T, uint32_t> &flowrecordlist, int top_k) {
        uint32_t true_value;
        uint32_t uint_true_value;
        T true_key;
        W query_value;
        uint32_t uint_query_value;


        double r_error = 0.0;
        double are = 0.0;

        double t;

        uint32_t topk_value = flowrecordlist.sorted_vecotr_[top_k].second;

        int identify_nums = 0;

        int times = 0;

        int TF = 0;

        for (auto it = flowrecordlist.sorted_vecotr_.begin(); it != flowrecordlist.sorted_vecotr_.end(); it++) {
            times++;
            true_key = it->first;
            query_value = estimate(true_key);


            if (query_value >= int(topk_value)) {
                identify_nums++;
                if (times <= top_k) {
                    TF++;
                }
            }


        }
        return TF * 1.0 / identify_nums;
    }


    template<class T, class W, class A>
    double count_sketch<T, W, A>::decode_sketch(FlowRecordList <T, uint32_t> &flowrecordlist,
                                                datasketches::EstimateTotalCountList &estimatelist) {
        int true_value;
        T true_key;
        W query_value;
        int uint_query_value;


        double r_error = 0.0;
        double mre;

        double t;

        for (auto it = flowrecordlist.flow_map_.begin(); it != flowrecordlist.flow_map_.end(); it++) {
            true_key = it->first;
            true_value = it->second;
            query_value = estimate(true_key);

            estimatelist.insert(true_value, query_value);
        }
        return 0;
    }

    template<class T, class W, class A>
    bool cm_intersection(count_sketch <T, W, A> &cm1, count_sketch <T, W, A> &cm2, count_sketch <T, W, A> &cm_output) {
        if (cm1.width != cm2.width || cm1.depth != cm2.depth)
            return false;
        else {
            cm_output = cm1;
            for (int i = 0; i != cm1.depth; i++) {
                for (int j = 0; j != cm2.width; j++) {
                    cm_output.table[i][j] = MAX(cm1.table[i][j], cm2.table[i][j]);
                }
            }
            return true;
        }

    }

}


#endif

