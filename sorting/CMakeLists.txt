set(TARGET_NAME sorting)

add_library(${TARGET_NAME} insertion_sort.cpp insertion_sort.h quick_sort.cpp quick_sort.h)

target_include_directories(${TARGET_NAME} INTERFACE ./)