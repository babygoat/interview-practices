//
// Created by 曾清陽 on 2021/7/15.
//

#include <vector>
#include <catch.hpp>
#include <selection_sort.h>

TEST_CASE("selection sort test", "[sorting]"){
    using namespace sorting;
    using namespace std;
    vector<int> got = {15, 20, 3, 7};
    vector<int> expect = {3, 7, 15, 20};
    SelectionSort(got);
    REQUIRE(got == expect);
}
