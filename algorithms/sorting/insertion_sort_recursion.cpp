/*
 * @file
 * @brief Implements Insertion Sort Algorithm (Recursion)
 *
 * Algorithm:
 * 1. For every element, check its preceding element and swap if they are not sorted
 * 2. Repeat for every element
 */

#include <cstddef>
#include <vector>

/*
 * @namespace algorithms
 * @brief Parent namespace for all namespaces of various algorithms
 */
namespace algorithms {

/* @namespace sort
 * @brief Functions for sorting algorithms
 */
namespace sort {

/*
 * @brief Inserts the element at given index into its correct position
 *        within the sorted subarray array[0..index-1].
 * 
 * @param array Pointer to the array of integers.
 * @param index The index of the element to be inserted.
 */
void insert(int *array, std::size_t index) {
    int key = array[index];
    std::size_t i = index - 1;

    while (i >= 0 && array[i] > key) {
        array[i + 1] = array[i];
        --i;
    }

    array[i + 1] = key;
}

/*
 * @brief Inserts the element at given index into its correct position
 *        within the sorted subarray array[0..index-1].
 * 
 * @param array Pointer to the array of integers.
 * @param index The index of the element to be inserted.
 */
template <typename T>
void insert(std::vector<T>& array, std::size_t index) {
    int key = array[index];
    std::size_t i = index - 1;

    while (i >= 0 && array[i] > key) {
        array[i + 1] = array[i];
        --i;
    }

    array[i + 1] = key;
}

/*
 * @brief Recursively sorts the array using insertion sort algorithm.
 * 
 * @param array Pointer to the array of integers to sort.
 * @param size Total number of elements in the array.
 * @param start The current index to insert into the sorted subarray (default is 1).
 */
void insertionSort(int *array, std::size_t size, std::size_t start = 1) {
    if (start >= size) return;

    insert(array, start);

    insertionSort(array, size, start + 1);
}

/*
 * @brief Recursively sorts the array using insertion sort algorithm.
 * 
 * @param array Pointer to the array of integers to sort.
 * @param size Total number of elements in the array.
 * @param start The current index to insert into the sorted subarray (default is 1).
 */
template <typename T>
void insertionSort(std::vector<T>& array, std::size_t size, std::size_t start = 1) {
    if (start >= size) return;

    insert(array, start);

    insertionSort(array, size, start + 1);
}

} // namespace sort

} // namespace algorithms


int main() {
    return 0;
}

