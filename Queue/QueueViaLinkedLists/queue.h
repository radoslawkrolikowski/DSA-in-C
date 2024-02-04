#ifndef QUEUE_LINKED_LISTS_TYPE_
#define QUEUE_LINKED_LISTS_TYPE_

#include <stdbool.h>

typedef struct Node {
    struct Node *next;
    int value;
} Node;

typedef struct Queue {
    Node *head;
    Node *tail;
    int size;
} Queue;

// make_node creates a new Node with a value, allocates the memory 
// for the node and returns the pointer
static Node* make_node(int value);

// make_queue creates an empty Queue, allocate the memory
// and returns the pointer
Queue* make_queue(void);

// empty function returns true if queue is empty, otherwise false
bool empty(Queue *queue);

// enqueue function adds the item to the queue (at the tail of linked list)
void enqueue(Queue *queue, int value);

// dequeue function writes the least recently added item (front) to a pointer
// result argument and returns 0; if queue is empty it returns -1
int dequeue(Queue *queue, int *result);

// destroy_queue function releases the memory for all the nodes
// and the Queue struct
void destroy_queue(Queue *queue);

// allocateMemoryError prints the error message and exits with code 1
void allocateMemoryError(void);

#endif // QUEUE_LINKED_LISTS_TYPE_