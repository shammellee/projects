cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(state_machine VERSION 0.1.0)

set(CMAKE_VERBOSE_MAKEFILE off)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

add_executable(${PROJECT_NAME} src/main.c)
target_include_directories(${PROJECT_NAME} PUBLIC lib)

