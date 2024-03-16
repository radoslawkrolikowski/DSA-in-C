cmake_minimum_required(VERSION 3.16.3)

project(CountingSort C)

set(MAIN_SOURCE_FILES
    main.c
    counting_sort.c
)

add_executable(counting_sort ${MAIN_SOURCE_FILES})
target_include_directories(counting_sort PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

