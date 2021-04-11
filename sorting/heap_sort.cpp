//
// Created by 曾清陽 on 2021/4/10.
//

#include "heap_sort.h"

namespace sorting{
    void heapify(std::vector<int> &arr, int size, int root);

    // best-case time complexity: O(nlogn),
    // avg-case time complexity: O(nlogn)
    // worst-case time complexity: O(nlogn)
    // space complexity: O(1), in-place.
    void HeapSort(std::vector<int>& arr){
        // Make arr a max heap
        // O(n)
        unsigned long size = arr.size();
        for (int i = size / 2 - 1; i >= 0; i--){
           heapify(arr, size, i);
        }
        // Sort array according to the max heap
        int sorted_number = 0;
        while (sorted_number < size){
            std::swap(arr[0], arr[size - sorted_number - 1]);
            sorted_number++;
            heapify(arr, size - sorted_number,0);
        }
    }

    // time-complexity: O(logn)
    // SiftDown
    void heapify(std::vector<int> &arr, int size, int root) {
        auto left = root * 2;
        auto right = left + 1;

        int child_max_index;
        if (left > size -1){
            // leaf-node
            return;
        } else if (left == size -1)  {
            // single-child
            child_max_index = left;
        } else {
            // complete-subtree
            child_max_index = arr[left] > arr[right] ? left : right;
        }

        // if a subtree node is greater than root,
        // swap the value and recursively tweak the subtree
        if (arr[root] < arr[child_max_index]) {
            std::swap(arr[root], arr[child_max_index]);
            heapify(arr, size, child_max_index);
        }
    }
}