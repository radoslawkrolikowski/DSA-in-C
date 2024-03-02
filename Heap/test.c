#include <stdbool.h>
#include <stdio.h>
#include "heap.h"

// redefine assert to set a boolean flag
#ifdef assert
#undef assert
#endif
#define assert(x) (rslt = rslt && (x))

// main result return code used by redefined assert
static int rslt;

// test suite main variables
static int done;
static int num_tests;
static int tests_passed;

void TestStart(char *name) {
    num_tests++;
    rslt = 1;
    printf("-- Testing %s ... ",name);
}

void TestEnd() {
    if (rslt) tests_passed++;
    printf("%s\n", rslt ? "success" : "fail");
}

// ----------
// Test cases
void test_get_parent_index() {
    TestStart("test_get_parent_index");

    size_t capacity = 8;
    int *array = malloc(capacity * sizeof(int));
    assert(array != NULL);

    Heap *heap = build_heap(array, 10, 10);
    assert(get_parent_index(heap, 0) == -1);
    assert(get_parent_index(heap, 10) == -1);
    assert(get_parent_index(heap, 9) == 4);
    assert(get_parent_index(heap, 2) == 0);
    assert(get_parent_index(heap, 5) == 2);
    assert(get_parent_index(heap, 6) == 2);
    assert(get_parent_index(heap, 7) == 3);

    TestEnd();
}

void test_get_left_child_index() {
    TestStart("test_get_left_child_index");

    size_t capacity = 8;
    int *array = malloc(capacity * sizeof(int));
    assert(array != NULL);

    Heap *heap = build_heap(array, capacity, 7);
    assert(get_left_child_index(heap, 7) == -1);
    assert(get_left_child_index(heap, 5) == -1);
    assert(get_left_child_index(heap, 0) == 1);
    assert(get_left_child_index(heap, 1) == 3);
    assert(get_left_child_index(heap, 2) == 5);

    TestEnd();
}

void test_get_right_child_index() {
    TestStart("test_get_right_child_index");

    size_t capacity = 8;
    int *array = malloc(capacity * sizeof(int));
    assert(array != NULL);

    Heap *heap = build_heap(array, capacity, 7);
    assert(get_right_child_index(heap, 7) == -1);
    assert(get_right_child_index(heap, 5) == -1);
    assert(get_right_child_index(heap, 0) == 2);
    assert(get_right_child_index(heap, 1) == 4);

    TestEnd();
}

void test_build_heap() {
    TestStart("test_build_heap");

    size_t capacity = 10;
    int *array = malloc(capacity * sizeof(int));
    assert(array != NULL);

    int init_array[9] = {2,5,1,3,4,7,8,10,6};
    for (int i = 0; i < 9; ++i)
        *(array + i) = init_array[i];

    Heap *heap = build_heap(array, capacity, 9);

    int result_array[9] = {10,6,8,5,4,7,1,3,2};

    for (int i = 0; i < 9; i++)
        assert(*(heap->array + i) == result_array[i]);

    TestEnd();
}

void test_get_max() {
    TestStart("test_get_max");

    size_t capacity = 10;
    int *array = malloc(capacity * sizeof(int));
    assert(array != NULL);

    int init_array[9] = {2,5,1,3,4,7,8,10,6};
    for (int i = 0; i < 9; ++i)
        *(array + i) = init_array[i];

    Heap *heap = build_heap(array, capacity, 9);
    assert(get_max(heap) == 10);

    TestEnd();
}

void test_insert() {
    TestStart("test_insert");

    size_t capacity = 16;
    int *array = malloc(capacity * sizeof(int));
    assert(array != NULL);

    int init_array[9] = {2,5,1,3,4,7,8,10,6};
    for (int i = 0; i < 9; ++i)
        *(array + i) = init_array[i];

    Heap *heap = build_heap(array, capacity, 9);
    insert(heap, 9);

    int result_array[10] = {10,9,8,5,6,7,1,3,2,4};

    for (int i = 0; i < 10; i++) {
        assert(*(heap->array + i) == result_array[i]);
    }

    TestEnd();
}

void test_resize_array() {
    TestStart("test_resize_array");

    size_t capacity = 4;
    int *array = malloc(capacity * sizeof(int));
    assert(array != NULL);

    int init_array[4] = {2,5,1,3};
    for (int i = 0; i < 4; ++i)
        *(array + i) = init_array[i];

    Heap *heap = build_heap(array, capacity, 4);
    insert(heap, 9);
    assert(heap->capacity == 8);
    assert(get_max(heap) == 9);
    extract_max(heap, true);
    extract_max(heap, true);
    extract_max(heap, true);
    extract_max(heap, true);
    assert(heap->capacity == 4);

    TestEnd();
}

void test_extract_max() {
    TestStart("test_extract_max");

    size_t capacity = 16;
    int *array = malloc(capacity * sizeof(int));
    assert(array != NULL);

    int init_array[9] = {2,5,1,3,4,7,8,10,6};
    for (int i = 0; i < 9; ++i)
        *(array + i) = init_array[i];

    Heap *heap = build_heap(array, capacity, 9);
    assert(extract_max(heap, true) == 10);
    assert(heap->size == 8);
    assert(extract_max(heap, true) == 8);
    assert(heap->size == 7);

    TestEnd();
}

void test_remove() {
    TestStart("test_remove");

    size_t capacity = 16;
    int *array = malloc(capacity * sizeof(int));
    assert(array != NULL);

    int init_array[9] = {2,5,1,3,4,7,8,10,6};
    for (int i = 0; i < 9; ++i)
        *(array + i) = init_array[i];

    Heap *heap = build_heap(array, capacity, 9);
    assert(remove_value(heap, 1) == 6);
    assert(heap->size == 8);

    int result_array[8] = {10,5,8,3,4,7,1,2};

    for (int i = 0; i < 8; i++) {
        assert(*(heap->array + i) == result_array[i]);
    }

    TestEnd();
}

void test_heap_sort() {
    TestStart("test_heap_sort");

    size_t capacity = 16;
    int *array = malloc(capacity * sizeof(int));
    assert(array != NULL);

    int init_array[9] = {2,5,1,3,4,7,8,10,6};
    for (int i = 0; i < 9; ++i)
        *(array + i) = init_array[i];

    heap_sort(array, 9);

    int result_array[9] = {1,2,3,4,5,6,7,8,10};

    for (int i = 0; i < 9; i++) {
        assert(*(array + i) == result_array[i]);
    }

    TestEnd();
}

int main(void) {

    num_tests = 0;
    tests_passed = 0;
    done = 0;

    test_get_parent_index();
    test_get_left_child_index();
    test_get_right_child_index();
    test_build_heap();
    test_get_max();
    test_insert();
    test_resize_array();
    test_extract_max();
    test_remove();
    test_heap_sort();

    printf("Total tests passed: %d\n", tests_passed);
    done = 1;
    return !(tests_passed == num_tests);
}
