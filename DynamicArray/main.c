#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"


int main(void) {

    DynamicArray* array = make_dynamic_array(10);
    push(array, 1);
    push(array, 2);
    push(array, 4);
    prepend(array, 0);
    insert(array, 3, 3);

    print_array(array);

    free(array->intArray);
    free(array);

    return 0;
}