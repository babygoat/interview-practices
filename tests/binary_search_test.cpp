//
// Created by 曾清陽 on 2021/4/13.
//

#include <vector>
#include <catch.hpp>
#include <binary_search.h>

TEST_CASE("binary search test", "[search]"){
    using namespace search;
    std::vector<int> distinct_cases = {3, 5, 6, 10, 12, 13};
    int target = 6;
    int expect_idx  = 2;
    REQUIRE(BinarySearch(distinct_cases, target) == expect_idx);

    target = 7;
    expect_idx = -1;
    REQUIRE(BinarySearch(distinct_cases, target) == expect_idx);

    std::vector<int> duplicate_cases = {3, 3, 5, 8, 8, 9, 10, 10, 10, 13, 16, 17};
    target = 10; // find the first index that is greater and equal to target
    int expect_lower_bound_idx = 6;
    REQUIRE(BinarySearchLowerBound(duplicate_cases, target) == expect_lower_bound_idx);

    target = 11;
    expect_lower_bound_idx = 9;
    REQUIRE(BinarySearchLowerBound(duplicate_cases, target) == expect_lower_bound_idx);
}