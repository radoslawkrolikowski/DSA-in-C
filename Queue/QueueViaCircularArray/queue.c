#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

Queue* make_queue(int capacity) {
    Queue *pQueue = malloc(sizeof(Queue));
    if (pQueue == NULL)
        allocateMemoryError();

    int *pArray = malloc(capacity * sizeof(int));
    if (pArray == NULL)
        allocateMemoryError();

    pQueue->array = pArray;
    pQueue->read = 0;
    pQueue->write = 0;
    pQueue->size = 0;
    pQueue->capacity = capacity;

    return pQueue;
}

void enqueue(Queue *queue, int value) {
    if (queue->size == queue->capacity) {
        queue->read++;
        queue->size--;
    }

    *(queue->array + queue->write) = value;
    queue->write++;

    if (queue->write == queue->capacity)
        queue->write = 0;       
    
    queue->size++;
}

int dequeue(Queue *queue, int *result) {
    if (queue->size == 0)
        return -1;

    if (queue->read == queue->capacity)
        queue->read = 0;

    *result = *(queue->array + queue->read);
    queue->read++;
    queue->size--;

    return 0;
}

void destroy_queue(Queue *queue) {
    free(queue->array);
    free(queue);
}

bool empty(Queue *queue) {
    return queue->size == 0;
}

void allocateMemoryError(void) {
    fprintf(stderr, "allocate memory error");
    exit(1);
}