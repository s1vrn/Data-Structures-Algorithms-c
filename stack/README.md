# Stack (Array-Based)

A **stack** is a Last-In-First-Out (LIFO) data structure. This implementation uses a fixed-capacity array.

## Operations

| Operation | Time Complexity | Space Complexity |
|-----------|:--------------:|:----------------:|
| Push      | O(1)           | O(1)             |
| Pop       | O(1)           | O(1)             |
| Peek      | O(1)           | O(1)             |
| is_empty  | O(1)           | O(1)             |
| is_full   | O(1)           | O(1)             |

Overall space: **O(n)** where n = capacity.

## API

```c
Stack *stack_create(size_t capacity);
bool   stack_push(Stack *s, int value);
bool   stack_pop(Stack *s, int *out);
bool   stack_peek(const Stack *s, int *out);
bool   stack_is_empty(const Stack *s);
bool   stack_is_full(const Stack *s);
size_t stack_size(const Stack *s);
void   stack_display(const Stack *s);
void   stack_destroy(Stack *s);
```

## Use Cases

- **Expression evaluation** (postfix, infix-to-postfix conversion).
- **Undo/Redo** mechanisms.
- **Depth-First Search (DFS)** in graph traversal.
- **Function call management** (the call stack).
- **Balanced parentheses** checking.

## Build & Run

```bash
make stack
./stack/stack_test
```
