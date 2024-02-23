#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

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
void test_insert() {
    TestStart("test_insert");

    BSTNode *root = make_node(5);
    assert(root->data == 5);
    int code = -1;
    code = insert(&root, 3);
    assert(code == 0);
    assert(root->left->data == 3);
    code = insert(&root, 4);
    assert(code == 0);
    assert(root->left->right->data == 4);
    code = insert(&root, 3);
    assert(code == 1);
    assert(root->left->data == 3);
    TestEnd();
}

void test_get_node_count() {
    TestStart("test_get_node_count");

    BSTNode *root = make_node(5);
    insert(&root, 3);
    insert(&root, 4);
    insert(&root, 1);
    insert(&root, 8);
    assert(get_node_count(root) == 5);

    TestEnd();
}

int main(void) {
    num_tests = 0;
    tests_passed = 0;
    done = 0;

    test_insert();
    test_get_node_count();

    printf("Total tests passed: %d\n", tests_passed);
    done = 1;
    return !(tests_passed == num_tests);
}
