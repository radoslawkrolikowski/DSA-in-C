cmake_minimum_required(VERSION 3.16.3)

project(QuickSort C)

set(MAIN_SOURCE_FILES
    main.c
    quick_sort.c
)

add_executable(quick_sort ${MAIN_SOURCE_FILES})
target_include_directories(quick_sort PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

