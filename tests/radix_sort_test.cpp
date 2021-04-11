//
// Created by 曾清陽 on 2021/4/11.
//

#include <catch.hpp>
#include <vector>
#include <radix_sort.h>

TEST_CASE("radix sort test", "[sorting]"){
    using namespace sorting;
    std::vector<int> distinct_values = {13456, 389, 77777, 8945, 37560, 143859, 2, 5, 1000};
    std::vector<int> expect = {2, 5, 389, 1000, 8945, 13456, 37560, 77777, 143859};
    RadixSort(distinct_values);
    REQUIRE(distinct_values == expect);
}
