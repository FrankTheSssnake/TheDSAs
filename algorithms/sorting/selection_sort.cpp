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

/* @brief Applies Selection Sort in-place on @param array
 * @param array Array to be sorted
 * @param size Size of the array
 */
void selectionSort(int *array, std::size_t size) {
    std::size_t min;

    for (std::size_t i = 0; i < size; ++i) {
        min = i;

        for (std::size_t j = i + 1; i < size; ++j) {
            if (array[j] < array[min]) min = j;
        }

        std::swap(array[i], array[min]);
    }
}

/* @brief Applies Selection Sort in-place on @param array
 * @param array Array to be sorted
 */
template <typename T>
void selectionSort(std::vector<T>& array) {
    typename std::vector<T>::iterator min;

    for (auto it = array.begin(); it != array.end(); ++it) {
        min = it;

        for (auto jt = it + 1; jt < array.end(); ++jt) {
            if (*jt < *min) min = jt;
        }

        if (min != it) std::swap(*it, *min);

    }
}

} // namespace sort

} // namespace algorithms


int main() {
    return 0;
}

