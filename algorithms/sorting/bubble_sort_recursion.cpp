/*
 * @file
 * @brief Implements Bubble Sort Algorithm (recursion)
 *
 * Algorithm:
 * 1. Iterate over the array
 * 2. Check if each element is in the correct position by repeatedly comparing it with previous element
 * 3. Repeat till you reach the end
 */

#include <cstddef>
#include <utility>
#include <vector>

/*
 * @namespace algorithms
 * @brief Parent namespace for all namespaces of various algorithms
 */
namespace algorithms {

/* 
 * @namespace sort
 * 
 * @brief Functions for sorting algorithms
 */
namespace sort {

/* 
 * @brief Applies Bubble Sort in-place on @param array
 * 
 * @param array Array to be sorted
 * @param size Size of the array
 */
void bubbleSort(int *array, std::size_t size) {
    if (size <= 1) return;

    for (std::size_t i = 0; i < size - 1; ++i) {
        if (array[i] > array[i + 1]) std::swap(array[i], array[i + 1]);
    }

    bubbleSort(array, size - 1);
}

/* 
 * @brief Applies Bubble Sort in-place on @param array
 * 
 * @param array Array to be sorted
 * @param size Size of the array
 */
template <typename T>
void bubbleSort(std::vector<T>& array, std::size_t size) {
    if (size <= 1) return;

    for (auto it = array.begin(); it != array.end() - 1; ++it) {
        if (*it > *(it + 1)) std::swap(*it, *(it + 1));
    }

    bubbleSort(array, size - 1);
}

} // namespace sort

} // namespace algorithms

