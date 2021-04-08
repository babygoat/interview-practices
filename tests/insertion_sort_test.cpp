//
// Created by 曾清陽 on 2021/4/8.
//
#include <vector>
#include <catch.hpp>
#include <insertion_sort.h>

TEST_CASE("insertion sort test", "[sorting]"){
    using namespace sorting;
    using namespace std;
    vector<int> got = {15, 20, 3, 7};
    vector<int> expect = {3, 7, 15, 20};
    InsertionSort(got);
    REQUIRE(got == expect);
}