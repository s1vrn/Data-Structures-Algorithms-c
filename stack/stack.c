/*
 * stack.c — Stack (Array-Based, Implementation)
 */

#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

/* ── Create / Destroy ────────────────────────────────────────────────── */

Stack *stack_create(size_t capacity)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if (!s) {
        fprintf(stderr, "Error: malloc failed in stack_create\n");
        return NULL;
    }

    s->data = (int *)malloc(sizeof(int) * capacity);
    if (!s->data) {
        fprintf(stderr, "Error: malloc failed for stack data\n");
        free(s);
        return NULL;
    }

    s->top      = 0;
    s->capacity = capacity;
    return s;
}

void stack_destroy(Stack *s)
{
    if (s) {
        free(s->data);
        free(s);
    }
}

/* ── Push / Pop / Peek ───────────────────────────────────────────────── */

bool stack_push(Stack *s, int value)
{
    if (stack_is_full(s))
        return false;

    s->data[s->top++] = value;
    return true;
}

bool stack_pop(Stack *s, int *out)
{
    if (stack_is_empty(s))
        return false;

    *out = s->data[--s->top];
    return true;
}

bool stack_peek(const Stack *s, int *out)
{
    if (stack_is_empty(s))
        return false;

    *out = s->data[s->top - 1];
    return true;
}

/* ── Queries ─────────────────────────────────────────────────────────── */

bool stack_is_empty(const Stack *s)
{
    return s->top == 0;
}

bool stack_is_full(const Stack *s)
{
    return s->top == s->capacity;
}

size_t stack_size(const Stack *s)
{
    return s->top;
}

/* ── Display ─────────────────────────────────────────────────────────── */

void stack_display(const Stack *s)
{
    printf("Stack (top -> bottom): [");
    for (size_t i = s->top; i > 0; i--) {
        printf("%d", s->data[i - 1]);
        if (i > 1)
            printf(", ");
    }
    printf("]\n");
}
