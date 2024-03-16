#include "counting_sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int unsorted[] = {4,2,6,1,2,3,4,5,2,1};
    size_t size = 10;

    int sorted[size];

    memcpy(sorted, unsorted, sizeof(unsorted));

    counting_sort(sorted, size);

    printf("--- BEFORE SORTING ---\n");
    for (int i = 0; i < size; i++) {
        printf(" %d", unsorted[i]);
    }

    printf("\n--- AFTER SORTING ---\n");
    for (int i = 0; i < size; i++) {
        printf(" %d", sorted[i]);
    }

    return 0;
}
