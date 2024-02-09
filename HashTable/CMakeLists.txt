cmake_minimum_required(VERSION 3.16.3)

project(HashTable C)

#set(SOURCE_FILES
#    main.c
#    linked_lists.c
#)

#add_executable(linked_lists ${SOURCE_FILES})
#target_include_directories(linked_lists PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

set(TEST_SOURCE_FILES
    test.c
    hash_table.c
)

add_executable(hash_table_tests ${TEST_SOURCE_FILES})
target_include_directories(hash_table_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

enable_testing()

add_test(NAME HashTableTests COMMAND hash_table_tests)
