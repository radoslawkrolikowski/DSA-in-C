#include <stdbool.h>
#include <stdio.h>
#include "queue.h"

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
void test_make_empty_queue()
{
    TestStart("test_make_empty_queue");
    
    Queue *queue = make_queue();
    assert(empty(queue) == true);
    assert(queue->tail == NULL);
    assert(queue->size == 0);

    TestEnd();
}

void test_enqueue()
{
    TestStart("test_enqueue");
    
    Queue *queue = make_queue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    assert(queue->head->value == 1);
    assert(queue->head->next->value == 2);
    assert(queue->tail->value == 3);
    assert(queue->size == 3);

    TestEnd();
}

void test_dequeue()
{
    TestStart("test_dequeue");
    
    Queue *queue = make_queue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    int result = -1;
    assert(dequeue(queue, &result) == 0);
    assert(result == 1);
    assert(dequeue(queue, &result) == 0);
    assert(result == 2);
    assert(queue->size == 1);
    assert(dequeue(queue, &result) == 0);
    assert(result == 3);
    assert(empty(queue) == true);
    assert(dequeue(queue, &result) == -1);

    TestEnd();
}

int main(void) {

    num_tests = 0;
    tests_passed = 0;
    done = 0;
  
    test_make_empty_queue();
    test_enqueue();
    test_dequeue();

    printf("Total tests passed: %d\n", tests_passed);
    done = 1;
    return !(tests_passed == num_tests);
}
