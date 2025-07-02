/*
 * @file
 * @brief Implements Bubble Sort Algorithm
 *
 * Algorithm:
 * 1. Check two adjacent elements and sort them
 * 2. Repeat until you reach the end
 * 3. Start from the beginning, going to one before end
 * 4. Repeat until array is sorted
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

/* @brief Applies Bubble Sort in-place on @param array
 * @param array Array to be sorted
 * @param size Size of the array
 */
void bubbleSort(int *array, std::size_t size) {
    for (std::size_t i = 0; i < size; i++) {
        for (std::size_t j = 0; j < size - i; j++) {
            if (array[j] < array[j+1]) continue;
            std::swap(array[j], array[j+1]);
        }
    }
}

} // namespace sort

} // namespace algorithms


int main() {
    return 0;
}

