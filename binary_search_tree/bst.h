/*
 * bst.h — Binary Search Tree (Declarations)
 *
 * An integer BST supporting insert, search, delete,
 * and in-order traversal.
 */

#ifndef BST_H
#define BST_H

#include <stdbool.h>
#include <stddef.h>

/* ── Node Definition ─────────────────────────────────────────────────── */

typedef struct BSTNode {
    int             data;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

/* ── Function Declarations ───────────────────────────────────────────── */

/**
 * Insert a value into the BST. Duplicates are ignored.
 * Returns the (possibly new) root.
 */
BSTNode *bst_insert(BSTNode *root, int data);

/**
 * Search for a value in the BST.
 * Returns a pointer to the node, or NULL if not found.
 */
BSTNode *bst_search(BSTNode *root, int data);

/**
 * Delete a value from the BST.
 * Returns the (possibly new) root.
 */
BSTNode *bst_delete(BSTNode *root, int data);

/**
 * Find the minimum value node in the BST.
 */
BSTNode *bst_min(BSTNode *root);

/**
 * Find the maximum value node in the BST.
 */
BSTNode *bst_max(BSTNode *root);

/**
 * Print the BST values via in-order traversal (sorted order).
 */
void bst_inorder(BSTNode *root);

/**
 * Print the BST values via pre-order traversal.
 */
void bst_preorder(BSTNode *root);

/**
 * Print the BST values via post-order traversal.
 */
void bst_postorder(BSTNode *root);

/**
 * Return the height of the BST.
 */
int bst_height(BSTNode *root);

/**
 * Return the number of nodes in the BST.
 */
size_t bst_size(BSTNode *root);

/**
 * Free all nodes in the BST and return NULL.
 */
BSTNode *bst_free(BSTNode *root);

#endif /* BST_H */
