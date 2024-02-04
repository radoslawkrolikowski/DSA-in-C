#include "queue.h"
#include <stdio.h>

int main(void) {
    Queue *queue = make_queue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    int result = -1;

    dequeue(queue, &result);
    printf("Dequeue value: %d\n", result);
    dequeue(queue, &result);
    printf("Dequeue value: %d\n", result);

    destroy_queue(queue);

    return 0;
}