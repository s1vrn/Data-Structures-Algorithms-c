/*
 * queue.c — Queue (Linked-List-Based, Implementation)
 */

#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

/* ── Create / Destroy ────────────────────────────────────────────────── */

Queue *queue_create(void)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (!q) {
        fprintf(stderr, "Error: malloc failed in queue_create\n");
        return NULL;
    }
    q->front = NULL;
    q->rear  = NULL;
    q->size  = 0;
    return q;
}

void queue_destroy(Queue *q)
{
    if (!q) return;

    QNode *curr = q->front;
    while (curr) {
        QNode *tmp = curr;
        curr = curr->next;
        free(tmp);
    }
    free(q);
}

/* ── Enqueue / Dequeue / Peek ────────────────────────────────────────── */

bool queue_enqueue(Queue *q, int value)
{
    QNode *node = (QNode *)malloc(sizeof(QNode));
    if (!node) {
        fprintf(stderr, "Error: malloc failed in queue_enqueue\n");
        return false;
    }

    node->data = value;
    node->next = NULL;

    if (q->rear)
        q->rear->next = node;
    else
        q->front = node;       /* first element */

    q->rear = node;
    q->size++;
    return true;
}

bool queue_dequeue(Queue *q, int *out)
{
    if (queue_is_empty(q))
        return false;

    QNode *node = q->front;
    *out = node->data;

    q->front = node->next;
    if (!q->front)
        q->rear = NULL;        /* queue is now empty */

    free(node);
    q->size--;
    return true;
}

bool queue_peek(const Queue *q, int *out)
{
    if (queue_is_empty(q))
        return false;

    *out = q->front->data;
    return true;
}

/* ── Queries ─────────────────────────────────────────────────────────── */

bool queue_is_empty(const Queue *q)
{
    return q->size == 0;
}

size_t queue_size(const Queue *q)
{
    return q->size;
}

/* ── Display ─────────────────────────────────────────────────────────── */

void queue_display(const Queue *q)
{
    printf("Queue (front -> rear): [");
    QNode *curr = q->front;
    while (curr) {
        printf("%d", curr->data);
        if (curr->next)
            printf(", ");
        curr = curr->next;
    }
    printf("]\n");
}
