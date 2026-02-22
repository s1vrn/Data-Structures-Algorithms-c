/*
 * bst.c — Binary Search Tree (Implementation)
 */

#include "bst.h"

#include <stdio.h>
#include <stdlib.h>

/* ── Helpers ─────────────────────────────────────────────────────────── */

static BSTNode *bst_create_node(int data)
{
    BSTNode *node = (BSTNode *)malloc(sizeof(BSTNode));
    if (!node) {
        fprintf(stderr, "Error: malloc failed in bst_create_node\n");
        return NULL;
    }
    node->data  = data;
    node->left  = NULL;
    node->right = NULL;
    return node;
}

/* ── Insert ──────────────────────────────────────────────────────────── */

BSTNode *bst_insert(BSTNode *root, int data)
{
    if (!root)
        return bst_create_node(data);

    if (data < root->data)
        root->left = bst_insert(root->left, data);
    else if (data > root->data)
        root->right = bst_insert(root->right, data);
    /* duplicate: do nothing */

    return root;
}

/* ── Search ──────────────────────────────────────────────────────────── */

BSTNode *bst_search(BSTNode *root, int data)
{
    if (!root || root->data == data)
        return root;

    if (data < root->data)
        return bst_search(root->left, data);

    return bst_search(root->right, data);
}

/* ── Delete ──────────────────────────────────────────────────────────── */

BSTNode *bst_delete(BSTNode *root, int data)
{
    if (!root) return NULL;

    if (data < root->data) {
        root->left = bst_delete(root->left, data);
    } else if (data > root->data) {
        root->right = bst_delete(root->right, data);
    } else {
        /* Node found */

        /* Case 1: No child or one child */
        if (!root->left) {
            BSTNode *tmp = root->right;
            free(root);
            return tmp;
        }
        if (!root->right) {
            BSTNode *tmp = root->left;
            free(root);
            return tmp;
        }

        /* Case 2: Two children — replace with in-order successor */
        BSTNode *successor = bst_min(root->right);
        root->data  = successor->data;
        root->right = bst_delete(root->right, successor->data);
    }

    return root;
}

/* ── Min / Max ───────────────────────────────────────────────────────── */

BSTNode *bst_min(BSTNode *root)
{
    if (!root) return NULL;
    while (root->left)
        root = root->left;
    return root;
}

BSTNode *bst_max(BSTNode *root)
{
    if (!root) return NULL;
    while (root->right)
        root = root->right;
    return root;
}

/* ── Traversals ──────────────────────────────────────────────────────── */

void bst_inorder(BSTNode *root)
{
    if (!root) return;
    bst_inorder(root->left);
    printf("%d ", root->data);
    bst_inorder(root->right);
}

void bst_preorder(BSTNode *root)
{
    if (!root) return;
    printf("%d ", root->data);
    bst_preorder(root->left);
    bst_preorder(root->right);
}

void bst_postorder(BSTNode *root)
{
    if (!root) return;
    bst_postorder(root->left);
    bst_postorder(root->right);
    printf("%d ", root->data);
}

/* ── Utilities ───────────────────────────────────────────────────────── */

int bst_height(BSTNode *root)
{
    if (!root) return -1;

    int lh = bst_height(root->left);
    int rh = bst_height(root->right);
    return 1 + (lh > rh ? lh : rh);
}

size_t bst_size(BSTNode *root)
{
    if (!root) return 0;
    return 1 + bst_size(root->left) + bst_size(root->right);
}

BSTNode *bst_free(BSTNode *root)
{
    if (!root) return NULL;
    bst_free(root->left);
    bst_free(root->right);
    free(root);
    return NULL;
}
