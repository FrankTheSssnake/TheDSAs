/*
 * @file
 * @brief Implements Selction Sort Algorithm (Recursion)
 *
 * Algorithm:
 * 1. Divide the array into 2 parts
 * 2. Keep dividing the left part until you arrive at 2 elements
 * 3. Sort the 2 elements
 * 4. Merge the sorted arrays together
 */

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

/* @brief Applies Merge Sort in-place on @param array
 * @param array Array to be sorted
 */
template <typename T>
void mergeSort(std::vector<T>& arr) {
    if (arr.size() <= 1) return;

    unsigned long split = arr.size() / 2;

    std::vector<T> left(arr.begin(), arr.begin() + split);
    std::vector<T> right(arr.begin() + split, arr.end());

    mergeSort(left);
    mergeSort(right);

    arr.clear();

    std::size_t i = 0, j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            arr.push_back(left[i++]);
        } else {
            arr.push_back(right[j++]);
        }
    }

    while (i < left.size()) arr.push_back(left[i++]);
    while (j < right.size()) arr.push_back(right[j++]);
}

} // namespace sort

} // namespace algorithms


int main() {
    return 0;
}
