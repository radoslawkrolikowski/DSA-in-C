#include <stdio.h>
#include "dynamic_array.h"

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

void TestStart(char *name)
{
    num_tests++;
    rslt = 1;
    printf("-- Testing %s ... ",name);
}

void TestEnd()
{
    if (rslt) tests_passed++;
    printf("%s\n", rslt ? "success" : "fail");
}

// ----------
// Test cases
void test_pointer_assignment()
{
    TestStart("test_pointer_assignment");

    DynamicArray *array = make_dynamic_array(16);
    *(array->intArray) = 9;
    *(array->intArray+1) = 10;
    assert(*(array->intArray) == 9);
    assert(*(array->intArray+1) == 10);

    TestEnd();
}

void test_push() {
    TestStart("test_push");

    DynamicArray *array = make_dynamic_array(16);
    push(array, 4);
    push(array, 5);
    assert(*(array->intArray) == 4);
    assert(*(array->intArray + 1) == 5);
    assert(array->size == 2);

    TestEnd();
}

void test_at_index() {
    TestStart("test_at_index");

    DynamicArray *array = make_dynamic_array(8);
    push(array, 1);
    push(array, 2);
    assert(at_index(array, 0) == 1);
    assert(at_index(array, 1) == 2);

    TestEnd();
}

void test_pop() {
    TestStart("test_pop");

    DynamicArray *array = make_dynamic_array(8);
    push(array, 5);
    push(array, 6);
    push(array, 7);
    assert(pop(array) == 7);
    assert(array->size == 2);
    assert(pop(array) == 6);
    assert(array->size == 1);

    TestEnd();
}

void test_insert() {
    TestStart("test_insert");

    DynamicArray *array = make_dynamic_array(16);
    push(array, 1);
    push(array, 2);
    push(array, 4);
    push(array, 5);
    insert(array, 3, 2);
    assert(*(array->intArray+2) == 3);
    assert(*(array->intArray+4) == 5);
    assert(array->size == 5);

    TestEnd();
}

void test_prepend() {
    TestStart("test_prepend");

    DynamicArray *array = make_dynamic_array(8);
    push(array, 2);
    prepend(array, 1);
    assert(*(array->intArray) == 1);
    assert(*(array->intArray+1) == 2);

    TestEnd();
}

void test_delete() {
    TestStart("test_delete");

    DynamicArray *array = make_dynamic_array(16);
    push(array, 1);
    push(array, 2);
    push(array, 3);
    delete(array, 0);
    assert(*(array->intArray) == 2);
    assert(*(array->intArray+1) == 3);
    assert(array->size == 2);

    TestEnd();

}

void test_remove() {
    TestStart("test_remove");

    DynamicArray *array = make_dynamic_array(16);
    push(array, 0);
    push(array, 1);
    push(array, 2);
    push(array, 3);
    push(array, 2);
    push(array, 4);
    push(array, 5);
    push(array, 2);
    array_remove(array, 2);
    assert(*(array->intArray+2) == 3);
    assert(*(array->intArray+3) == 4);
    assert(*(array->intArray+4) == 5);
    assert(array->size == 5);

    TestEnd();
}

void test_find() {
    TestStart("test_find");

    DynamicArray *array = make_dynamic_array(16);
    push(array, 0);
    push(array, 1);
    push(array, 4);
    push(array, 3);
    push(array, 4);
    assert(array_find(array, 4) == 2);

    TestEnd();
}

void test_resize() {
    TestStart("test_resize");

    DynamicArray *array = make_dynamic_array(8);
    resize(array, 2.0f);
    assert(array->capacity == 16);

    TestEnd();
}

int main(void) {

    num_tests = 0;
    tests_passed = 0;
    done = 0;

    test_pointer_assignment();
    test_push();
    test_at_index();
    test_pop();
    test_insert();
    test_prepend();
    test_delete();
    test_remove();
    test_find();
    test_resize();

    printf("Total tests passed: %d\n", tests_passed);
    done = 1;
    return !(tests_passed == num_tests);
}