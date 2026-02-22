/*
 * sorting.h — Sorting Algorithms (Declarations)
 *
 * Eight classic sorting algorithms operating on integer arrays.
 * All functions sort in ascending order.
 */

#ifndef SORTING_H
#define SORTING_H

#include <stddef.h>

/* ── Comparison-Based Sorts ──────────────────────────────────────────── */

void bubble_sort(int *arr, size_t n);
void selection_sort(int *arr, size_t n);
void insertion_sort(int *arr, size_t n);
void merge_sort(int *arr, size_t n);
void quick_sort(int *arr, size_t n);
void heap_sort(int *arr, size_t n);

/* ── Non-Comparison Sorts ────────────────────────────────────────────── */

/**
 * Counting sort — works for non-negative integers.
 */
void counting_sort(int *arr, size_t n);

/**
 * Radix sort (LSD) — works for non-negative integers.
 */
void radix_sort(int *arr, size_t n);

/* ── Utility ─────────────────────────────────────────────────────────── */

void print_array(const int *arr, size_t n);

#endif /* SORTING_H */
