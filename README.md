# 📚 Data Structures in C

A clean, modular, and well-documented collection of fundamental data structures implemented in C. Built for learning, reference, and interview preparation.

---

## 📁 Project Structure

```
cds-workflow/
├── README.md
├── Makefile
├── linked_list/
│   ├── linked_list.h
│   ├── linked_list.c
│   ├── main.c
│   └── README.md
├── stack/
│   ├── stack.h
│   ├── stack.c
│   ├── main.c
│   └── README.md
├── queue/
│   ├── queue.h
│   ├── queue.c
│   ├── main.c
│   └── README.md
├── binary_search_tree/
│   ├── bst.h
│   ├── bst.c
│   ├── main.c
│   └── README.md
└── hashmap/
    ├── hashmap.h
    ├── hashmap.c
    ├── main.c
    └── README.md
```

---

## 📖 Table of Contents

| # | Data Structure | Description |
|---|----------------|-------------|
| 1 | [Singly Linked List](linked_list/) | Dynamic linear collection with pointer-based nodes |
| 2 | [Stack](stack/) | LIFO container (array-based) |
| 3 | [Queue](queue/) | FIFO container (linked-list-based) |
| 4 | [Binary Search Tree](binary_search_tree/) | Hierarchical sorted structure for fast lookup |
| 5 | [Hash Map](hashmap/) | Key-value store with O(1) average access |

---

## 🔨 Build & Run

### Prerequisites

- GCC (or any C99-compatible compiler)
- GNU Make

### Compile Everything

```bash
make all
```

### Compile a Specific Module

```bash
make linked_list
make stack
make queue
make bst
make hashmap
```

### Run a Test

```bash
./linked_list/linked_list_test
./stack/stack_test
./queue/queue_test
./binary_search_tree/bst_test
./hashmap/hashmap_test
```

### Clean Build Artifacts

```bash
make clean
```

---

## 🧠 Design Philosophy

- **Modular**: Each data structure lives in its own directory with a clean `.h` / `.c` separation.
- **Documented**: Every module has a `README.md` with time-complexity analysis and real-world use cases.
- **Tested**: Each module includes a `main.c` test driver that exercises all operations.
- **Portable**: Pure C99 with no external dependencies.

---

## 📜 License

This project is open-source and available under the [MIT License](LICENSE).
