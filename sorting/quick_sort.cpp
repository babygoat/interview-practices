//
// Created by 曾清陽 on 2021/4/8.
//

#include "quick_sort.h"

namespace sorting{
    namespace {
        void quickSort(std::vector<int>& arr, int start, int end){
            if (start >= end ){
                return;
            }
            // choose the first element for pivot
            auto pivot = arr[start];
            // find the index of the pivot and move the elements less than pivot to the left of the pivot
            auto indexOfPivot= start;
            for(auto i = indexOfPivot; i <= end; i++ ){
                if(arr[i] < pivot){
                    std::swap(arr[indexOfPivot], arr[i]);
                    indexOfPivot++;
                }
            }
            // move the pivot to its index
            arr[indexOfPivot] = pivot;
            // sort the partition less than the pivot
            quickSort(arr, start, indexOfPivot);
            // sort the partition greater or equal to the pivot
            quickSort(arr, indexOfPivot+1, end);
        }
    }
    // worst-case time complexity: O(n^2), if the partition is always skew. T(n) = T(n-1) + O(n)
    // best-case time complexity: O(nlogn), if the partition is evenly each iteration. T(n) = 2T(n/2) + O(n)
    // avg-case time complexity: O(nlogn)
    // space-complexity: O(logn) or O(n) depends on cases.
    // not stable sorting
    void QuickSort(std::vector<int>& arr){
        quickSort(arr, 0, arr.size()-1);
    }
}