cmake_minimum_required(VERSION 3.16.3)

project(Heap C)

set(TEST_SOURCE_FILES
    test.c
    heap.c
)

add_executable(heap_tests ${TEST_SOURCE_FILES})
target_include_directories(heap_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

enable_testing()

add_test(NAME HeapTests COMMAND heap_tests)
