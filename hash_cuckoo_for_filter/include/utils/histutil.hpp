


#ifndef CUCKOO_PREFILTER_HISTUTIL_HPP
#define CUCKOO_PREFILTER_HISTUTIL_HPP

#include "vector"
#include <cstdint>
#include <iostream>

using namespace std;

struct HISTOGRAM {
    vector<uint32_t> bars;
    uint16_t min_bar_index;
    uint16_t totalLength;

    void init_hist(int totalLen);

    void insert_hist(int32_t value);

    void delete_hist(HISTOGRAM &histogram, int32_t value);

    void delete_hist(int32_t value);

    void print_hist();
};


inline int ilog2_kf(int n) {
    return std::__lg(n);
}


void HISTOGRAM::init_hist(int totalLen) {
    bars.clear();
    bars.reserve(totalLen);
    totalLength = totalLen;
    for (int i = 0; i < totalLen; i++) {
        bars.emplace_back(0);
    }
    min_bar_index = 100;
}


void HISTOGRAM::insert_hist(int32_t value) {
    int index = ilog2_kf(value);
    bars[index] += 1;
    if (index < min_bar_index) {
        min_bar_index = index;
    }
}


void HISTOGRAM::delete_hist(int32_t value) {
    int index = ilog2_kf(value);
    bars[index] -= 1;
    if (bars[index] == 0) {
        for (int i = index + 1; i < totalLength; i++) {
            if (bars[i] != 0) {
                min_bar_index = i;
            }
        }
    }
}


void HISTOGRAM::print_hist() {
    int min_index = min_bar_index;
    int totalLen = totalLength;
    cout << "min_index:" << min_index << endl;
    cout << "totalLen:" << totalLen << endl;
    vector<uint32_t> vec = bars;
    for (int i = 0; i < vec.size(); i++) {
        uint32_t range_start = 1 << i;
        uint32_t range_end = 1 << (i + 1);
        cout << "range from [2^" << i << "=" << range_start << " to 2^" << i + 1 << "=" << range_end << ")"
             << "\t\t\t:::";
        cout << "value:" << vec[i] << endl;
    }
}


#endif
