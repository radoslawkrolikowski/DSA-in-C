#include <stdbool.h>
#include <stdio.h>
#include "linked_lists.h"

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
void test_make_empty_linked_list()
{
    TestStart("test_make_empty_linked_lists");
    
    LinkedLists *list = make_linked_lists();
    assert(empty(list) == true);

    TestEnd();
}

void test_push_front()
{
    TestStart("test_push_front");
    
    LinkedLists *list = make_linked_lists();
    push_front(list, 3);
    push_front(list, 2);
    push_front(list, 1);
    assert(list->head->value == 1);
    assert(list->head->next->value == 2);
    assert(list->head->next->next->value == 3);
    assert(list->size == 3);

    TestEnd();
}

void test_push_back()
{
    TestStart("test_push_back");

    LinkedLists *list = make_linked_lists();
    push_back(list, 1);
    push_back(list, 2);
    push_back(list, 3);
    assert(list->head->value == 1);
    assert(list->head->next->value == 2);
    assert(list->head->next->next->value == 3);
    assert(list->size == 3);

    TestEnd();
}

void test_front()
{
    TestStart("test_front");

    LinkedLists *list = make_linked_lists();
    int result = -1;
    assert(front(list, &result) == -1);
    assert(result == -1);
    push_back(list, 5);
    assert(front(list, &result) == 0);
    assert(result == 5);

    TestEnd();
}

void test_back()
{
    TestStart("test_back");

    LinkedLists *list = make_linked_lists();
    int result = -1;
    assert(back(list, &result) == -1);
    assert(result == -1);
    push_back(list, 2);
    push_back(list, 6);
    assert(back(list, &result) == 0);
    assert(result == 6);

    TestEnd();
}

void test_value_at()
{
    TestStart("test_value_at");

    LinkedLists *list = make_linked_lists();
    push_back(list, 1);
    push_back(list, 2);
    push_back(list, 3);
    push_back(list, 4);
    push_back(list, 5);
    assert(value_at(list, 0) == 1);
    assert(value_at(list, 3) == 4);
    assert(value_at(list, 10) == -1);

    TestEnd();
}

void test_pop_front()
{
    TestStart("test_pop_front");

    LinkedLists *list = make_linked_lists();
    int result = -1;
    assert(pop_front(list, &result) == -1);
    assert(result == -1);
    push_back(list, 2);
    push_back(list, 6);
    assert(pop_front(list, &result) == 0);
    assert(result == 2);
    assert(list->size == 1);

    TestEnd();
}

void test_pop_back()
{
    TestStart("test_pop_back");

    LinkedLists *list = make_linked_lists();
    int result = -1;
    assert(pop_back(list, &result) == -1);
    assert(result == -1);
    push_back(list, 2);
    push_back(list, 6);
    assert(pop_back(list, &result) == 0);
    assert(result == 6);
    assert(list->size == 1);
    assert(pop_back(list, &result) == 0);
    assert(result == 2);
    assert(list->size == 0);

    TestEnd();
}


void test_value_n_from_end()
{
    TestStart("test_value_n_from_end");

    LinkedLists *list = make_linked_lists();
    int result = -1;
    assert(value_n_from_end(list, 0, &result) == -1);
    assert(result == -1);
    push_back(list, 1);
    push_back(list, 2);
    push_back(list, 3);
    push_back(list, 4);
    push_back(list, 5);
    assert(value_n_from_end(list, 2, &result) == 0);
    assert(result == 4);

    TestEnd();
}

void test_insert()
{
    TestStart("test_insert");

    LinkedLists *list = make_linked_lists();
    assert(insert(list, 2, 2) == -1);
    assert(insert(list, 0, 0) == 0);
    assert(value_at(list, 0) == 0);
    assert(insert(list, 1, 1) == 0);
    assert(value_at(list, 1) == 1);
    assert(insert(list, 1, 5) == 0);
    assert(value_at(list, 1) == 5);
    assert(value_at(list, 2) == 1);
    assert(list->size == 3);

    TestEnd();
}

void test_remove_value()
{
    TestStart("test_remove_value");

    LinkedLists *list = make_linked_lists();
    insert(list, 0, 0);
    insert(list, 1, 1);
    insert(list, 2, 2);
    remove_value(list, 1);
    assert(value_at(list, 1) == 2);
    assert(list->size == 2);
    remove_value(list, 2);
    assert(value_at(list, 0) == 0);
    remove_value(list, 0);
    assert(list->size == 0);
    remove_value(list, 4);

    TestEnd();
}

void test_reverse()
{
    TestStart("test_reverse");

    LinkedLists *list = make_linked_lists();
    push_back(list, 1);
    push_back(list, 2);
    push_back(list, 3);
    push_back(list, 4);
    push_back(list, 5);
    reverse(list);
    assert(value_at(list, 0) == 5);
    assert(value_at(list, 1) == 4);
    assert(value_at(list, 2) == 3);
    assert(value_at(list, 3) == 2);
    assert(value_at(list, 4) == 1);

    TestEnd();
}

void test_delete_node()
{
    TestStart("test_delete_node");

    LinkedLists *list = make_linked_lists();
    push_back(list, 1);
    push_back(list, 2);
    push_back(list, 3);
    push_back(list, 4);
    delete_node(list, 1);
    assert(value_at(list, 0) == 1);
    assert(value_at(list, 1) == 3);
    assert(value_at(list, 2) == 4);
    delete_node(list, 0);
    assert(value_at(list, 0) == 3);
    assert(value_at(list, 1) == 4);
    delete_node(list, 1);
    assert(value_at(list, 0) == 3);
    assert(list->size == 1);

    TestEnd();
}

int main(void) {

    num_tests = 0;
    tests_passed = 0;
    done = 0;
  
    test_make_empty_linked_list();
    test_push_front();
    test_push_back();
    test_front();
    test_back();
    test_value_at();
    test_pop_front();
    test_pop_back();
    test_value_n_from_end();
    test_insert();
    test_remove_value();
    test_reverse();
    test_delete_node();

    printf("Total tests passed: %d\n", tests_passed);
    done = 1;
    return !(tests_passed == num_tests);
}
