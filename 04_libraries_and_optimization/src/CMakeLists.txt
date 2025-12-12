cmake_minimum_required(VERSION 3.10)
project(04_libraries)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../lib)

add_library(selectionSort sort.c)
add_executable(app main.c)
target_link_libraries(app selectionSort)

add_compile_options(-Wall -Wextra -pedantic)
