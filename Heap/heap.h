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

// sift_up function performs the sift up operation on the node at
// provided index.
void sift_up(Heap *heap, int index);

// insert function inserts the value into the heap and
// performs max-heapify operation
void insert(Heap *heap, int value);

// extract_max function returns and removes the maximum value.
// If heap is empty it returns -1.
int extract_max(Heap *heap);

// is_empty function returns true if heap is empty, otherwise
// is returns false.
bool is_empty(Heap *heap);

// get_size returns the number of elements in the heap.
size_t get_size(Heap *heap);

// get_max returns the maximum element without removing it.
// if heap is empty it returns -1.
int get_max(Heap *heap);

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
