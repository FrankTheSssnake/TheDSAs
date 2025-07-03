/*
 * @file
 *
 * @brief Implements Quick Sort Algorithm (Recursion)
 *
 * Algorithm:
 * 1. Pick a pivot element
 * 2. Partition arrays so elements lesser than pivot are on the left, and elements greater than pivot are on the right
 * 3. Recursively sort the left and right arrays
*/

#include <cstddef>
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
 * @brief Applies Quick Sort in-place on @param array
 * 
 * @param array Array to be sorted
 */
template <typename T>
void quickSort(std::vector<T>& array) {
    if (array.size() == 1) return;

    T pivot = array.back();
    std::size_t pivotCount = 1;

    std::vector<T> left, right;

    for (auto i: array) {
        if (i < pivot) left.push_back(i);
        else if (i > pivot) right.push_back(i);
        else ++pivotCount;
    }

    quickSort(left);
    quickSort(right);

    array.clear();
    array.insert(array.end(), left.begin(), left.end());

    for (std::size_t i = 0; i < pivotCount; ++i) array.push_back(pivot);

    array.insert(array.end(), right.begin(), right.end());
}

} // namespace sort

} // namespace algorithms


int main() {
    return 0;
}

