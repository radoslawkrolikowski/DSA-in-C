#ifndef QUEUE_CIRCULAR_ARRAY_TYPE_
#define QUEUE_CIRCULAR_ARRAY_TYPE_

#include <stdbool.h>

typedef struct Queue {
    int read;
    int write;
    int size;
    int capacity;
    int *array;
} Queue;

// make_queue creates an empty Queue, allocate the memory
// of the size of capacity argument and returns the pointer
Queue* make_queue(int capacity);

// empty function returns true if queue is empty, otherwise false
bool empty(Queue *queue);

// enqueue function adds the element to the queue. If queue is at the
// full capacity, it will overwrite the least recently added element
void enqueue(Queue *queue, int value);

// dequeue function writes the least recently added item to a pointer
// result argument and returns 0; if queue is empty it returns -1
int dequeue(Queue *queue, int *result);

// destroy_queue function releases the memory for the underlying
// array and Queue struct
void destroy_queue(Queue *queue);

// allocateMemoryError prints the error message and exits with code 1
void allocateMemoryError(void);

#endif // QUEUE_CIRCULAR_ARRAY_TYPE_