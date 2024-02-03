cmake_minimum_required(VERSION 3.16.3)
    
project(DynamicArray C)

set(SOURCE_FILES
    main.c
    dynamic_array.c
)

add_executable(dynamic_array ${SOURCE_FILES})
target_include_directories(dynamic_array PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

set(TEST_SOURCE_FILES
    test.c
    dynamic_array.c
)

add_executable(dynamic_array_tests ${TEST_SOURCE_FILES})
target_include_directories(dynamic_array_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

enable_testing()

add_test(NAME DynamicArrayTests COMMAND dynamic_array_tests)