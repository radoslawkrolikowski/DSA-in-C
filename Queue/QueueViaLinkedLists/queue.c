#include "queue.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

static Node* make_node(int value) {
    Node *pNode = malloc(sizeof(Node));
    if (pNode == NULL)
        allocateMemoryError();

    pNode->next = NULL;
    pNode->value = value;

    return pNode;
}

Queue* make_queue(void) {
    Queue *pQueue = malloc(sizeof(Queue));
    if (pQueue == NULL)
        allocateMemoryError();

    pQueue->size = 0;
    pQueue->head = NULL;
    pQueue->tail = NULL;

    return pQueue;
}

bool empty(Queue *queue) {
    return queue->size == 0;
}

void enqueue(Queue *queue, int value) {
    Node *node = make_node(value);
    
    if (queue->size == 0) {
        queue->head = node;
        queue->tail = node;
    } else {
        queue->tail->next = node;
        queue->tail = node;
    }

    queue->size++;
}

int dequeue(Queue *queue, int *result) {
    if (queue->size == 0)
        return -1;

    *result = queue->head->value;

    if (queue->size == 1) {
        free(queue->head);
        queue->head = NULL;
        queue->tail = NULL;

    } else {
        Node *pDelNode = queue->head;
        queue->head = queue->head->next;
        free(pDelNode);
    }

    queue->size--;

    return 0;
}

void destroy_queue(Queue *queue) {
    Node *temp = queue->head;
    while (temp != NULL) {
        Node *pDelNode = temp;
        temp = temp->next;
        free(pDelNode);
    }

    free(queue);
}

void allocateMemoryError(void) {
    fprintf(stderr, "allocate memory error");
    exit(1);
}
