#ifndef HEAP_H
#define HEAP_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct Heap {
    int *array;
    size_t capacity;
    size_t size;
} Heap;

// build_heap function creates a max-heap from an arbitrary array of
// integers. It takes as arguments: an array pointer, capacity determining
// the initial capacity of the array and size that specifies the initial
// number of elements in the array.
Heap* build_heap(int *array, size_t capacity, size_t size);

// sift_down function performs the sift down operation on the node at
// provided index.
void sift_down(Heap *heap, int index);

// get_parent_index function returns the index of the parent node
// if exists, otherwise it returns -1.
int get_parent_index(Heap *heap, int index);

// get_left_child_index function Vreturns the index of the left child node
// if exists, otherwise it returns -1.
int get_left_child_index(Heap *heap, int index);

// get_right_child_index function Vreturns the index of the right child node
// if exists, otherwise it returns -1.
int get_right_child_index(Heap *heap, int index);

// logger function logs the tag and message to stderr. If _exit flag
// is set to true it exists with code 1.
void logger(const char *tag, const char *message, bool _exit);

#endif // HEAP_H
