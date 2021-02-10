cmake_minimum_required(VERSION 3.1)

project(main
  VERSION 0.1.0
  DESCRIPTION "Lists all prime numbers from 2 to n"
  LANGUAGES C
)

set(CMAKE_VERBOSE_MAKEFILE off)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
set(DIR_PRIME lib/prime)
set(SOURCES
  src/${PROJECT_NAME}.c
  ${DIR_PRIME}/prime.c
  ${DIR_PRIME}/prime.h
)
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE lib/prime)

