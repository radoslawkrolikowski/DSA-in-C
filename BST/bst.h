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

// delete_tree releases the memory of all the tree/subtree nodes
void delete_tree(BSTNode *node);

// is_in_tree function returns true if a given value exists in the tree,
// otherwise it returns false
bool is_in_tree(BSTNode *node, int value);

// max_value function returns maximum of (x,y)
static int max_value(int x, int y);

// get_depth function returns the depth of the tree/subtree
int get_depth(BSTNode *node);

// get_min function returns the minimum value in the tree/subtree
// If tree is empty it returns 0.
int get_min(BSTNode *node);

// get_max function returns the maximum value in the tree/subtree
// If tree is empty it returns 0.
int get_max(BSTNode *node);

// is_binary_search_tree function returns true if the tree is a valid
// binary search tree, otherwise it returns false.
bool is_binary_search_tree(BSTNode *node);

// __is_binary_search_tree is a helper function that performs the in-order
// traversal and updates the last_value variable
static bool __is_binary_search_tree(BSTNode *node, int *last_value);

// delete_value function deletes the node with the given value.
BSTNode* delete_value(BSTNode *node, int value);

// logger function logs the tag and message to the stderr. If _exit flag
// is set to true it exits with code 1.
void logger(const char *tag, const char *message, bool _exit);

#endif // BST_H_
