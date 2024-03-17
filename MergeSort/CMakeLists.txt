cmake_minimum_required(VERSION 3.16.3)

project(MergeSort C)

set(MAIN_SOURCE_FILES
    main.c
    merge_sort.c
)

add_executable(merge_sort ${MAIN_SOURCE_FILES})
target_include_directories(merge_sort PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

