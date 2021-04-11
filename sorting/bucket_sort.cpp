//
// Created by 曾清陽 on 2021/4/11.
//

#include "bucket_sort.h"

namespace sorting {
    // Worst-case time complexity: O(n^2), if the values are distributed in the single bucket
    // Best-case time complexity: O(n+k)
    // Avg-case time complexity: O(n + n^2/k + k), if uniformly distributed.
    // https://en.wikipedia.org/wiki/Bucket_sort#Average-case_analysis
    // space complexity: O(n+k) with dynamic array(vector) within each bucket.
    void BucketSort(std::vector<int> &arr) {
#define BUCKET_SIZE 10
        // Initialize
        // create the buckets according to the value range of input
        // WLOG, define the bucket size to 10, assume the value range to be 1~99
        std::vector<std::vector<int>> buckets(BUCKET_SIZE);

        // Scatter
        // distribute the input into the buckets
        for (auto val: arr) {
            buckets[val / BUCKET_SIZE].push_back(val);
        }

        // sort values within each bucket
        // if the val are distributed evenly, the insertion sort would be utilized to lower the time complexity
        // the sort type will result in the stable/unstable sorting
        for (auto it = buckets.begin(); it != buckets.end(); it++) {
            std::sort(it->begin(), it->end());
        }

        // Gather
        // copy the sorted elements from each bucket
        int index = 0;
        for (auto it = buckets.begin(); it != buckets.end(); it++) {
            std::copy(it->begin(), it->end(), arr.begin() + index);
            index += it->size();
        }
    }
}