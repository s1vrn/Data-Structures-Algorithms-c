/*
 * linked_list.c — Singly Linked List (Implementation)
 */

#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

/* ── Helpers ─────────────────────────────────────────────────────────── */

Node *node_create(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) {
        fprintf(stderr, "Error: malloc failed in node_create\n");
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/* ── Insertion ───────────────────────────────────────────────────────── */

Node *insert_head(Node *head, int data)
{
    Node *new_node = node_create(data);
    if (!new_node) return head;

    new_node->next = head;
    return new_node;
}

Node *insert_tail(Node *head, int data)
{
    Node *new_node = node_create(data);
    if (!new_node) return head;

    if (!head) return new_node;

    Node *curr = head;
    while (curr->next)
        curr = curr->next;

    curr->next = new_node;
    return head;
}

Node *insert_at(Node *head, int data, size_t pos)
{
    if (pos == 0)
        return insert_head(head, data);

    Node *new_node = node_create(data);
    if (!new_node) return head;

    Node  *curr = head;
    size_t i    = 0;

    while (curr->next && i < pos - 1) {
        curr = curr->next;
        i++;
    }

    new_node->next = curr->next;
    curr->next     = new_node;
    return head;
}

/* ── Deletion ────────────────────────────────────────────────────────── */

Node *delete_node(Node *head, int data)
{
    if (!head) return NULL;

    /* Head node matches */
    if (head->data == data) {
        Node *new_head = head->next;
        free(head);
        return new_head;
    }

    Node *curr = head;
    while (curr->next && curr->next->data != data)
        curr = curr->next;

    if (curr->next) {
        Node *to_free = curr->next;
        curr->next = to_free->next;
        free(to_free);
    }

    return head;
}

/* ── Search ──────────────────────────────────────────────────────────── */

Node *search(Node *head, int data)
{
    Node *curr = head;
    while (curr) {
        if (curr->data == data)
            return curr;
        curr = curr->next;
    }
    return NULL;
}

/* ── Utilities ───────────────────────────────────────────────────────── */

size_t list_length(Node *head)
{
    size_t len  = 0;
    Node  *curr = head;
    while (curr) {
        len++;
        curr = curr->next;
    }
    return len;
}

void display(Node *head)
{
    printf("[");
    Node *curr = head;
    while (curr) {
        printf("%d", curr->data);
        if (curr->next)
            printf(" -> ");
        curr = curr->next;
    }
    printf(" -> NULL]\n");
}

Node *free_list(Node *head)
{
    Node *curr = head;
    while (curr) {
        Node *tmp = curr;
        curr = curr->next;
        free(tmp);
    }
    return NULL;
}
