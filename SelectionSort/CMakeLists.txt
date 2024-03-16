cmake_minimum_required(VERSION 3.16.3)

project(SelectionSort C)

set(MAIN_SOURCE_FILES
    main.c
    selection_sort.c
)

add_executable(selection_sort ${MAIN_SOURCE_FILES})
target_include_directories(selection_sort PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

