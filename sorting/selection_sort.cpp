//
// Created by 曾清陽 on 2021/7/15.
//

#include "selection_sort.h"

namespace sorting {
    // Worst case: O(n^2)
    // Avg case: O(n^2)
    // Best case: O(n^2)
    // Space complexity: O(1)
    // Unstable sort
    void SelectionSort(std::vector<int>& arr){
        int min_idx;
        for(int i = 0; i < arr.size(); i++){
            min_idx = i;
            for(int j = i + 1; j < arr.size(); j++){
                if(arr[min_idx] > arr[j]){
                    min_idx = j;
                }
            }
            std::swap(arr[i], arr[min_idx]);
        }
    }
}