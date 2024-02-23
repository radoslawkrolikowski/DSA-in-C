#ifndef BST_H_
#define BST_H_

#include <stdbool.h>

typedef struct BSTNode {
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

// make_node function allocates the memory for the BSTNode and returns
// the pointer.
BSTNode* make_node(const int data);

// insert function inserts the data value into the BST and returns 0
// if operation was successful, otherwise it returns 1.
// Duplicate values are not allowed.
int insert(BSTNode **node, const int data);

// get_node_count returns the number of the nodes in BST
int get_node_count(BSTNode *node);

// print_values function prints the tree values in-order
void print_values(BSTNode *node);

// logger function logs the tag and message to the stderr. If _exit flag
// is set to true it exits with code 1.
void logger(const char *tag, const char *message, bool _exit);

#endif // BST_H_
