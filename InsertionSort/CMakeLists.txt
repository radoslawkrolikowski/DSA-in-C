cmake_minimum_required(VERSION 3.16.3)

project(InsertionSort C)

set(MAIN_SOURCE_FILES
    main.c
    insertion_sort.c
)

add_executable(insertion_sort ${MAIN_SOURCE_FILES})
target_include_directories(insertion_sort PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

