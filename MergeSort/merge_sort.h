#ifndef MERGE_SORT_H_
#define MERGE_SORT_H_

#include <stdlib.h>

void merge_sort(int *array, size_t size);
static void sort(int *array, size_t lo, size_t hi);
static void merge(int *array, size_t lo, size_t mid, size_t hi);

#endif // !MERGE_SORT_H_

