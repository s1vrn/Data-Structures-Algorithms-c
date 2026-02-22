/*
 * main.c — Queue Test Driver
 */

#include "queue.h"
#include <stdio.h>
#include <assert.h>

int main(void)
{
    printf("=== Queue Tests ===\n\n");

    Queue *q = queue_create();
    assert(q != NULL);
    assert(queue_is_empty(q));

    /* ── Enqueue ─────────────────────────────────────────────────────── */
    printf("--- Enqueue: 10, 20, 30, 40 ---\n");
    assert(queue_enqueue(q, 10));
    assert(queue_enqueue(q, 20));
    assert(queue_enqueue(q, 30));
    assert(queue_enqueue(q, 40));
    queue_display(q);                       /* [10, 20, 30, 40] */
    assert(queue_size(q) == 4);

    /* ── Peek ────────────────────────────────────────────────────────── */
    int val;
    printf("\n--- Peek ---\n");
    assert(queue_peek(q, &val));
    printf("Front: %d\n", val);
    assert(val == 10);

    /* ── Dequeue ─────────────────────────────────────────────────────── */
    printf("\n--- Dequeue two elements ---\n");
    assert(queue_dequeue(q, &val));
    printf("Dequeued: %d\n", val);
    assert(val == 10);

    assert(queue_dequeue(q, &val));
    printf("Dequeued: %d\n", val);
    assert(val == 20);

    queue_display(q);                       /* [30, 40] */
    assert(queue_size(q) == 2);

    /* ── Dequeue until empty ─────────────────────────────────────────── */
    printf("\n--- Dequeue remaining ---\n");
    while (queue_dequeue(q, &val))
        printf("Dequeued: %d\n", val);

    assert(queue_is_empty(q));
    assert(!queue_dequeue(q, &val));        /* Dequeue on empty should fail */

    /* ── Cleanup ─────────────────────────────────────────────────────── */
    queue_destroy(q);

    printf("\n✅ All queue tests passed!\n");
    return 0;
}
