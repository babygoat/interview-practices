//
// Created by 曾清陽 on 2021/4/15.
//

#include "binary_search.h"

// worst case time-complexity: O(logn)
// space complexity: O(1)
int search::BinarySearch(std::vector<int> arr, int target) {
    int low = 0, high = arr.size();
    // we will use the range [low, high) as the loop invariant
    while(low<high){
        auto mid = low + (high -low)/2;
        if(arr[mid] < target)
            low = mid + 1;
        else if(arr[mid] > target)
            high = mid;
        else
            return mid;
    }
    return -1;
}

// worst case time-complexity: O(logn)
// space complexity: O(1)
int search::BinarySearchLowerBound(std::vector<int> arr, int target) {
    int low = 0, high = arr.size();
    // we will use the range [low, high) as the loop invariant
    while(low<high){
        auto mid = low + (high -low)/2;
        if(arr[mid] < target)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}
