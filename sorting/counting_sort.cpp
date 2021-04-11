//
// Created by 曾清陽 on 2021/4/11.
//

#include "counting_sort.h"

namespace sorting{
#define MAX 100
#define MIN -100
    // Best/Avg/worst time complexity: O(n + k), k is the range MIN~MAX
    // Space complexity: O(n + k) or O(k) if the element in arr can be overwritten directly since the element is integer only.
    // https://rust-algo.club/sorting/counting_sort/
    std::vector<int> CountingSort(std::vector<int> arr){
        std::vector<int> count(MAX-MIN+1, 0);
        std::vector<int> work(arr.size(), 0);
        // counting the number of each value
        for (auto val: arr){
            count[val - MIN]++;
        }

        // calculates the delimiter index of each element
        for (int i = 1; i < count.size(); i++){
            count[i] += count[i-1];
        }

        // copy output
        int index;
        for (int i = arr.size() - 1; i >= 0; i--){
            count[arr[i]-MIN]--;
            index = count[arr[i] - MIN];
            work[index] = arr[i];
        }
        return work;
    }
}