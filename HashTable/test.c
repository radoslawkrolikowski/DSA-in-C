#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "hash_table.h"

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
void test_make_empty_hash_table() {
    TestStart("test_make_empty_hash_table");

    HashTable *ht = make_hash_table(10);
    assert(ht->capacity == 10);
    assert(ht->size == 0);
    assert(*(ht->data) == NULL);
    assert(*(ht->data + 1)  == NULL);

    TestEnd();
}

void test_add_kv_pair() {
    TestStart("test_add_kv_pair");

    HashTable *ht = make_hash_table(10);

    add(ht, "England", 5);
    assert(*(ht->data + 4) != NULL);
    assert(strcmp((*(ht->data + 4))->key, "England") == 0);
    assert((*(ht->data + 4))->value == 5);
    assert(*(ht->data + 8) == NULL);
    assert(ht->size == 1);

    /*for (int i = 0; i < ht->capacity; i++) {
        if (*(ht->data + i) == NULL)
            fprintf(stderr, "NULL\n");
        else {
            char *k = (*(ht->data + i))->key;
            int v = (*(ht->data + i))->value;
            fprintf(stderr, "%s: %d\n", k, v);
        }
    }*/

    TestEnd();
}

int main(void) {
    num_tests = 0;
    tests_passed = 0;
    done = 0;

    test_make_empty_hash_table();
    test_add_kv_pair();

    printf("Total tests passed: %d\n", tests_passed);
    done = 1;
    return !(tests_passed == num_tests);
}
