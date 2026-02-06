/** 
 * ===========================================================
 * Name: C3C Colby Ting
 * Section: T1A
 * Project: Queue ADT implemented with C array
 * ===========================================================
 */
#include "queueAsArray.h"

#include <stdio.h>
#include <stdlib.h>

/** enqueue() - adds an element to the back of the queue
 * @param queue - a ptr to the queue structure
 * @param element - the item to add to the queue
 * @return 1 on success, -1 on failure
 */
int enqueue(QueueAsArray* queue, int element) {
       if (queue == NULL) {
        return -1; 
    }

    // Check if queue is full
    if ((queue->back + 1) % QUEUE_MAX_SIZE == queue->front) {
        return -1; 
    }
    if(queueIsEmpty(queue)) {
            queue->front = 0;
        }

    int new_index = (queue->back + 1) % QUEUE_MAX_SIZE;
    queue->number[new_index] = element;
    queue->back = new_index;
    queue->size++;
    return 1;
}

/** dequeue() - removes an element from the front of the queue
 * @param queue - a ptr to the queue structure
 * @return - the top of the queue on success, -1 on failure
 */
int dequeue(QueueAsArray* queue) {
    int value = queue->number[queue->front];
    queue->front = (queue->front + 1) % QUEUE_MAX_SIZE;
    queue->size--;

    return value;
}

/** queueIsEmpty() - determines if the queue is empty
 * @param queue - a ptr to the queue structure
 * @return - true if the queue is empty or false
 */
bool queueIsEmpty(QueueAsArray* queue) {
    if(queue->size == 0) {
        return true;
    }
    return false;
}

/** queueIsFull() - determines if the queue is full
 * @param queue - a ptr to the queue structure
 * @return - true if the queue is full or false
 */
bool queueIsFull(QueueAsArray* queue) {
    if(queue->size == QUEUE_MAX_SIZE) {
        return true;
    }
    return false;
}

/** queueInit() - initializes the queue structure
 * @param queue - a ptr to the queue structure
 */
void queueInit(QueueAsArray* queue) {
    queue->front = -1;
    queue->back = -1;
    queue->size = 0;
    
}

/** queuePeek() - returns the item on the front of the
 * queue but doesn't remove it
 * @param queue - a ptr to the queue structure
 * @return - the item at the front of the queue or -1 on failure
 */
int queuePeek(QueueAsArray* queue) {
    return queue->number[queue->front];
}

/** queueSize() - determines the size of the queue
 * @param queue - a ptr to the queue structure
 * @return - number of items in the queue
 */
int queueSize(QueueAsArray* queue) {
    return queue->size;
}

/** queuePrint() - outputs the queue to the console
 * @param queue - ptr to the queue structure
 */
void queuePrint(QueueAsArray* queue) {
    printf("Queue: ");
    for(int i = 0; i < queue->size; i++) {
        int index = (queue->front + i) % QUEUE_MAX_SIZE;
        printf("%d ", queue->number[index]);
    }
    printf("\n");
    
}