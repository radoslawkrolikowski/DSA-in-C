cmake_minimum_required(VERSION 3.16.3)
    
project(Queue C)

set(SOURCE_FILES
    main.c
    queue.c
)

add_executable(queue ${SOURCE_FILES})
target_include_directories(queue PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

set(TEST_SOURCE_FILES
    test.c
    queue.c
)

add_executable(queue_tests ${TEST_SOURCE_FILES})
target_include_directories(queue_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

enable_testing()

add_test(NAME QueueTests COMMAND queue_tests)