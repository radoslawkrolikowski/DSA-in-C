#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "dynamic_array.h"

DynamicArray* make_dynamic_array(int capacity) {
    DynamicArray* pDynArr = malloc(sizeof(DynamicArray));
    pDynArr->capacity = capacity;

    int* ptr = (int*) malloc(capacity * sizeof(int));
    if (ptr == NULL) allocateMemoryError();
    pDynArr->intArray = ptr;

    return pDynArr;
}

int size(DynamicArray *array) {
    return array->size;
}

int capacity(DynamicArray *array) {
    return array->capacity;
}

bool is_empty(DynamicArray *array) {
    return array->size == 0;
}

void push(DynamicArray *array, int value) {
    if (array->size == array->capacity-1) {
        resize(array, 2.0f);
    }

    *(array->intArray + array->size) = value;
    array->size++;
}

int at_index(DynamicArray *array, int index) {
    if (index < 0 || index > (array->size-1)) {
        outOfBoundsError();
    }

    return *(array->intArray + index);
}

int pop(DynamicArray *array) {
    if (is_empty(array)) {
        outOfBoundsError();
    }

    int returnItem = *(array->intArray + --(array->size));

    if (array->size < (array->capacity / 4))
        resize(array, 0.5f);

    return returnItem;
}


void insert(DynamicArray *array, int value, int index) {
    if (index < 0 || index > (array->size-1)) {
        outOfBoundsError();
    }

    if (array->size == array->capacity-1) {
        resize(array, 2.0f);
    }

    for(int i = array->size; i > index; i--) {
        *(array->intArray+i) = *(array->intArray+i-1);
    }

    *(array->intArray+index) = value;
    array->size++;
}

void prepend(DynamicArray *array, int value) {
    insert(array, value, 0);
}

void delete(DynamicArray *array, int index) {
    if (index < 0 || index > (array->size-1)) {
        outOfBoundsError();
    }

    for(int i = index; i < array->size-1; i++) {
        *(array->intArray+i) = *(array->intArray+i+1);
    }

    array->size--;

    if (array->size < (array->capacity / 4))
        resize(array, 0.5f);
}


void array_remove(DynamicArray *array, int value) {
    int i = 0; 
    int k = 0;

    while(1) {
        if (*(array->intArray+k) == value) {
            k++;
        } else {
            i++; k++;
        }
        if (k >= array->size) break;
        if (k != i) {
            *(array->intArray+i) = *(array->intArray+k);
        }
    }

    array->size = (array->size)-(k-i);

    if (array->size < (array->capacity / 4))
        resize(array, 0.5f);
}

int array_find(DynamicArray *array, int value) {

    for (int i = 0; i < array->size; i++) {
        if (*(array->intArray+i) == value) {
            return i;
        }
    }

    return -1;
}

void resize(DynamicArray *array, float scalling_factor) {
    int newSize = (int)(array->capacity * scalling_factor);
    int *newPtr = realloc(array->intArray, newSize);
    if (newPtr == NULL) {
        allocateMemoryError();
    }

    array->intArray = newPtr;
    array->capacity = newSize;
}

void print_array(DynamicArray *array) {
    for(int i = 0; i < array->size; i++) {
        printf("%d", *(array->intArray + i));
        if (i != array->size-1)
            printf(" | ");
    }
    printf("\n");
}

void allocateMemoryError() {
    fprintf(stderr, "Could not allocate memory\n");
    exit(1);
}

void outOfBoundsError() {
    fprintf(stderr, "index out of bounds\n");
    exit(1);
}