#include <stdio.h>

void insertion_sort(int *array, size_t size) {

    for (int i = 1; i < size; i++) {
        int prev = i - 1;
        int key = *(array + i);

        while (prev >= 0 && *(array + prev) > key) {
            *(array + prev + 1) = *(array + prev); // shift to the right
            prev--;
        }

        *(array + prev + 1) = key;
    }
}
