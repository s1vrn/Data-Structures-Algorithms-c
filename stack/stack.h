/*
 * stack.h — Stack (Array-Based, Declarations)
 *
 * A fixed-capacity integer stack implemented with a dynamic array.
 */

#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stddef.h>

/* ── Stack Definition ────────────────────────────────────────────────── */

typedef struct {
    int   *data;
    size_t top;
    size_t capacity;
} Stack;

/* ── Function Declarations ───────────────────────────────────────────── */

/**
 * Allocate and initialise a stack with the given capacity.
 * Returns NULL on allocation failure.
 */
Stack *stack_create(size_t capacity);

/**
 * Push a value onto the stack.
 * Returns false if the stack is full.
 */
bool stack_push(Stack *s, int value);

/**
 * Pop the top value off the stack and store it in *out.
 * Returns false if the stack is empty.
 */
bool stack_pop(Stack *s, int *out);

/**
 * Peek at the top value without removing it.
 * Returns false if the stack is empty.
 */
bool stack_peek(const Stack *s, int *out);

/**
 * Returns true if the stack contains no elements.
 */
bool stack_is_empty(const Stack *s);

/**
 * Returns true if the stack is at full capacity.
 */
bool stack_is_full(const Stack *s);

/**
 * Return the current number of elements.
 */
size_t stack_size(const Stack *s);

/**
 * Print the stack contents from top to bottom.
 */
void stack_display(const Stack *s);

/**
 * Free all memory associated with the stack.
 */
void stack_destroy(Stack *s);

#endif /* STACK_H */
