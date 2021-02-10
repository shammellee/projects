set(LIB_NAME nbox)
add_library(${LIB_NAME} OBJECT ${LIB_NAME}.c)

# Require anyone linking to nbox to include the current source directory.
target_include_directories(${LIB_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

