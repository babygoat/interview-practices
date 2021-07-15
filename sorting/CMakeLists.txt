set(TARGET_NAME sorting)

add_library(${TARGET_NAME} insertion_sort.cpp insertion_sort.h quick_sort.cpp quick_sort.h merge_sort.cpp merge_sort.h heap_sort.h heap_sort.cpp heap_sort.h counting_sort.cpp counting_sort.h bucket_sort.cpp bucket_sort.h radix_sort.cpp radix_sort.h ../search/binary_search.cpp ../search/binary_search.h selection_sort.cpp selection_sort.h)

target_include_directories(${TARGET_NAME} INTERFACE ./)