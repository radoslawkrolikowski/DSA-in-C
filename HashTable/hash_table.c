#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

HashTable* make_hash_table(const size_t capacity) {
    HashTable *pHashTable = malloc(sizeof(HashTable));
    if (pHashTable == NULL)
        logger("ERROR", "allocate memory error", true);

    KV **pArray = malloc(capacity * sizeof(KV*));
    if (pArray == NULL)
        logger("ERROR", "allocate memory error", true);

    memset(pArray, NULL, capacity);
    pHashTable->data = pArray;

    pHashTable->capacity = capacity;
    pHashTable->size = 0;

    return pHashTable;
}

void logger(const char *tag, const char *message, bool _exit) {
    time_t now = time(0);
    char buff[50];
    strftime(buff, 50, "%Y-%m-%d %H:%M:%S", localtime(&now));
    fprintf(stderr, "%s [%s] %s", buff, tag, message);
    if (_exit)
        exit(1);
}
