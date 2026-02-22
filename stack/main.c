/*
 * main.c — Stack Test Driver
 */

#include "stack.h"
#include <stdio.h>
#include <assert.h>

int main(void)
{
    printf("=== Stack Tests ===\n\n");

    Stack *s = stack_create(5);
    assert(s != NULL);
    assert(stack_is_empty(s));

    /* ── Push ────────────────────────────────────────────────────────── */
    printf("--- Push: 10, 20, 30, 40, 50 ---\n");
    assert(stack_push(s, 10));
    assert(stack_push(s, 20));
    assert(stack_push(s, 30));
    assert(stack_push(s, 40));
    assert(stack_push(s, 50));
    stack_display(s);                       /* [50, 40, 30, 20, 10] */
    assert(stack_size(s) == 5);
    assert(stack_is_full(s));

    /* Push on full stack should fail */
    assert(!stack_push(s, 60));

    /* ── Peek ────────────────────────────────────────────────────────── */
    int val;
    printf("\n--- Peek ---\n");
    assert(stack_peek(s, &val));
    printf("Top: %d\n", val);
    assert(val == 50);

    /* ── Pop ─────────────────────────────────────────────────────────── */
    printf("\n--- Pop two elements ---\n");
    assert(stack_pop(s, &val));
    printf("Popped: %d\n", val);
    assert(val == 50);

    assert(stack_pop(s, &val));
    printf("Popped: %d\n", val);
    assert(val == 40);

    stack_display(s);                       /* [30, 20, 10] */
    assert(stack_size(s) == 3);

    /* ── Pop until empty ─────────────────────────────────────────────── */
    printf("\n--- Pop remaining ---\n");
    while (stack_pop(s, &val))
        printf("Popped: %d\n", val);

    assert(stack_is_empty(s));
    assert(!stack_pop(s, &val));            /* Pop on empty should fail */

    /* ── Cleanup ─────────────────────────────────────────────────────── */
    stack_destroy(s);

    printf("\n✅ All stack tests passed!\n");
    return 0;
}
