/*
 * @file
 *
 * @brief Implements Insertion Sort Algorithm (Iterative)
 *
 * Algorithm:
 * 1. For every element, check its preceding element and swap if they are not sorted
 * 2. Repeat for every element
 */

#include <cstddef>
#include <vector>

/*
 * @namespace algorithms
 * 
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
 * @brief Applies Insertion Sort in-place on @param array
 * 
 * @param array Array to be sorted
 * @param size Size of the array
 */
void insertionSort(int *array, std::size_t size) {
    int key;
    for (std::size_t i = 1; i < size; ++i) {
        key = array[i];
        std::size_t j = i;
        
        while (j > 0 && array[j - 1] > key) {
            array[j] = array[j-1];
            --j;
        }
        array[j] = key;
    }
}

/* 
 * @brief Applies Insertion Sort in-place on @param array
 * 
 * @param array Array to be sorted
 */
template <typename T>
void insertionSort(std::vector<T>& array) {
    int key;

    for (auto it = array.begin() + 1; it != array.end(); ++it) {
        key = *(it);
        auto jt = it;

        while (jt > array.begin() && *(jt - 1) > key) {
            *(jt) = *(jt - 1);
            --jt;
        }
        *(jt) = key;
    }
}

} // namespace sort

} // namespace algorithms

