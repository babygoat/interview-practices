//
// Created by 曾清陽 on 2021/4/10.
//

#include <vector>
#include <catch.hpp>
#include <heap_sort.h>

TEST_CASE("heap sort test", "[sorting]"){
    using namespace sorting;
    using namespace std;
    vector<int> got = {15, 20, 3, 7};
    vector<int> expect = {3, 7, 15, 20};
    HeapSort(got);
    REQUIRE(got == expect);

    vector<int> empty = {};
    expect = {};
    HeapSort(empty);
    REQUIRE(empty == expect);

    vector<int> odd_elements_case = {100, 80, 60, 50, 30, 20, 10};
    expect = {10, 20, 30, 50, 60, 80, 100};
    HeapSort(odd_elements_case);
    REQUIRE(odd_elements_case == expect);

    vector<int> element_duplicates_case = {50, 50, 30, 20, 70, 90, 90, 80};
    expect = {20, 30, 50, 50, 70, 80, 90, 90};
    HeapSort(element_duplicates_case);
    REQUIRE(element_duplicates_case == expect);
}