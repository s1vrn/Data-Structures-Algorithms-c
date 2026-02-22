/*
 * hashmap.h — Hash Map (Separate Chaining, Declarations)
 *
 * A string-key, integer-value hash map using separate chaining
 * for collision resolution.
 */

#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdbool.h>
#include <stddef.h>

/* ── Entry (Linked List Node) ────────────────────────────────────────── */

typedef struct HMEntry {
    char          *key;
    int            value;
    struct HMEntry *next;
} HMEntry;

/* ── Hash Map ────────────────────────────────────────────────────────── */

typedef struct {
    HMEntry **buckets;
    size_t    capacity;
    size_t    size;
} HashMap;

/* ── Function Declarations ───────────────────────────────────────────── */

/**
 * Create a new hash map with the given number of buckets.
 * Returns NULL on allocation failure.
 */
HashMap *hashmap_create(size_t capacity);

/**
 * Insert or update a key-value pair.
 * The key string is copied internally.
 * Returns false on allocation failure.
 */
bool hashmap_put(HashMap *map, const char *key, int value);

/**
 * Retrieve the value for `key` and store it in *out.
 * Returns false if the key is not found.
 */
bool hashmap_get(const HashMap *map, const char *key, int *out);

/**
 * Check whether the map contains the given key.
 */
bool hashmap_contains(const HashMap *map, const char *key);

/**
 * Remove a key-value pair.
 * Returns false if the key is not found.
 */
bool hashmap_remove(HashMap *map, const char *key);

/**
 * Return the number of key-value pairs.
 */
size_t hashmap_size(const HashMap *map);

/**
 * Print all key-value pairs.
 */
void hashmap_display(const HashMap *map);

/**
 * Free all memory associated with the hash map.
 */
void hashmap_destroy(HashMap *map);

#endif /* HASHMAP_H */
