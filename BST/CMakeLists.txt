cmake_minimum_required(VERSION 3.16.3)

project(BinarySearchTree C)


set(MAIN_SOURCE_FILES
    main.c
    bst.c
)

add_executable(bst_main ${MAIN_SOURCE_FILES})
target_include_directories(bst_main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

set(TEST_SOURCE_FILES
    test.c
    bst.c
)

add_executable(bst_tests ${TEST_SOURCE_FILES})
target_include_directories(bst_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

enable_testing()

add_test(NAME BinarySearchTreeTests COMMAND bst_tests)
