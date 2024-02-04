#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked_lists.h"


static Node* make_node(int value) {
    Node *pNode = malloc(sizeof(Node));
    if (pNode == NULL) {
        allocateMemoryError();
    }

    pNode->value = value;
    pNode->next = NULL;

    return pNode;
}

LinkedLists* make_linked_lists() {
    LinkedLists *pList = malloc(sizeof(LinkedLists));
    if (pList == NULL) {
        allocateMemoryError();
    }

    pList->head = NULL;
    pList->size = 0;

    return pList;
}

int size(LinkedLists *list) {
    return list->size;
}

bool empty(LinkedLists *list) {
    return list->size == 0;
}

void push_front(LinkedLists *list, int value) {
    Node *pNewNode = make_node(value);

    pNewNode->next = list->head;
    list->head = pNewNode;
    
    list->size++;
}

void push_back(LinkedLists *list, int value) {
    Node *pNewNode = make_node(value);

    if (list->head == NULL)
        list->head = pNewNode;
    else {
        Node *temp = list->head;
        for (; temp->next != NULL; temp = temp->next);
        temp->next = pNewNode;
    }

    list->size++;
}

int front(LinkedLists *list, int *result) {
    if (list->size == 0)
        return -1;

    *result = list->head->value;
    return 0;
}

int back(LinkedLists *list, int *result) {
    if (list->size == 0)
        return -1;

    Node *temp = list->head;
    for (; temp->next != NULL; temp = temp->next);

    *result = temp->value;
    return 0;
}

int value_at(LinkedLists *list, int index) {
    if (index < 0 || index >= list->size) {
        return -1;
    }

    Node *temp = list->head;

    for (int i = 0; i < index; i++)
        temp = temp->next;

    return temp->value;
}

int pop_front(LinkedLists *list, int *result) {
    if (list->size == 0)
        return -1;

    *result = list->head->value;
    free(list->head);
    list->head = list->head->next;
    list->size--;

    return 0;    
}

int pop_back(LinkedLists *list, int *result) {
    if (list->size == 0)
        return -1;

    if (list->size == 1) {
        *result = list->head->value;
        free(list->head);
        list->head = NULL;
        list->size--;
        return 0;
    }

    Node *prev = list->head;
    Node *curr = list->head->next;
    for (; curr->next != NULL; curr = curr->next, prev = prev->next);

    *result = curr->value;
    free(curr);
    prev->next = NULL;
    list->size--;

    return 0;
}

int value_n_from_end(LinkedLists *list, int n, int *result) {
    if (list->size == 0 || n < 0 || n >= list->size)
        return -1;

    Node *front = list->head;
    Node *end = list->head;

    for (int i = 0; i < n; i++)
        end = end->next;

    while (end != NULL) {
        front = front->next;
        end = end->next;
    }

    *result = front->value;

    return 0;
}

int insert(LinkedLists *list, int index, int value) {
    if (index < 0 || index > list->size)
        return -1;

    if (list->size == 0) {
        push_front(list, value);
        return 0;
    }

    Node *pNewNode = make_node(value);
    Node *temp = list->head;

    for (int i = 0; i < index-1; i++) {
        temp = temp->next;
    }
    
    pNewNode->next = temp->next;
    temp->next = pNewNode;
    list->size++;

    return 0;
}

void remove_value(LinkedLists *list, int value) {
    if (list->size == 0)
        return;

    if (list->size == 1) {
        if (list->head->value == value) {
            free(list->head);
            list->head = NULL;
            list->size--;
        }
        return;
    }

    Node *prev = list->head;
    Node *curr = list->head->next;

    while (curr != NULL) {
        if (curr->value == value) {
            prev->next = curr->next;
            free(curr);
            list->size--;
            return;
        }

        prev = curr;
        curr = curr->next;
    }
}

void reverse(LinkedLists *list) {
    if (list->size <= 1)
        return;

    Node *last = list->head;
    while (last->next != NULL)
        last = last->next;

    Node *temp = list->head;
    Node *next = NULL;
    for (int i = 0; i < list->size-1; i++) {
        next = temp->next;
        temp->next = last->next;
        last->next = temp;
        temp = next;
    }

    list->head = last;
}

void delete_node(LinkedLists *list, int index) {
    if (index > list->size-1 || index < 0)
        return;
    
    Node **lpp = &(list->head);
    for (int i = 0; i < index; i++) {
        lpp = &((*lpp)->next);
    }

    Node *pDelNode = *lpp;
    *lpp = (*lpp)->next;
    free(pDelNode);
    list->size--;
}

void print_list(LinkedLists *list) {
    printf("--- Linked lists ---\n");
    for (Node *temp = list->head; temp != NULL; temp = temp->next) {
        printf("%d", temp->value);
        if (temp->next != NULL)
            printf(" | ");
    }
    printf("\n");
}

void destroy_list(LinkedLists *list) {
    Node *temp = list->head;
    while (temp != NULL) {
        Node *pDelNode = temp;
        temp = temp->next;
        free(pDelNode);
    }

    free(list);
}

void allocateMemoryError(void) {
    fprintf(stderr, "allocate memory error");
    exit(1);
}