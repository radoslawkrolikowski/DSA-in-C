#include <stdlib.h>

void selection_sort(int *array, size_t size) {

    for (int i = 0; i < size; i++) {
        int min_idx = i;

        for (int j = i; j < size; j++) {
            if (*(array + j) < *(array + min_idx)) {
                min_idx = j;
            }
        }

        if (min_idx != i) {
            int temp = *(array + i);
            *(array + i) = *(array + min_idx);
            *(array + min_idx) = temp;
        }
    }
}
