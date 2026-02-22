# Binary Search Tree

A **binary search tree (BST)** is a hierarchical data structure where each node has at most two children, and for every node, all values in the left subtree are smaller and all values in the right subtree are larger.

## Operations

| Operation           | Average | Worst (Skewed) |
|---------------------|:-------:|:--------------:|
| Insert              | O(log n)| O(n)           |
| Search              | O(log n)| O(n)           |
| Delete              | O(log n)| O(n)           |
| In-order Traversal  | O(n)    | O(n)           |
| Min / Max           | O(log n)| O(n)           |
| Height              | O(n)    | O(n)           |

Space: **O(n)**

## API

```c
BSTNode *bst_insert(BSTNode *root, int data);
BSTNode *bst_search(BSTNode *root, int data);
BSTNode *bst_delete(BSTNode *root, int data);
BSTNode *bst_min(BSTNode *root);
BSTNode *bst_max(BSTNode *root);
void     bst_inorder(BSTNode *root);
void     bst_preorder(BSTNode *root);
void     bst_postorder(BSTNode *root);
int      bst_height(BSTNode *root);
size_t   bst_size(BSTNode *root);
BSTNode *bst_free(BSTNode *root);
```

## Use Cases

- **Dictionaries** and **symbol tables**.
- **Database indexing** (B-trees are generalisations of BSTs).
- **Auto-complete** and **spell-checking** systems.
- **Priority queues** (though heaps are typically preferred).

## Build & Run

```bash
make bst
./binary_search_tree/bst_test
```
