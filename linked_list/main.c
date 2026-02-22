/*
 * main.c — Singly Linked List Test Driver
 *
 * Exercises all linked-list operations and prints results.
 */

#include "linked_list.h"
#include <stdio.h>
#include <assert.h>

int main(void)
{
    Node *list = NULL;

    printf("=== Singly Linked List Tests ===\n\n");

    /* ── Insert at head ──────────────────────────────────────────────── */
    printf("--- Insert at head: 10, 20, 30 ---\n");
    list = insert_head(list, 10);
    list = insert_head(list, 20);
    list = insert_head(list, 30);
    display(list);                          /* [30 -> 20 -> 10 -> NULL] */
    assert(list_length(list) == 3);

    /* ── Insert at tail ──────────────────────────────────────────────── */
    printf("\n--- Insert at tail: 5 ---\n");
    list = insert_tail(list, 5);
    display(list);                          /* [30 -> 20 -> 10 -> 5 -> NULL] */
    assert(list_length(list) == 4);

    /* ── Insert at position ──────────────────────────────────────────── */
    printf("\n--- Insert 99 at position 2 ---\n");
    list = insert_at(list, 99, 2);
    display(list);                          /* [30 -> 20 -> 99 -> 10 -> 5 -> NULL] */
    assert(list_length(list) == 5);

    /* ── Search ──────────────────────────────────────────────────────── */
    printf("\n--- Search for 99 ---\n");
    Node *found = search(list, 99);
    if (found)
        printf("Found: %d\n", found->data);
    else
        printf("Not found\n");
    assert(found != NULL && found->data == 99);

    printf("\n--- Search for 42 (not in list) ---\n");
    found = search(list, 42);
    printf("%s\n", found ? "Found" : "Not found");
    assert(found == NULL);

    /* ── Delete ──────────────────────────────────────────────────────── */
    printf("\n--- Delete 20 ---\n");
    list = delete_node(list, 20);
    display(list);                          /* [30 -> 99 -> 10 -> 5 -> NULL] */
    assert(list_length(list) == 4);

    printf("\n--- Delete head (30) ---\n");
    list = delete_node(list, 30);
    display(list);                          /* [99 -> 10 -> 5 -> NULL] */
    assert(list_length(list) == 3);

    printf("\n--- Delete tail (5) ---\n");
    list = delete_node(list, 5);
    display(list);                          /* [99 -> 10 -> NULL] */
    assert(list_length(list) == 2);

    /* ── Cleanup ─────────────────────────────────────────────────────── */
    list = free_list(list);
    assert(list == NULL);

    printf("\n✅ All linked list tests passed!\n");
    return 0;
}
