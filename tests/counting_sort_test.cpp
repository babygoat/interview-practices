//
// Created by 曾清陽 on 2021/4/11.
//

#include <vector>
#include <catch.hpp>
#include <counting_sort.h>

TEST_CASE("counting sort test", "sorting") {
    using namespace sorting;
    std::vector<int> distinct_values = {-3, 4, 6, -2, -5, -100, 20, 30, -37, 100};
    std::vector<int> expect = {-100, -37, -5, -3, -2, 4, 6, 20, 30, 100};

    REQUIRE(CountingSort(distinct_values) == expect);

    std::vector<int> empty = {};
    expect = empty;
    REQUIRE(CountingSort(empty) == expect);

    std::vector<int> single_value = {5};
    expect = {5};
    REQUIRE(CountingSort(single_value) == expect);

    std::vector<int> duplicate_values = {-4, -5, 3, 3, -4, -6, -5, -2};
    expect = {-6, -5, -5, -4, -4, -2, 3, 3};
    REQUIRE(CountingSort(duplicate_values) == expect);
}