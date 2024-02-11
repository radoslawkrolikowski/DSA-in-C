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

// add function adds the key-value pair to the HashTable.
// If the key already exists, the value will be overwritten.
// In case of a hash_code collision, it uses linear probing
// to determine the new hash_code.
// Function releases the memory for the DELETED KV items
void add(HashTable *ht, char *key, int value);

// remove_kv function adds the DELETED flag to the KV item
void remove_kv(HashTable *ht, char *key);

// exists function returns true if the given key exists,
// otherwise it returns false
bool exists(HashTable *ht, char *key);

// get_value function writes the value for the provided key into
// the 'value' pointer variable and returns 0. If the key does
// not exists it returns -1
int get_value(HashTable *ht, char *key, int *value);

// resize function allocates the memory for the new hash table of
// the size of factor * old size, then it calculates new hash codes
// and inserts all KV pairs into the new table.
static void resize(HashTable *ht, float factor);

// hash function generates the hash code for the provided key
static uint32_t hash(const char *key);

// logger function logs the message with the tag to the stderr
// if _exit flag is set to true, it exits with code 1
void logger(const char *tag, const char *message, bool _exit);

#endif // HASH_TABLE_
