#include <stdio.h>
#include "binary_search.h"

int main(void) {
    size_t array_size = 10;
    int array[10] = {0,1,2,3,4,5,6,7,8,9};
    int index = -1;
    int target = 15;
    int status = 1;

    status = binary_search(array, array_size, target, &index);

    if (status == 0)
        printf("Found target=%d at index: %d\n", target, index);
    else if (status == -1)
        printf("target=%d not found in the array\n", target);

    return 0;
}
