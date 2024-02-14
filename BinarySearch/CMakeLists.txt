cmake_minimum_required(VERSION 3.16.3)

project(BinarySearch C)

set(SOURCE_FILES
    main.c
    binary_search.c
)

add_executable(binary_search ${SOURCE_FILES})
target_include_directories(binary_search PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
