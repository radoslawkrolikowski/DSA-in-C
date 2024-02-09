#ifndef HASH_TABLE_
#define HASH_TABLE_

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum {
    DELETED,
    OCCUPIED
} FLAG;

typedef struct KV {
    char *key;
    int value;
    FLAG flag;
} KV;

typedef struct HashTable {
    size_t capacity;
    size_t size;
    KV **data;
} HashTable;

// make_hash_table function allocates the memory for the HashTable struct
// and returns the pointer
HashTable* make_hash_table(const size_t capacity);

// make_kv_pair function allocates the memory for the KV struct
// and returns the pointer
static KV* make_kv_pair(char *key, int value);

// add function adds the key-value pair to the HashTable
// if the key already exists, the value will be overwritten
void add(HashTable *ht, char *key, int value);

// hash function generates the hash code for the provided key
static uint32_t hash(const char *key);

// logger function logs the message with the tag to the stderr
// if _exit flag is set to true, it exits with code 1
void logger(const char *tag, const char *message, bool _exit);

#endif // HASH_TABLE_
