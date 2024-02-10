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

    add(ht, "England", 7); // update the value for key 'England'
    assert(*(ht->data + 4) != NULL);
    assert(strcmp((*(ht->data + 4))->key, "England") == 0);
    assert((*(ht->data + 4))->value == 7);

    add(ht, "France", 3);
    assert(*(ht->data + 2) != NULL);
    assert(strcmp((*(ht->data + 2))->key, "France") == 0);

    add(ht, "Italy", 4); // collision with 'France' at index 2
    assert(*(ht->data + 3) != NULL);
    assert(strcmp((*(ht->data + 3))->key, "Italy") == 0);

    add(ht, "Greece", 6); // collisions at index: 2,3,4
    assert(*(ht->data + 5) != NULL);
    assert(strcmp((*(ht->data + 5))->key, "Greece") == 0);

    add(ht, "Sweden", 1);
    assert(*(ht->data + 9) != NULL);
    assert(strcmp((*(ht->data + 9))->key, "Sweden") == 0);

    add(ht, "Iceland", 2); // collision at index 9
    assert(*(ht->data) != NULL);
    assert(strcmp((*(ht->data))->key, "Iceland") == 0);

    /*for (int i = 0; i < ht->capacity; i++) {
        if (*(ht->data + i) == NULL)
            fprintf(stderr, "NULL\n");
        else {
            char *k = (*(ht->data + i))->key;
            int v = (*(ht->data + i))->value;
            fprintf(stderr, "%s: %d\n", k, v);
        }
    } */

    TestEnd();
}

void test_remove_kv() {
    TestStart("test_remove_kv");

    HashTable *ht = make_hash_table(10);

    add(ht, "France", 3);
    assert(*(ht->data + 2) != NULL);
    add(ht, "Italy", 4); // collision with 'France' at index 2
    assert(*(ht->data + 3) != NULL);

    remove_kv(ht, "Italy");
    assert((*(ht->data + 3))->flag == DELETED);
    assert(ht->size == 1);

    TestEnd();
}

int main(void) {
    num_tests = 0;
    tests_passed = 0;
    done = 0;

    test_make_empty_hash_table();
    test_add_kv_pair();
    test_remove_kv();

    printf("Total tests passed: %d\n", tests_passed);
    done = 1;
    return !(tests_passed == num_tests);
}
