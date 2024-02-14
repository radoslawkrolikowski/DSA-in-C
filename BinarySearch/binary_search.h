#ifndef BINARY_SEARCH_

#include <stdlib.h>

// binary_search function performs the bianary search of the provided target
// value in the array. If the target is found, its index is written to the
// 'index' pointer variable, then the function returns 0. If the target value
// was not found the function returns -1.
int binary_search(int *array, size_t array_size, int target, int *index);

#endif // BINARY_SEARCH_
