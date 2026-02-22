# Queue (Linked-List-Based)

A **queue** is a First-In-First-Out (FIFO) data structure. This implementation uses a singly linked list with front and rear pointers for O(1) enqueue and dequeue.

## Operations

| Operation | Time Complexity | Space Complexity |
|-----------|:--------------:|:----------------:|
| Enqueue   | O(1)           | O(1)             |
| Dequeue   | O(1)           | O(1)             |
| Peek      | O(1)           | O(1)             |
| is_empty  | O(1)           | O(1)             |

Overall space: **O(n)** where n = number of elements.

## API

```c
Queue *queue_create(void);
bool   queue_enqueue(Queue *q, int value);
bool   queue_dequeue(Queue *q, int *out);
bool   queue_peek(const Queue *q, int *out);
bool   queue_is_empty(const Queue *q);
size_t queue_size(const Queue *q);
void   queue_display(const Queue *q);
void   queue_destroy(Queue *q);
```

## Use Cases

- **Breadth-First Search (BFS)** in graph traversal.
- **Task scheduling** (CPU scheduling, print queues).
- **Message buffers** in producer-consumer patterns.
- **Level-order traversal** of trees.

## Build & Run

```bash
make queue
./queue/queue_test
```
