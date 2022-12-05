#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "queue.h"

// Fully fill and empty a Queue
void unit_test_1() {
    printf("\n******** Running test case 1 ********\n");

    int push_times = 0;
    int pop_times = 0;

    queue_t q1;

    // Initialize the queue
    init(&q1);

    srand(time(NULL));

    // Fill the queue
    for (int i = 0; i < QUEUE_CAPACITY; i++)
    {
        int randValue = rand();

        printf("Push %d\n", randValue);

        int ret = enqueue(&q1, randValue);

        if (ret == QUEUE_IS_FULL)
        {
            break;
        }
    }

    // Ensure queue is full
    if (!is_full(&q1))
    {
        printf(".............. enqueue()  :: NOK\n");
        printf(".............. is_full()  :: NOK\n");
    }

    // Empty the queue
    for (int i = 0; i < QUEUE_CAPACITY; i++)
    {
        int val;
        int ret = dequeue(&q1, &val);

        if (ret == QUEUE_IS_EMPTY)
        {
            break;
        }

        printf("Pop  %d\n", val);
    }

    // Ensure queue is empty
    if (!is_empty(&q1))
    {
        printf(".............. dequeue()  :: NOK\n");
        printf(".............. is_empty() :: NOK\n");
    }

    if ((push_times - pop_times) == q1.size)
    {
        printf(".............. Test case 1  :: OK\n");
    }
    else
    {
        printf(".............. Test case 1  :: NOK\n");
    }
}

// Push three elements and pop one
void unit_test_2() {
    printf("\n******** Running test case 2 ********\n");

    int push_times = 0;
    int pop_times = 0;

    queue_t q2;

    srand(time(NULL));

    // Initialize the queue
    init(&q2);

    // Push and pop multiple times
    for (int i = 0; i < (QUEUE_CAPACITY/2); i++)
    {

        // Push two elements to the queue
        for (int j = 0; j < 2; j++)
        {
            push_times++;

            int randValue = rand();

            printf("Push %d\n", randValue);

            int ret = enqueue(&q2, randValue);

            if (ret == QUEUE_IS_FULL)
            {
                break;
            }
        }

        // Ensure queue is not full
        if (is_full(&q2))
        {
            printf(".............. enqueue()  :: NOK\n");
            printf(".............. is_full()  :: NOK\n");
        }

        // Pop one from the queue
        pop_times++;

        int val;
        int ret = dequeue(&q2, &val);

        if (ret == QUEUE_IS_EMPTY)
        {
            break;
        }

        printf("Pop  %d\n", val);

        // Ensure queue is not empty
        if (is_empty(&q2))
        {
            printf(".............. dequeue()  :: NOK\n");
            printf(".............. is_empty() :: NOK\n");
        }
    }

    if ((push_times - pop_times) == q2.size)
    {
        printf(".............. Test case 2  :: OK\n");
    }
    else
    {
        printf(".............. Test case 2  :: NOK\n");
    }
}

int main(void)
{
    unit_test_1();
    unit_test_2();

    return 0;
}
