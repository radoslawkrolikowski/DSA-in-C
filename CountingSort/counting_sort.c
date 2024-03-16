#include <limits.h>
#include <stdlib.h>
#include <string.h>

void counting_sort(int *array, size_t size) {

    int min_val = INT_MAX;
    int max_val = INT_MIN;

    int temp[size];

    // find min and max values
    for (int i = 0; i < size; i++) {
        if (*(array + i) < min_val) {
            min_val = *(array + i);
        }
        if (*(array + i) > max_val) {
            max_val = *(array + i);
        }
    }

    int counts[max_val - min_val + 1];
    memset(counts, 0, sizeof(counts));

    // count the occurances
    for (int i = 0; i < size; i++) {
        counts[array[i] - min_val]++;
    }

    // calculate cumulative sum
    for (int i = 1; i < max_val - min_val + 1; i++) {
        counts[i] = counts[i-1] + counts[i];
    }

    // write values in sorted order to temp array
    for (int i = 0; i < size; i++) {
        temp[--counts[array[i] - min_val]] = array[i];
    }

    memcpy(array, temp, sizeof(temp));
}
