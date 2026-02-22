/*
 * hashmap.c — Hash Map (Separate Chaining, Implementation)
 */

#include "hashmap.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ── Hash Function (djb2 by Dan Bernstein) ───────────────────────────── */

static size_t hash_djb2(const char *str, size_t capacity)
{
    unsigned long hash = 5381;
    int c;
    while ((c = (unsigned char)*str++))
        hash = ((hash << 5) + hash) + (unsigned long)c;   /* hash * 33 + c */
    return hash % capacity;
}

/* ── Helpers ─────────────────────────────────────────────────────────── */

static HMEntry *entry_create(const char *key, int value)
{
    HMEntry *entry = (HMEntry *)malloc(sizeof(HMEntry));
    if (!entry) return NULL;

    entry->key = strdup(key);
    if (!entry->key) {
        free(entry);
        return NULL;
    }
    entry->value = value;
    entry->next  = NULL;
    return entry;
}

static void entry_free(HMEntry *entry)
{
    free(entry->key);
    free(entry);
}

/* ── Create / Destroy ────────────────────────────────────────────────── */

HashMap *hashmap_create(size_t capacity)
{
    if (capacity == 0) capacity = 16;

    HashMap *map = (HashMap *)malloc(sizeof(HashMap));
    if (!map) {
        fprintf(stderr, "Error: malloc failed in hashmap_create\n");
        return NULL;
    }

    map->buckets = (HMEntry **)calloc(capacity, sizeof(HMEntry *));
    if (!map->buckets) {
        fprintf(stderr, "Error: calloc failed for buckets\n");
        free(map);
        return NULL;
    }

    map->capacity = capacity;
    map->size     = 0;
    return map;
}

void hashmap_destroy(HashMap *map)
{
    if (!map) return;

    for (size_t i = 0; i < map->capacity; i++) {
        HMEntry *curr = map->buckets[i];
        while (curr) {
            HMEntry *tmp = curr;
            curr = curr->next;
            entry_free(tmp);
        }
    }
    free(map->buckets);
    free(map);
}

/* ── Put / Get / Remove ──────────────────────────────────────────────── */

bool hashmap_put(HashMap *map, const char *key, int value)
{
    size_t idx = hash_djb2(key, map->capacity);

    /* Update existing key */
    HMEntry *curr = map->buckets[idx];
    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            curr->value = value;
            return true;
        }
        curr = curr->next;
    }

    /* Insert new entry at head of chain */
    HMEntry *entry = entry_create(key, value);
    if (!entry) return false;

    entry->next       = map->buckets[idx];
    map->buckets[idx] = entry;
    map->size++;
    return true;
}

bool hashmap_get(const HashMap *map, const char *key, int *out)
{
    size_t idx = hash_djb2(key, map->capacity);

    HMEntry *curr = map->buckets[idx];
    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            *out = curr->value;
            return true;
        }
        curr = curr->next;
    }
    return false;
}

bool hashmap_contains(const HashMap *map, const char *key)
{
    int dummy;
    return hashmap_get(map, key, &dummy);
}

bool hashmap_remove(HashMap *map, const char *key)
{
    size_t idx = hash_djb2(key, map->capacity);

    HMEntry *curr = map->buckets[idx];
    HMEntry *prev = NULL;

    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            if (prev)
                prev->next = curr->next;
            else
                map->buckets[idx] = curr->next;

            entry_free(curr);
            map->size--;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false;
}

/* ── Queries ─────────────────────────────────────────────────────────── */

size_t hashmap_size(const HashMap *map)
{
    return map->size;
}

void hashmap_display(const HashMap *map)
{
    printf("HashMap (%zu entries):\n", map->size);
    for (size_t i = 0; i < map->capacity; i++) {
        HMEntry *curr = map->buckets[i];
        if (!curr) continue;

        printf("  [%zu]:", i);
        while (curr) {
            printf(" (\"%s\" => %d)", curr->key, curr->value);
            if (curr->next) printf(" ->");
            curr = curr->next;
        }
        printf("\n");
    }
}
