#include <stdlib.h>
#include "quick_sort.h"

void quick_sort(int *array, size_t size) {
    sort(array, 0, size-1);
}

static void sort(int *array, size_t lo, size_t hi) {
    if (lo < hi) {
        int pivot = partition(array, lo, hi);
        sort(array, lo, pivot-1);
        sort(array, pivot+1, hi);
    }
}

static int partition(int *array, size_t lo, size_t hi) {
    int pivot = array[lo];

    int i = lo;
    int j = hi;

    while (i < j) {
        while (array[i] <= pivot && i <= hi-1) i++;
        while (array[j] >= pivot && j >= lo+1) j--;

        if (i < j) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    int temp = array[lo];
    array[lo] = array[j];
    array[j] = temp;

    return j;
}
