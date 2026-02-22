/*
 * queue.h — Queue (Linked-List-Based, Declarations)
 *
 * A FIFO integer queue backed by a singly linked list,
 * providing O(1) enqueue and dequeue.
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stddef.h>

/* ── Internal Node ───────────────────────────────────────────────────── */

typedef struct QNode {
    int           data;
    struct QNode *next;
} QNode;

/* ── Queue Definition ────────────────────────────────────────────────── */

typedef struct {
    QNode *front;
    QNode *rear;
    size_t size;
} Queue;

/* ── Function Declarations ───────────────────────────────────────────── */

/**
 * Create and return a new empty queue.
 * Returns NULL on allocation failure.
 */
Queue *queue_create(void);

/**
 * Add a value to the rear of the queue.
 * Returns false on allocation failure.
 */
bool queue_enqueue(Queue *q, int value);

/**
 * Remove the front value and store it in *out.
 * Returns false if the queue is empty.
 */
bool queue_dequeue(Queue *q, int *out);

/**
 * Peek at the front value without removing it.
 * Returns false if the queue is empty.
 */
bool queue_peek(const Queue *q, int *out);

/**
 * Returns true if the queue has no elements.
 */
bool queue_is_empty(const Queue *q);

/**
 * Return the number of elements in the queue.
 */
size_t queue_size(const Queue *q);

/**
 * Print the queue from front to rear.
 */
void queue_display(const Queue *q);

/**
 * Free all memory associated with the queue.
 */
void queue_destroy(Queue *q);

#endif /* QUEUE_H */
