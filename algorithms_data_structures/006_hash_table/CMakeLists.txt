cmake_minimum_required(VERSION 3.1)

set(CMAKE_VERBOSE_MAKEFILE off)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

project(HashTable
  VERSION 0.1.0
  LANGUAGES C
)

add_executable(main src/main.c src/hash_table.c)

