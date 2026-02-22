/*
 * sorting.c — Sorting Algorithms (Implementation)
 *
 * 8 sorting algorithms: bubble, selection, insertion,
 * merge, quick, heap, counting, radix.
 */

#include "sorting.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ── Internal Helpers ────────────────────────────────────────────────── */

static void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/* ═══════════════════════════════════════════════════════════════════════
 *  1. Bubble Sort
 * ═══════════════════════════════════════════════════════════════════════ */

void bubble_sort(int *arr, size_t n)
{
    for (size_t i = 0; i < n; i++) {
        int swapped = 0;
        for (size_t j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if (!swapped) break;   /* optimised: early exit */
    }
}

/* ═══════════════════════════════════════════════════════════════════════
 *  2. Selection Sort
 * ═══════════════════════════════════════════════════════════════════════ */

void selection_sort(int *arr, size_t n)
{
    for (size_t i = 0; i < n; i++) {
        size_t min_idx = i;
        for (size_t j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
            swap(&arr[i], &arr[min_idx]);
    }
}

/* ═══════════════════════════════════════════════════════════════════════
 *  3. Insertion Sort
 * ═══════════════════════════════════════════════════════════════════════ */

void insertion_sort(int *arr, size_t n)
{
    for (size_t i = 1; i < n; i++) {
        int key = arr[i];
        size_t j = i;
        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}

/* ═══════════════════════════════════════════════════════════════════════
 *  4. Merge Sort
 * ═══════════════════════════════════════════════════════════════════════ */

static void merge(int *arr, size_t left, size_t mid, size_t right)
{
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    if (!L || !R) { free(L); free(R); return; }

    memcpy(L, arr + left, n1 * sizeof(int));
    memcpy(R, arr + mid + 1, n2 * sizeof(int));

    size_t i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

static void merge_sort_rec(int *arr, size_t left, size_t right)
{
    if (left >= right) return;

    size_t mid = left + (right - left) / 2;
    merge_sort_rec(arr, left, mid);
    merge_sort_rec(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void merge_sort(int *arr, size_t n)
{
    if (n < 2) return;
    merge_sort_rec(arr, 0, n - 1);
}

/* ═══════════════════════════════════════════════════════════════════════
 *  5. Quick Sort (Lomuto partition, last element pivot)
 * ═══════════════════════════════════════════════════════════════════════ */

static size_t partition(int *arr, size_t low, size_t high)
{
    int pivot = arr[high];
    size_t i = low;

    for (size_t j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}

static void quick_sort_rec(int *arr, size_t low, size_t high)
{
    if (low >= high) return;

    size_t pi = partition(arr, low, high);

    if (pi > 0)
        quick_sort_rec(arr, low, pi - 1);
    quick_sort_rec(arr, pi + 1, high);
}

void quick_sort(int *arr, size_t n)
{
    if (n < 2) return;
    quick_sort_rec(arr, 0, n - 1);
}

/* ═══════════════════════════════════════════════════════════════════════
 *  6. Heap Sort
 * ═══════════════════════════════════════════════════════════════════════ */

static void heapify(int *arr, size_t n, size_t i)
{
    size_t largest = i;
    size_t left    = 2 * i + 1;
    size_t right   = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort(int *arr, size_t n)
{
    /* Build max-heap */
    for (size_t i = n / 2; i > 0; i--)
        heapify(arr, n, i - 1);

    /* Extract elements one by one */
    for (size_t i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

/* ═══════════════════════════════════════════════════════════════════════
 *  7. Counting Sort (non-negative integers)
 * ═══════════════════════════════════════════════════════════════════════ */

void counting_sort(int *arr, size_t n)
{
    if (n < 2) return;

    /* Find max */
    int max_val = arr[0];
    for (size_t i = 1; i < n; i++) {
        if (arr[i] > max_val) max_val = arr[i];
    }

    size_t range = (size_t)max_val + 1;
    int *count  = (int *)calloc(range, sizeof(int));
    int *output = (int *)malloc(n * sizeof(int));
    if (!count || !output) { free(count); free(output); return; }

    /* Count occurrences */
    for (size_t i = 0; i < n; i++)
        count[arr[i]]++;

    /* Cumulative count */
    for (size_t i = 1; i < range; i++)
        count[i] += count[i - 1];

    /* Build output (stable, iterate backwards) */
    for (size_t i = n; i > 0; i--) {
        output[count[arr[i - 1]] - 1] = arr[i - 1];
        count[arr[i - 1]]--;
    }

    memcpy(arr, output, n * sizeof(int));
    free(count);
    free(output);
}

/* ═══════════════════════════════════════════════════════════════════════
 *  8. Radix Sort (LSD, non-negative integers)
 * ═══════════════════════════════════════════════════════════════════════ */

static void counting_sort_by_digit(int *arr, size_t n, int exp)
{
    int *output = (int *)malloc(n * sizeof(int));
    int  count[10] = {0};
    if (!output) return;

    for (size_t i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (size_t i = n; i > 0; i--) {
        int digit = (arr[i - 1] / exp) % 10;
        output[count[digit] - 1] = arr[i - 1];
        count[digit]--;
    }

    memcpy(arr, output, n * sizeof(int));
    free(output);
}

void radix_sort(int *arr, size_t n)
{
    if (n < 2) return;

    int max_val = arr[0];
    for (size_t i = 1; i < n; i++) {
        if (arr[i] > max_val) max_val = arr[i];
    }

    for (int exp = 1; max_val / exp > 0; exp *= 10)
        counting_sort_by_digit(arr, n, exp);
}

/* ── Utility ─────────────────────────────────────────────────────────── */

void print_array(const int *arr, size_t n)
{
    printf("[");
    for (size_t i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}
