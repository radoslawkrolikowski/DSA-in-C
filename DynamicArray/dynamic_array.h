#include <stdbool.h>

#ifndef DYNAMIC_ARRAY_TYPE_
#define DYNAMIC_ARRAY_TYPE_

typedef struct DynamicArray {
    int capacity;
    int size;
    int *intArray;
} DynamicArray;

// make_dynamic_array function allocates the memory 
// of the size of 'capacity' for the dynamic array
DynamicArray* make_dynamic_array(int capacity);

// size function returns the size of the array
int size(DynamicArray *array);

// capacity function returns the capacity of the array
int capacity(DynamicArray *array);

// is_empty returns True if the size of the array is 0, False otherwise
bool is_empty(DynamicArray *array);

// push function appends the value to the array
void push(DynamicArray *array, int value);

// at_index function returns the value stored at the provided index
int at_index(DynamicArray *array, int index);

// pop function removes and returns the last item in the array
int pop(DynamicArray *array);

// insert function inserts value at given index
void insert(DynamicArray *array, int value, int index);

// prepend function inserts value at index 0
void prepend(DynamicArray *array, int value);

// delete function deletes an item at given index
void delete(DynamicArray *array, int index);

// array_remove function removes all occurances of the value in the array
void array_remove(DynamicArray *array, int value);

// array_find returns the first index with that value, or -1 if not found
int array_find(DynamicArray *array, int value);

// resize function creates a new resized array and copies all the elements
// from the old array to the new array.
// New array size = old array size * scalling_factor
void resize(DynamicArray *array, float scalling_factor);

// prints array values (pipe separated)
void print_array(DynamicArray *array);

// allocateMemoryError displays the error message and exits
void allocateMemoryError();

// outOfBoundError function displays the error message and exits
void outOfBoundsError();

#endif