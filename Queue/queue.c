/*-------------------------------------------------------------------------------------------*/
// Includes

#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "queue.h"

/*-------------------------------------------------------------------------------------------*/
// Exported functions definition

void init(queue_t* q)
{
    assert(q != NULL);
    assert(q->data != NULL);

    // Initialize the queue variables
    q->tail = 0;
    q->head = 0;
    q->size = 0;
    q->capacity = QUEUE_CAPACITY;
    // Set the buffer to 0
    memset(q->data, 0, QUEUE_CAPACITY*sizeof(q->data[0]));
}

int enqueue(queue_t* q, int val)
{
    if (is_full(q))
    {
        // Ensure queue is not full.
        return QUEUE_IS_FULL;
    }

    // Insert the value
    q->data[q->tail] = val;

    q->tail++;

    if (q->tail >= q->capacity)
    {
        q->tail = 0;
    }

    // Increase size by 1
    q->size++;

    return 0;
}

int dequeue(queue_t* q, int* val)
{
    if (is_empty(q))
    {
        // Ensure queue is not empty.
        return QUEUE_IS_EMPTY;
    }

    // Capture the value
    *val = q->data[q->head];

    q->head++;

    if (q->head >= q->capacity)
    {
        q->head = 0;
    }

    // Decrease size by 1
    q->size--;

    return 0;
}

bool is_empty(queue_t* q)
{
    if(q->size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_full(queue_t* q)
{
    if(q->size == q->capacity)
    {
        return true;
    }
    else
    {
        return false;
    }
}
