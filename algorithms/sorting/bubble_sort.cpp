/*
 * @file
 *
 * @brief Implements Bubble Sort Algorithm (Iterative)
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
    for (std::size_t i = 1; i < size; i++) {
        for (std::size_t j = i; j > 0; --j) {
            if (array[j] < array[j-1]) std::swap(array[j], array[j-1]);
        }
    }
}

/* 
 * @brief Applies Bubble Sort in-place on @param array
 * 
 * @param array Array to be sorted
 */
template <typename T>
void bubbleSort(std::vector<T>& array) {
    for (auto it = array.begin() + 1; it != array.end(); ++it) {
        for (auto jt = array.end() - 1; jt > it; --jt) {
            if (*(jt) < *(jt - 1)) std::swap(*(jt), *(jt - 1));
        }
    }
}

} // namespace sort

} // namespace algorithms


int main() {
    return 0;
}

