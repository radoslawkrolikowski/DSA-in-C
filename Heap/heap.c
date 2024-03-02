#include "heap.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

int get_parent_index(Heap *heap, int index) {
    if (index <= 0 || index >= heap->size)
        return -1;

    return ((index-1) / 2);
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

void sift_up(Heap *heap, int index) {
    if (index < 0 || index >= heap->size)
        return;

    int parent = get_parent_index(heap, index);
    if (parent == -1)
        return;

    if (*(heap->array + index) > *(heap->array + parent)) {
        // swap parent with the greater child (binary XOR swap algorithm)
        *(heap->array + index) ^= *(heap->array + parent);
        *(heap->array + parent) ^= *(heap->array + index);
        *(heap->array + index) ^= *(heap->array + parent);

        // go up the tree
        sift_up(heap, parent);
    }
}

void insert(Heap *heap, int value) {
    if (heap->size >= heap->capacity) {
        int *pArray = realloc(heap->array, heap->capacity * 2);
        if (pArray == NULL)
            logger("[ERROR]", "could not reallocate the heap array", true);

        heap->array = pArray;
        heap->capacity = heap->capacity * 2;
    }

    *(heap->array + heap->size) = value;
    heap->size++;
    sift_up(heap, heap->size-1);
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

int extract_max(Heap *heap, bool scale_down) {
    if (heap->size == 0)
        return -1;

    // swap first and last element (XOR swap algorithm)
    *(heap->array) ^= *(heap->array + heap->size-1);
    *(heap->array + heap->size-1) ^= *(heap->array);
    *(heap->array) ^= *(heap->array + heap->size-1);

    heap->size--;

    if (scale_down & (heap->size < heap->capacity / 4)) {
        int *pArray = realloc(heap->array, heap->capacity / 2);
        if (pArray == NULL)
            logger("[ERROR]", "could not reallocate the heap array", true);

        heap->array = pArray;
        heap->capacity = heap->capacity / 2;
    }

    sift_down(heap, 0);

    return *(heap->array + heap->size);
}

int remove_value(Heap *heap, int index) {
    if (heap->size == 0 || index < 0 || index >= heap->size)
        return -1;

    // swap element at index position and last element (XOR swap algorithm)
    *(heap->array + index) ^= *(heap->array + heap->size-1);
    *(heap->array + heap->size-1) ^= *(heap->array + index);
    *(heap->array + index) ^= *(heap->array + heap->size-1);

    heap->size--;

    if (heap->size < heap->capacity / 4) {
        int *pArray = realloc(heap->array, heap->capacity / 2);
        if (pArray == NULL)
            logger("[ERROR]", "could not reallocate the heap array", true);

        heap->array = pArray;
        heap->capacity = heap->capacity / 2;
    }

    sift_down(heap, index);

    return *(heap->array + heap->size);
}

bool is_empty(Heap *heap) {
    return heap->size == 0;
}

size_t get_size(Heap *heap) {
    return heap->size;
}

int get_max(Heap *heap) {
    if (heap->size == 0)
        return -1;

    return *(heap->array);
}

void heap_sort(int *array, size_t size) {
    Heap *heap = build_heap(array, size, size);

    for (int i = 0; i < size-1; i++)
        extract_max(heap, false);
}

void logger(const char *tag, const char *message, bool _exit) {
    time_t now = time(0);
    char buff[50];
    strftime(buff, 50, "%Y-%m-%d %H:%M:%S", localtime(&now));
    fprintf(stderr, "%s [%s] %s\n", buff, tag, message);
    if (_exit)
        exit(1);
}

