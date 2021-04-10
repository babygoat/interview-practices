//
// Created by 曾清陽 on 2021/4/10.
//

#include "merge_sort.h"

namespace sorting{
    namespace{
        void merge(std::vector<int>& arr, int start, int mid, int end, std::vector<int>& work){
            auto sortedIndex = start;
            auto left=start, right= mid + 1;
            while (left <= mid && right <= end){
                if(work[left] < work[right]){
                    arr[sortedIndex] = work[left];
                    sortedIndex++;
                    left++;
                } else{
                    arr[sortedIndex] = work[right];
                    sortedIndex++;
                    right++;
                }
            }
            if (left <= mid){
                std::copy(&work[left], &work[mid+1], &arr[sortedIndex]);
            }
            if (right <= end){
                std::copy(&work[right], &work[end+1], &arr[sortedIndex]);
            }
            // note that the std::copy range specifier is [begin, tail)
            std::copy(&arr[start], &arr[end+1], &work[start]);
        }
        void mergeSort(std::vector<int>& arr, int start, int end, std::vector<int>& work){
            if (start >= end) {
                return;
            }
            // avoid the integer overflow
            // tips: by means of sub-adder
            //         (carry)        (half-adder)
            //  mid =  (start + end) / 2
            auto mid = (start&end) + ((start ^ end) >> 1);
            mergeSort(arr, start, mid, work);
            mergeSort(arr, mid+1, end, work);
            merge(arr, start, mid, end, work);
        }
    }

    // best-case time complexity: O(nlogn), if the array is already sorted.
    // avg-case time complexity: O(nlogn),
    // worst-case time complexity: O(nlogn), if the largest two values reside in two sub-lists.
    // space complexity: O(n) to create the work array
    void MergeSort(std::vector<int>& arr){
        std::vector<int> copy(arr);
        mergeSort(arr, 0, arr.size()-1, copy);
    }
}