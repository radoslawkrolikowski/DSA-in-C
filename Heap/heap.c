#include "heap.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

int get_parent_index(Heap *heap, int index) {
    if (index <= 0 || index >= heap->size)
        return -1;

    return (index / 2) - 1;
}

int get_left_child_index(Heap *heap, int index) {
    if (index < 0 || index >= heap->size)
        return -1;

    int left = (index * 2) + 1;
    if (left >= heap->size)
        return -1;

    return left;
}

int get_right_child_index(Heap *heap, int index) {
    if (index < 0 || index >= heap->size)
        return -1;

    int right = (index * 2) + 2;
    if (right >= heap->size)
        return -1;

    return right;
}

void sift_down(Heap *heap, int index) {
    if (index < 0 || index >= heap->size)
        return;

    int max_val_index = index;

    // find the maximum between the parent, left child and right child
    int left = get_left_child_index(heap, index);
    if (left != -1 && *(heap->array + left) > *(heap->array + max_val_index))
        max_val_index = left;

    int right = get_right_child_index(heap, index);
    if (right != -1 && *(heap->array + right) > *(heap->array + max_val_index))
        max_val_index = right;

    if (max_val_index != index) {
        // swap parent with the greater child (binary XOR swap algorithm)
        *(heap->array + index) ^= *(heap->array + max_val_index);
        *(heap->array + max_val_index) ^= *(heap->array + index);
        *(heap->array + index) ^= *(heap->array + max_val_index);

        // go down the sub-tree
        sift_down(heap, max_val_index);
    }
}

Heap* build_heap(int *array, size_t capacity, size_t size) {
    if (capacity < size)
        logger("[ERROR]", "capacity cannot be lower than the size", true);

    Heap *pHeap = malloc(sizeof(Heap));
    if (pHeap == NULL)
        logger("[ERROR]", "allocate memory error", true);

    pHeap->array = array;
    pHeap->capacity = capacity;
    pHeap->size = size;

    for (int i = (size/2); i >= 0; --i)
        sift_down(pHeap, i);

    return pHeap;
}

void logger(const char *tag, const char *message, bool _exit) {
    time_t now = time(0);
    char buff[50];
    strftime(buff, 50, "%Y-%m-%d %H:%M:%S", localtime(&now));
    fprintf(stderr, "%s [%s] %s\n", buff, tag, message);
    if (_exit)
        exit(1);
}

