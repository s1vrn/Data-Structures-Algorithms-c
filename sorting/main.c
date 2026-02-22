/*
 * main.c — Sorting Algorithms Test Driver
 *
 * Tests all 8 sorting algorithms with the same input array,
 * verifying correctness with assertions.
 */

#include "sorting.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define ARRAY_SIZE 10

static const int ORIGINAL[]  = {64, 25, 12, 22, 11, 90, 45, 78, 33, 1};
static const int EXPECTED[]  = {1, 11, 12, 22, 25, 33, 45, 64, 78, 90};

static void reset(int *arr)
{
    memcpy(arr, ORIGINAL, sizeof(ORIGINAL));
}

static void verify(const int *arr, const char *name)
{
    for (size_t i = 0; i < ARRAY_SIZE; i++) {
        if (arr[i] != EXPECTED[i]) {
            printf("FAIL: %s\n", name);
            print_array(arr, ARRAY_SIZE);
            assert(0 && "Sort result mismatch");
        }
    }
}

static void test_sort(void (*sort_fn)(int *, size_t), const char *name)
{
    int arr[ARRAY_SIZE];
    reset(arr);

    printf("%-18s ", name);
    printf("Before: ");
    print_array(arr, ARRAY_SIZE);

    sort_fn(arr, ARRAY_SIZE);

    printf("%-18s ", "");
    printf("After:  ");
    print_array(arr, ARRAY_SIZE);

    verify(arr, name);
    printf("\n");
}

int main(void)
{
    printf("=== Sorting Algorithms Tests ===\n\n");

    test_sort(bubble_sort,    "Bubble Sort");
    test_sort(selection_sort, "Selection Sort");
    test_sort(insertion_sort, "Insertion Sort");
    test_sort(merge_sort,     "Merge Sort");
    test_sort(quick_sort,     "Quick Sort");
    test_sort(heap_sort,      "Heap Sort");
    test_sort(counting_sort,  "Counting Sort");
    test_sort(radix_sort,     "Radix Sort");

    printf("✅ All sorting tests passed!\n");
    return 0;
}
