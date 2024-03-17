#ifndef QUICK_SORT_H_
#define QUICK_SORT_H_

#include <stdlib.h>

void quick_sort(int *array, size_t size);
static void sort(int *array, size_t lo, size_t hi);
static int partition(int *array, size_t lo, size_t hi);

#endif // !QUICK_SORT_H_

