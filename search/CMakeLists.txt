set(TARGET_NAME search)

add_library(${TARGET_NAME} binary_search.cpp binary_search.h)

target_include_directories(${TARGET_NAME} INTERFACE ./)