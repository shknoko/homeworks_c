cmake_minimum_required(VERSION 3.10)
project(Comparing_binary)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../lib)

add_library(compare compare.c)

add_executable(comparing main.c)
target_link_libraries(comparing compare)

add_compile_options(-Wall -Wextra -pedantic)

enable_testing()
add_executable(tests ../tests/tests.c)
target_link_libraries(tests compare)
add_test(NAME tests COMMAND tests)