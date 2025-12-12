cmake_minimum_required(VERSION 3.10)
project(02_styleguide)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../lib)

add_executable(polynimialCalculation 1.c)
add_executable(incompleteQuotient 2.c)
add_executable(arrayFlipping 3.c)
add_executable(luckyTickets 4.c)

add_compile_options(-Wall -Wextra -pedantic)
