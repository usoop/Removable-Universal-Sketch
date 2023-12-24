#ifndef SKETCH_UTILS_HPP_
#define SKETCH_UTILS_HPP_

#include <iostream>
#include <cstdint>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <stdint.h>
#include <cstring>


template<class W>
void swap(W arr[], int index_i, int index_j) {
    int k = arr[index_i];
    arr[index_i] = arr[index_j];
    arr[index_j] = k;
}

template<class W>
int partition_Rowe(W arr[], int low, int high) {


    int pivot = arr[low];
    int low_index = low;
    for (int i = low + 1; i <= high; i++) {
        if (arr[i] < pivot) {

            low_index++;
            if (i != low_index) {
                swap<W>(arr, i, low_index);
            }
        }
    }

    arr[low] = arr[low_index];
    arr[low_index] = pivot;
    return low_index;
}

template<class W>
void quick_sort(W arr[], int low, int high) {
    if (high > low) {
        int pivot_pos = partition_Rowe<W>(arr, low, high);
        quick_sort<W>(arr, low, pivot_pos - 1);
        quick_sort<W>(arr, pivot_pos + 1, high);
    }
}


#endif