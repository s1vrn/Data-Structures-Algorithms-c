# Singly Linked List

A **singly linked list** is a linear data structure where each element (node) contains a value and a pointer to the next node. Unlike arrays, linked lists do not require contiguous memory and allow efficient insertions and deletions.

## Operations

| Operation | Time Complexity | Space Complexity |
|------------------|:--------------:|:----------------:|
| Insert at head   | O(1)           | O(1)             |
| Insert at tail   | O(n)           | O(1)             |
| Insert at index  | O(n)           | O(1)             |
| Delete by value  | O(n)           | O(1)             |
| Search           | O(n)           | O(1)             |
| Display / Length  | O(n)           | O(1)             |

## API

```c
Node *insert_head(Node *head, int data);
Node *insert_tail(Node *head, int data);
Node *insert_at(Node *head, int data, size_t pos);
Node *delete_node(Node *head, int data);
Node *search(Node *head, int data);
size_t list_length(Node *head);
void   display(Node *head);
Node  *free_list(Node *head);
```

## Use Cases

- Implementing **stacks** and **queues**.
- Building **adjacency lists** for graph representations.
- **Dynamic memory** scenarios where the size is unknown at compile time.
- **Undo** functionality in text editors (each state is a node).

## Build & Run

```bash
# From project root
make linked_list
./linked_list/linked_list_test
```
