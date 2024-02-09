#include "hash_table.h"
#include <stdint.h>
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

    for (int i = 0; i < capacity; ++i)
        *(pArray + i) = NULL;

    pHashTable->data = pArray;
    pHashTable->capacity = capacity;
    pHashTable->size = 0;

    return pHashTable;
}

static KV* make_kv_pair(char *key, int value) {
    KV *pKV = malloc(sizeof(KV));
    if (pKV == NULL)
        logger("ERROR", "allocate memory error", true);

    pKV->key = key;
    pKV->value = value;
    FLAG flag = OCCUPIED;
    pKV->flag = flag;

    return pKV;
}

// djb2 hash function
static uint32_t hash(const char *key) {
    uint32_t hash = 5381;
    int c;

    while ((c = *key++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

void add(HashTable *ht, char *key, int value) {
    if (ht->size == ht->capacity)
        exit(1); // TODO: scale the table up

    KV *pKV = make_kv_pair(key, value);

    uint32_t hash_code = hash(key) % ht->capacity;

    // TODO: check and handle collisions

    *(ht->data + hash_code) = pKV;
    ht->size++;
}

void logger(const char *tag, const char *message, bool _exit) {
    time_t now = time(0);
    char buff[50];
    strftime(buff, 50, "%Y-%m-%d %H:%M:%S", localtime(&now));
    fprintf(stderr, "%s [%s] %s", buff, tag, message);
    if (_exit)
        exit(1);
}
