//
// Created by 曾清陽 on 2021/4/7.
//
#include <vector>
#include "insertion_sort.h"

namespace sorting {
    // InsertionSort sort an input vector in-place
    // worst-case time complexity: O(n^2), if the elements are in reverse order.
    // average-case time complexity: O(n^2),
    // best-case time complexity: O(n), if the elements are already sorted
    // space complexity: O(1)
    // stable sorting
    void InsertionSort(std::vector<int> &arr) {
        for (auto i = 1; i < arr.size(); i++) {
            for (auto j = i - 1; j >= 0; j--) {
                if (arr[j] <= arr[j + 1]) {
                    break;
                }
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}
