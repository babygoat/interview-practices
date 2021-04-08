set(UNIT_TEST_LIST insertion_sort)

foreach (NAME IN LISTS UNIT_TEST_LIST)
    list(APPEND UNIT_TEST_SOURCE_LIST ${NAME}_test.cpp)
endforeach ()

set(TARGET_NAME tests)

add_executable(${TARGET_NAME} main_test.cpp ${UNIT_TEST_SOURCE_LIST})

target_link_libraries(${TARGET_NAME} PUBLIC sorting)
target_include_directories(${TARGET_NAME} PUBLIC ../lib/catch2/)
