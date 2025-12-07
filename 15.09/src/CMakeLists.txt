cmake_minimum_required(VERSION 3.10)
project(03_compilation)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../lib)

add_executable(bracketsChecker 1.c)
add_executable(substrCount 2.c)
add_executable(zeroElementsCount 3.c)

add_compile_options(-Wall -Wextra -pedantic)
