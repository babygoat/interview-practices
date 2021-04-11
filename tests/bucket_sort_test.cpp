//
// Created by 曾清陽 on 2021/4/11.
//

#include <vector>
#include <catch.hpp>
#include <bucket_sort.h>

TEST_CASE("bucket sort test", "sorting"){
    using namespace sorting;
    std::vector<int> distinct_values = {11, 1, 3, 54, 30, 29, 18, 49, 59, 79, 89, 99};
    std::vector<int> expect = {1, 3, 11, 18, 29, 30, 49, 54, 59, 79, 89, 99};
    BucketSort(distinct_values);
    REQUIRE(distinct_values == expect);
}