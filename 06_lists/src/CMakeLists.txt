cmake_minimum_required(VERSION 3.10)
project(06_lists)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../lib)

add_library(List list.c)
add_library(circularList circularList.c)

add_executable(sortedList sortedList.c)
target_link_libraries(sortedList List)

add_executable(josephus josephusProblem.c)
target_link_libraries(josephus circularList)

add_compile_options(-Wall -Wextra -pedantic)