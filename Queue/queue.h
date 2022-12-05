/**
* @file queue.h
* @brief this header file will contain all required
* definitions and basic utilities functions.
*
* @author Nidhal Abidi
*
* @date 2022
*/

#ifndef __QUEUE_H__
#define __QUEUE_H__

/*-------------------------------------------------------------------------------------------*/
// Includes

#include <stdbool.h>

/*-------------------------------------------------------------------------------------------*/
// Exported variables declarations

/**
 * @brief Error code used to handle queue is empty.
 */
#define QUEUE_IS_EMPTY 1

/**
 * @brief Error code used to handle queue is full.
 */
#define QUEUE_IS_FULL 2

/**
 * @struct queue
 * @brief This structure contains queue elements.
 */
struct queue {
    unsigned int tail;          /**< tail Current tail */
    unsigned int head;          /**< Current head */
    unsigned int size;          /**< size current number of items */
    unsigned int capacity;      /**< capacity Capacity of queue */
    int data[QUEUE_CAPACITY];   /**< Array of data */
};

typedef struct queue queue_t;

/*-------------------------------------------------------------------------------------------*/
// Exported functions declarations

/**
 * @fn void init(queue_t* q)
 * @brief Initialize queue.
 * @param[in] q : pointer to circular queue (queue_t*)
 */
void init(queue_t* q);

/**
 * @fn int enqueue(queue_t* q, int val)
 * @brief Enqueue item into circular queue.
 * @param[in] q   : pointer to circular queue (queue_t*)
 * @param[in] val : integer to be added to queue
 * @return  QUEUE_IS_FULL if q is full \n
 *          0 otherwise
 */
int enqueue(queue_t* q, int val);

/**
 * @fn int dequeue(queue_t* q, int* val)
 * @brief Dequeue item from circular queue.
 * @param[in] q   : pointer to circular queue (queue_t*)
 * @param[out] val : integer to be removed from queue
 * @return  QUEUE_IS_EMPTY if q is NULL \n
 *          0 otherwise
 */
int dequeue(queue_t* q, int* val);

/**
 * @fn bool is_empty(queue_t* q)
 * @brief Determine if queue is empty.
 * @param[in] q   : pointer to circular queue (queue_t*)
 * @return  true if QUEUE_IS_EMPTY \n
 *          false otherwise
 */
bool is_empty(queue_t* q);

/**
 * @fn bool is_empty(queue_t* q)
 * @brief Determine if queue is full.
 * @param[in] q   : pointer to circular queue (queue_t*)
 * @return  true if QUEUE_IS_FULL \n
 *          false otherwise
 */
bool is_full(queue_t* q);

#endif // __QUEUE_H__
