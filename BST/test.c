#include <stdbool.h>
#include <stdio.h>
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

void test_get_depth() {
    TestStart("test_get_depth");

    BSTNode *root = make_node(5);
    insert(&root, 3);
    insert(&root, 4);
    insert(&root, 1);
    insert(&root, 8);
    assert(get_depth(root) == 3);

    TestEnd();
}

void test_is_in_tree() {
    TestStart("test_is_in_tree");

    BSTNode *root = make_node(5);
    insert(&root, 3);
    insert(&root, 4);
    insert(&root, 1);
    insert(&root, 8);
    assert(is_in_tree(root, 5) == true);
    assert(is_in_tree(root, 8) == true);
    assert(is_in_tree(root, 1) == true);
    assert(is_in_tree(root, 3) == true);
    assert(is_in_tree(root, 15) == false);

    TestEnd();
}

void test_get_min() {
    TestStart("test_get_min");

    BSTNode *root = make_node(5);
    assert(get_min(root) == 5);
    insert(&root, 3);
    assert(get_min(root) == 3);
    insert(&root, 4);
    assert(get_min(root) == 3);
    insert(&root, 1);
    assert(get_min(root) == 1);
    insert(&root, 8);
    assert(get_min(root) == 1);

    TestEnd();
}

void test_get_max() {
    TestStart("test_get_max");

    BSTNode *root = make_node(5);
    assert(get_max(root) == 5);
    insert(&root, 3);
    assert(get_max(root) == 5);
    insert(&root, 4);
    assert(get_max(root) == 5);
    insert(&root, 6);
    assert(get_max(root) == 6);
    insert(&root, 8);
    assert(get_max(root) == 8);

    TestEnd();
}

void test_is_binary_search_tree() {
    TestStart("test_is_binary_search_tree");

    BSTNode *root = make_node(5);
    insert(&root, 3);
    insert(&root, 4);
    insert(&root, 1);
    insert(&root, 6);
    insert(&root, 9);
    insert(&root, 8);
    assert(is_binary_search_tree(root) == true);

    root->data = 7;
    assert(is_binary_search_tree(root) == false);

    root->data = 5;
    root->left->data = 10;
    assert(is_binary_search_tree(root) == false);

    TestEnd();
}

void test_delete_value() {
    TestStart("test_delete_value");

    BSTNode *root = make_node(5);
    root = delete_value(root, 5);
    assert(root == NULL);

    root = make_node(5);
    insert(&root, 3);
    insert(&root, 4);
    insert(&root, 1);
    insert(&root, 8);
    insert(&root, 7);
    insert(&root, 9);
    insert(&root, 6);
    insert(&root, 10);

    root = delete_value(root, 1);
    assert(root->data == 5);
    assert(get_min(root) == 3);

    root = delete_value(root, 3);
    assert(root->left->data == 4);

    root = delete_value(root, 8);
    assert(root->right->data == 9);

    root = delete_value(root, 22);
    assert(root->data == 5);

    assert(is_binary_search_tree(root) == true);

    TestEnd();
}

void test_get_successor() {
    TestStart("test_get_successor");

    BSTNode *root = make_node(5);
    insert(&root, 3);
    insert(&root, 4);
    insert(&root, 1);
    insert(&root, 8);
    insert(&root, 7);
    insert(&root, 9);
    insert(&root, 6);
    insert(&root, 10);
    assert(get_successor(root, 1) == 3);
    assert(get_successor(root, 3) == 4);
    assert(get_successor(root, 5) == 6);
    assert(get_successor(root, 6) == 7);
    assert(get_successor(root, 10) == -1);
    assert(get_successor(root, 22) == -1);

    TestEnd();
}

int main(void) {
    num_tests = 0;
    tests_passed = 0;
    done = 0;

    test_insert();
    test_get_node_count();
    test_is_in_tree();
    test_get_depth();
    test_get_min();
    test_get_max();
    test_is_binary_search_tree();
    test_delete_value();
    test_get_successor();

    printf("Total tests passed: %d\n", tests_passed);
    done = 1;
    return !(tests_passed == num_tests);
}
