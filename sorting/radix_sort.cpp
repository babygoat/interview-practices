//
// Created by 曾清陽 on 2021/4/11.
//

#include "radix_sort.h"

namespace sorting{
    namespace {
        std::vector<int> countingSort(std::vector<int> arr, int exp, int radix){
            const int count_size = radix;
            const auto arr_size = arr.size();
            std::vector<int> count (count_size, 0);
            std::vector<int> work (arr_size, 0);
            for (auto val: arr){
                count[val / exp % radix]++;
            }

            for (int i = 1; i < count_size; i++ ){
                count[i] += count[i - 1];
            }

            int bucket_idx;
            for (int i = arr_size - 1; i >= 0; i--){
                bucket_idx = arr[i]/exp %radix;
                count[bucket_idx]--;
                work[count[bucket_idx]] = arr[i];
            }
            return work;
        }
    }
    // Worst/Best/Avg-time complexity: O(d * (n + r)), where d is the number of digit(LSD) to sort and r is the radix
    // Space: O(n + r)
    // In general, the radix sort is stable sort if starts from LSD.
    // Usage: known range (d) of the data
    // fixed-size integers, floating points, strings (lexicographically)
    void RadixSort(std::vector<int> &arr) {
        const int radix = 10;

        // find the maximum number within the input
        int max = arr[0];
        for (auto val : arr){
            if(val > max){
                max = val;
            }
        }
        // Repeatedly sort the values with the LSD(Least Significant Digit)
        for (int exp = 1 ; exp <= max; exp *= radix){
            arr = countingSort(arr, exp, radix);
        }
    }
}
