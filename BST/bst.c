#include "bst.h"
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

void logger(const char *tag, const char *message, bool _exit) {
    time_t now = time(0);
    char buff[50];
    strftime(buff, 50, "%Y-%m-%d %H:%M:%S", localtime(&now));
    fprintf(stderr, "%s [%s] %s\n", buff, tag, message);
    if (_exit)
        exit(1);
}
