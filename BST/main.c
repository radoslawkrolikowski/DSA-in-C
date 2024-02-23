#include "bst.h"
#include <stdio.h>

int main(void) {
    BSTNode *root = make_node(5);
    insert(&root, 3);
    insert(&root, 1);
    insert(&root, 4);
    insert(&root, 7);
    insert(&root, 9);
    insert(&root, 6);
    insert(&root, 8);
    insert(&root, 2);

    printf("--- BST nodes ---\n");
    print_values(root);
    printf("\n");

    return 0;
}
