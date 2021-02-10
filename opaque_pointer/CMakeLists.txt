cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(opaque_ptr VERSION 0.1.0)

set(CMAKE_VERBOSE_MAKEFILE off)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
set(LIB_DIR lib)

add_subdirectory(${LIB_DIR})

add_executable(${PROJECT_NAME} src/main.c)
target_link_libraries(${PROJECT_NAME} PUBLIC link)

