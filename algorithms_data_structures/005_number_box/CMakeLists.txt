cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 1)
set(PROJECT_VERSION_PATCH 0)
set(PROJECT_VERSION
  ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})

project(number_box VERSION ${PROJECT_VERSION})

set(LIB_DIR lib)

set(CMAKE_VERBOSE_MAKEFILE off)
set(CMAKE_BINARY_DIR bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(${LIB_DIR}/nbox)  # Add nbox library as part of build process

add_executable(${PROJECT_NAME} src/main.c)
target_link_libraries(${PROJECT_NAME} nbox)

