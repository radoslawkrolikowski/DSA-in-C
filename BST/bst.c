#include "bst.h"
#include <limits.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

BSTNode* make_node(const int data) {
    BSTNode *pNode = malloc(sizeof(BSTNode));
    if (pNode == NULL)
        logger("ERROR", "allocate memory error", true);

    pNode->data = data;
    pNode->left = NULL;
    pNode->right = NULL;

    return pNode;
}

int insert(BSTNode **node, const int data) {
    if (*node == NULL) {
        *node = make_node(data);
        return 0;
    }

    if (data < (*node)->data)
        return insert(&(*node)->left, data);
    else if (data > (*node)->data)
        return insert(&(*node)->right, data);
    else
        return 1;
}

int get_node_count(BSTNode *node) {
    if (node == NULL)
        return 0;

    return 1 + get_node_count(node->left) + get_node_count(node->right);
}

void print_values(BSTNode *node) {
    if (node == NULL)
        return;

    print_values(node->left);
    fprintf(stderr, "%d ", node->data);
    print_values(node->right);
}

void delete_tree(BSTNode *node) {
    if (node == NULL)
        return;

    delete_tree(node->left);
    delete_tree(node->right);

    free(node);
}

bool is_in_tree(BSTNode *node, int value) {
    if (node == NULL)
        return false;

    if (value == node->data)
        return true;
    else if (value < node->data)
        return is_in_tree(node->left, value);
    else
        return is_in_tree(node->right, value);
}

static int max_value(int x, int y) {
    if (x >= y)
        return x;
    return y;
}

int get_depth(BSTNode *node) {
   if (node == NULL)
       return 0;

   return 1 + max_value(get_depth(node->left), get_depth(node->right));
}

int get_min(BSTNode *node) {
    if (node->left)
        return get_min(node->left);
    else
        return node->data;
}

int get_max(BSTNode *node) {
    if (node->right)
        return get_max(node->right);
    else
        return node->data;
}

bool is_binary_search_tree(BSTNode *node) {
    int last_value = INT_MIN;
    return __is_binary_search_tree(node, &last_value);
}

static bool __is_binary_search_tree(BSTNode *node, int *last_value) {
    if (node == NULL)
        return true;

    if (!__is_binary_search_tree(node->left, last_value))
        return false;

    if (node->data <= *last_value) {
        return false;
    }

    *last_value = node->data;

    if (!__is_binary_search_tree(node->right, last_value))
        return false;

    return  true;
}

BSTNode* delete_value(BSTNode *node, int value) {
    if (node == NULL) {
        return node;
    }

    if (value < node->data)
        node->left = delete_value(node->left, value);
    else if (value > node->data) {
        node->right = delete_value(node->right, value);
    }
    else {
        if (!node->left && !node->right) {
            free(node);
            return NULL;
        } else if (!node->left != !node->right) { // logical XOR
            BSTNode *temp = node->left ? node->left : node->right;
            free(node);
            return temp;
        } else {
            int minVal = get_min(node->right);
            node->data = minVal;
            node->right = delete_value(node->right, minVal);
            return node;
        }
    }

    return node;
}

void logger(const char *tag, const char *message, bool _exit) {
    time_t now = time(0);
    char buff[50];
    strftime(buff, 50, "%Y-%m-%d %H:%M:%S", localtime(&now));
    fprintf(stderr, "%s [%s] %s\n", buff, tag, message);
    if (_exit)
        exit(1);
}
