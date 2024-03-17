#include "quick_sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int unsorted[] = {8,3,7,4,6,10,1,5,2,9};
    size_t size = 10;

    int sorted[size];

    memcpy(sorted, unsorted, sizeof(unsorted));

    quick_sort(sorted, size);

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
