/*
 * linked_list.h — Singly Linked List (Declarations)
 *
 * A generic integer singly linked list with insert, delete,
 * search, and traversal operations.
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

/* ── Node Definition ─────────────────────────────────────────────────── */

typedef struct Node {
    int          data;
    struct Node *next;
} Node;

/* ── Function Declarations ───────────────────────────────────────────── */

/**
 * Create a new node with the given data.
 * Returns NULL on allocation failure.
 */
Node *node_create(int data);

/**
 * Insert a new node at the head of the list.
 * Returns the new head pointer.
 */
Node *insert_head(Node *head, int data);

/**
 * Insert a new node at the tail of the list.
 * Returns the head pointer (unchanged unless list was empty).
 */
Node *insert_tail(Node *head, int data);

/**
 * Insert a new node at the given 0-based position.
 * If pos > length, the node is appended at the tail.
 * Returns the (possibly new) head pointer.
 */
Node *insert_at(Node *head, int data, size_t pos);

/**
 * Delete the first node that matches `data`.
 * Returns the (possibly new) head pointer.
 */
Node *delete_node(Node *head, int data);

/**
 * Search for the first node containing `data`.
 * Returns a pointer to the node, or NULL if not found.
 */
Node *search(Node *head, int data);

/**
 * Return the number of nodes in the list.
 */
size_t list_length(Node *head);

/**
 * Print all node values: [10 -> 20 -> 30 -> NULL]
 */
void display(Node *head);

/**
 * Free every node in the list and return NULL.
 */
Node *free_list(Node *head);

#endif /* LINKED_LIST_H */
