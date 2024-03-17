#include <stdlib.h>
#include "merge_sort.h"

void merge_sort(int *array, size_t size) {
    sort(array, 0, size-1);
}

static void sort(int *array, size_t lo, size_t hi) {
    if (lo < hi) {
        size_t mid = lo + (hi - lo) / 2;
        sort(array, lo, mid);
        sort(array, mid+1, hi);
        merge(array, lo, mid, hi);
    }
}

static void merge(int *array, size_t lo, size_t mid, size_t hi) {
    int n1 = mid - lo + 1;
    int n2 = hi - mid;

    int left[n1];
    int right[n2];

    for (int i = 0; i < n1; i++)
        left[i] = array[lo + i];

    for (int i = 0; i < n2; i++)
        right[i] = array[mid + 1 + i];

    int i = 0;
    int j = 0;
    int k = lo;

    while(i < n1 && j < n2) {
        if (left[i] < right[j])
            array[k++] = left[i++];
        else
            array[k++] = right[j++];
    }

    while(i < n1)
        array[k++] = left[i++];

    while(j < n2)
        array[k++] = right[j++];
}
