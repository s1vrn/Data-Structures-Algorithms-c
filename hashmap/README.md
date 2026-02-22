# Hash Map (Separate Chaining)

A **hash map** (hash table) stores key-value pairs and provides near-constant-time access via a hash function. This implementation uses **separate chaining** (linked lists at each bucket) for collision resolution.

## Operations

| Operation  | Average | Worst |
|------------|:-------:|:-----:|
| Put        | O(1)    | O(n)  |
| Get        | O(1)    | O(n)  |
| Remove     | O(1)    | O(n)  |
| Contains   | O(1)    | O(n)  |

Space: **O(n + m)** where n = entries, m = bucket count.

> **Note:** Worst-case O(n) occurs when all keys hash to the same bucket. A good hash function and load-factor management mitigate this.

## API

```c
HashMap *hashmap_create(size_t capacity);
bool     hashmap_put(HashMap *map, const char *key, int value);
bool     hashmap_get(const HashMap *map, const char *key, int *out);
bool     hashmap_contains(const HashMap *map, const char *key);
bool     hashmap_remove(HashMap *map, const char *key);
size_t   hashmap_size(const HashMap *map);
void     hashmap_display(const HashMap *map);
void     hashmap_destroy(HashMap *map);
```

## Hash Function

Uses the classic **djb2** algorithm by Dan Bernstein:

```c
hash = 5381;
while (c = *str++)
    hash = hash * 33 + c;
```

## Use Cases

- **Caching** (memoization, LRU caches).
- **Frequency counting** (word count, character frequency).
- **Database indexing** (in-memory indices).
- **Set implementations** (checking membership).
- **Symbol tables** in compilers and interpreters.

## Build & Run

```bash
make hashmap
./hashmap/hashmap_test
```
