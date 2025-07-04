/*
 * @file
 *
 * @brief Implements Linear Search Algorithm
 *
 * Algorithm:
 * 1. Iterate over entire array
 * 2. Check if current element matches the requested one
 * 3. If it matches, return the current index
 * 4. If loop finishes, no element matching the requested one is found, return -1
 */

#include <cstddef>
#include <vector>

/*
 * @namespace algorithms
 * @brief Parent namespace for all namespaces of various algorithms
 */
namespace algorithms {

/* 
 * @namespace search
 * @brief Functions for searching algorithms
 */
namespace search {

/* 
 * @brief Looks for @param item in @param array using Linear Search
 * 
 * @param array Array to be seached
 * @param size Size of the array
 * @param item Item to be searched for
 */
template <typename T>
std::size_t linearSeach(T *array, std::size_t size, T item) {
    for (std::size_t i = 0; i < size; ++i) {
        if (array[i] == item) return i;
    }

    return -1;
}

/* 
 * @brief Applies Bubble Sort in-place on @param array
 * 
 * @param array Array to be searched
 * @param item Item to searched for
 */
template <typename T>
std::size_t linearSeach(std::vector<T> array, T item) {
    for (std::size_t i = 0; i < array.size(); ++i) {
        if (array[i] == item) return i;
    }

    return -1;
}


} // namespace search

} // namespace algorithms

