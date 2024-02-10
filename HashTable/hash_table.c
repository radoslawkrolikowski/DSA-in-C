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
    KV *pInsKV = *(ht->data + hash_code);

    if (pInsKV != NULL && strcmp(pInsKV->key, key) == 0) {
        pInsKV->value = value;
        return;
    }

    while (pInsKV != NULL && pInsKV->flag == OCCUPIED) {
        hash_code++;
        if (hash_code == ht->capacity)
            hash_code = 0;
        pInsKV = *(ht->data + hash_code);
    }

    if (pInsKV != NULL && pInsKV->flag == DELETED)
        free(pInsKV);

    *(ht->data + hash_code) = pKV;
    ht->size++;
}

void remove_kv(HashTable *ht, char *key) {
    // TODO: if size < 1/4 of capacity -> scale down

    uint32_t hash_code = hash(key) % ht->capacity;
    KV *pInsKV = *(ht->data + hash_code);

    while (pInsKV != NULL) {
        if (strcmp(pInsKV->key, key) == 0) {
            pInsKV->flag = DELETED;
            ht->size--;
            return;
        }

        hash_code++;
        if (hash_code == ht->capacity)
            hash_code = 0;
        pInsKV = *(ht->data + hash_code);
    }
}

void logger(const char *tag, const char *message, bool _exit) {
    time_t now = time(0);
    char buff[50];
    strftime(buff, 50, "%Y-%m-%d %H:%M:%S", localtime(&now));
    fprintf(stderr, "%s [%s] %s", buff, tag, message);
    if (_exit)
        exit(1);
}
