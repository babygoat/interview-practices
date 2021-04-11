set(UNIT_TEST_LIST insertion_sort quick_sort)

foreach (NAME IN LISTS UNIT_TEST_LIST)
    list(APPEND UNIT_TEST_SOURCE_LIST ${NAME}_test.cpp)
endforeach ()

set(TARGET_NAME tests)

add_executable(${TARGET_NAME} main_test.cpp ${UNIT_TEST_SOURCE_LIST} merge_sort_test.cpp heap_sort_test.go.cpp  counting_sort_test.cpp bucket_sort_test.cpp radix_sort_test.cpp)

target_link_libraries(${TARGET_NAME} PUBLIC sorting)
target_include_directories(${TARGET_NAME} PUBLIC ../lib/catch2/)
