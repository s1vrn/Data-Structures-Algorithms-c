/*
 * main.c — Hash Map Test Driver
 */

#include "hashmap.h"
#include <stdio.h>
#include <assert.h>

int main(void)
{
    printf("=== Hash Map Tests ===\n\n");

    HashMap *map = hashmap_create(8);
    assert(map != NULL);
    assert(hashmap_size(map) == 0);

    /* ── Put ─────────────────────────────────────────────────────────── */
    printf("--- Put: apple=1, banana=2, cherry=3, date=4 ---\n");
    assert(hashmap_put(map, "apple",  1));
    assert(hashmap_put(map, "banana", 2));
    assert(hashmap_put(map, "cherry", 3));
    assert(hashmap_put(map, "date",   4));
    hashmap_display(map);
    assert(hashmap_size(map) == 4);

    /* ── Get ─────────────────────────────────────────────────────────── */
    int val;
    printf("\n--- Get 'banana' ---\n");
    assert(hashmap_get(map, "banana", &val));
    printf("banana => %d\n", val);
    assert(val == 2);

    printf("--- Get 'fig' (not in map) ---\n");
    assert(!hashmap_get(map, "fig", &val));
    printf("fig => not found\n");

    /* ── Contains ────────────────────────────────────────────────────── */
    printf("\n--- Contains ---\n");
    assert(hashmap_contains(map, "cherry"));
    assert(!hashmap_contains(map, "grape"));

    /* ── Update existing key ─────────────────────────────────────────── */
    printf("\n--- Update 'apple' to 100 ---\n");
    assert(hashmap_put(map, "apple", 100));
    assert(hashmap_get(map, "apple", &val));
    printf("apple => %d\n", val);
    assert(val == 100);
    assert(hashmap_size(map) == 4);         /* size unchanged */

    /* ── Remove ──────────────────────────────────────────────────────── */
    printf("\n--- Remove 'banana' ---\n");
    assert(hashmap_remove(map, "banana"));
    assert(!hashmap_contains(map, "banana"));
    assert(hashmap_size(map) == 3);

    printf("--- Remove 'unknown' (not in map) ---\n");
    assert(!hashmap_remove(map, "unknown"));

    hashmap_display(map);

    /* ── Cleanup ─────────────────────────────────────────────────────── */
    hashmap_destroy(map);

    printf("\n✅ All hash map tests passed!\n");
    return 0;
}
