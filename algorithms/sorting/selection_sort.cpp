/*
 * @file
 * @brief Implements Selction Sort Algorithm
 *
 * Algorithm:
 * 1. Find the minimum element in the unsorted array
 * 2. Move the minimum element to the beginning of the unsorted array
 * 3. Move the beginning of the unsorted array once to the right
 * 4. Repeat till the beginning and end of the unsorted array are same
 */

#include <cstddef>
#include <utility>

/*
 * @namespace algorithms
 * @brief Parent namespace for all namespaces of various algorithms
 */
namespace algorithms {

/* @namespace sort
 * @brief Functions for sorting algorithms
 */
namespace sort {

/* @brief Applies Selection Sort in-place on @param array
 * @param array Array to be sorted
 * @param size Size of the array
 */
void selectionSort(int *array, std::size_t size) {
    std::size_t min;

    for (std::size_t start = 0; start < size; ++start) {
        min = start;

        for (std::size_t i = start + 1; i < size; i++) {
            if (array[i] < array[min]) min = i;
        }

        std::swap(array[start], array[min]);
    }
}


} // namespace sort

} // namespace algorithms


int main() {
    return 0;
}

