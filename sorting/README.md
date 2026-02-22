# Sorting Algorithms

Eight classic sorting algorithms implemented in C, operating on integer arrays in ascending order.

## Complexity Comparison

| Algorithm      | Best       | Average    | Worst      | Space  | Stable |
|----------------|:----------:|:----------:|:----------:|:------:|:------:|
| Bubble Sort    | O(n)       | O(n²)      | O(n²)      | O(1)   | ✅     |
| Selection Sort | O(n²)      | O(n²)      | O(n²)      | O(1)   | ❌     |
| Insertion Sort | O(n)       | O(n²)      | O(n²)      | O(1)   | ✅     |
| Merge Sort     | O(n log n) | O(n log n) | O(n log n) | O(n)   | ✅     |
| Quick Sort     | O(n log n) | O(n log n) | O(n²)      | O(log n)| ❌    |
| Heap Sort      | O(n log n) | O(n log n) | O(n log n) | O(1)   | ❌     |
| Counting Sort  | O(n + k)   | O(n + k)   | O(n + k)   | O(n+k) | ✅     |
| Radix Sort     | O(d·(n+k)) | O(d·(n+k)) | O(d·(n+k)) | O(n+k) | ✅     |

> **n** = number of elements, **k** = range of values, **d** = number of digits

## API

```c
void bubble_sort(int *arr, size_t n);
void selection_sort(int *arr, size_t n);
void insertion_sort(int *arr, size_t n);
void merge_sort(int *arr, size_t n);
void quick_sort(int *arr, size_t n);
void heap_sort(int *arr, size_t n);
void counting_sort(int *arr, size_t n);   /* non-negative integers */
void radix_sort(int *arr, size_t n);      /* non-negative integers */
void print_array(const int *arr, size_t n);
```

## When to Use What

| Scenario | Recommended |
|----------|-------------|
| Small or nearly sorted data | **Insertion Sort** |
| General purpose, guaranteed O(n log n) | **Merge Sort** or **Heap Sort** |
| Fast average case, in-place | **Quick Sort** |
| Known small range of integers | **Counting Sort** |
| Large integers with fixed digits | **Radix Sort** |
| Educational / simplicity | **Bubble Sort** or **Selection Sort** |

## Build & Run

```bash
make sorting
./sorting/sorting_test
```
