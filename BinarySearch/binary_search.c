#include "binary_search.h"
#include <stdlib.h>
#include <stdio.h>

#define IMPLEMENTATION 0 // 0: iterative, 1: recursive
#define DEBUG 1

#if IMPLEMENTATION == 0
    int binary_search(int *array, size_t array_size, int target, int *index) {
        if (array_size <= 0)
            return -1;

        int left = 0;
        int right = array_size-1;
        int counter = 1;

        while(left <= right) {
            if (DEBUG == 1)
                printf("[DEBUG] Iteration %d, left=%d, right=%d, size=%d\n",
                       counter, left, right, right-left);

            int mid = left + (int)((right - left) / 2);
            int mid_value = *(array + mid);

            if ( mid_value == target ) {
                if (DEBUG == 1)
                    printf("[DEBUG] Target found in %d steps/iterations\n",
                            counter);

                *index = mid;
                return 0;
            } else if ( target < mid_value ) {
                right = mid - 1;
            } else if ( target > mid_value ) {
                left = mid + 1;
            }

            counter++;
        }

        return -1;
    }

#elif IMPLEMENTATION == 1
    static int binary_search_recursive(int *array, int left, int right,
            int target, int *index) {

        if (left > right)
            return  -1;

        static int counter = 0;
        counter++;

        if (DEBUG == 1) {
            printf("[DEBUG] Recursion number %d, left=%d, right=%d, size=%d\n",
                    counter, left, right, right-left);
        }

        int mid = left + (int)((right - left) / 2);
        int mid_value = *(array + mid);

        if (mid_value == target) {
            if (DEBUG == 1)
                printf("[DEBUG] Target found in %d recursive calls\n",
                            counter);
            *index = mid;
            return 0;
        } else if (target < mid_value) {
            return binary_search_recursive(array, left, mid-1, target, index);
        } else { // target > mid_value
            return binary_search_recursive(array, mid+1, right, target, index);
        }
    }

    int binary_search(int *array, size_t array_size, int target, int *index) {
        if (array_size <= 0)
            return -1;
        return binary_search_recursive(array, 0, array_size-1, target, index);
    }

#endif
