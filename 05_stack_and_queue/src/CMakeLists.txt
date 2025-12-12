cmake_minimum_required(VERSION 3.10)
project(Stack_and_queue)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../lib)

add_library(Stack stack.c)

add_executable(sortStation sortStation.c)
add_executable(bracketsChecker bracketsChecker.c)

target_link_libraries(sortStation Stack)
target_link_libraries(bracketsChecker Stack)

add_compile_options(-Wall -Wextra -pedantic)
