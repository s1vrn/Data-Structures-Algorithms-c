/*
 * main.c — Binary Search Tree Test Driver
 */

#include "bst.h"
#include <stdio.h>
#include <assert.h>

int main(void)
{
    printf("=== Binary Search Tree Tests ===\n\n");

    BSTNode *root = NULL;

    /* ── Insert ──────────────────────────────────────────────────────── */
    printf("--- Insert: 50, 30, 70, 20, 40, 60, 80 ---\n");
    root = bst_insert(root, 50);
    root = bst_insert(root, 30);
    root = bst_insert(root, 70);
    root = bst_insert(root, 20);
    root = bst_insert(root, 40);
    root = bst_insert(root, 60);
    root = bst_insert(root, 80);

    printf("In-order:   ");
    bst_inorder(root);          /* 20 30 40 50 60 70 80 */
    printf("\n");

    printf("Pre-order:  ");
    bst_preorder(root);         /* 50 30 20 40 70 60 80 */
    printf("\n");

    printf("Post-order: ");
    bst_postorder(root);        /* 20 40 30 60 80 70 50 */
    printf("\n");

    assert(bst_size(root) == 7);
    assert(bst_height(root) == 2);

    /* ── Search ──────────────────────────────────────────────────────── */
    printf("\n--- Search for 40 ---\n");
    BSTNode *found = bst_search(root, 40);
    printf("%s\n", found ? "Found" : "Not found");
    assert(found != NULL && found->data == 40);

    printf("--- Search for 99 (not in tree) ---\n");
    found = bst_search(root, 99);
    printf("%s\n", found ? "Found" : "Not found");
    assert(found == NULL);

    /* ── Min / Max ───────────────────────────────────────────────────── */
    printf("\n--- Min / Max ---\n");
    printf("Min: %d\n", bst_min(root)->data);
    printf("Max: %d\n", bst_max(root)->data);
    assert(bst_min(root)->data == 20);
    assert(bst_max(root)->data == 80);

    /* ── Delete ──────────────────────────────────────────────────────── */
    printf("\n--- Delete leaf (20) ---\n");
    root = bst_delete(root, 20);
    printf("In-order: ");
    bst_inorder(root);
    printf("\n");
    assert(bst_size(root) == 6);

    printf("\n--- Delete node with one child (30) ---\n");
    root = bst_delete(root, 30);
    printf("In-order: ");
    bst_inorder(root);
    printf("\n");
    assert(bst_size(root) == 5);

    printf("\n--- Delete node with two children (50, root) ---\n");
    root = bst_delete(root, 50);
    printf("In-order: ");
    bst_inorder(root);
    printf("\n");
    assert(bst_size(root) == 4);

    /* ── Cleanup ─────────────────────────────────────────────────────── */
    root = bst_free(root);
    assert(root == NULL);

    printf("\n✅ All BST tests passed!\n");
    return 0;
}
