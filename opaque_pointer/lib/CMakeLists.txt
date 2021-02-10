set(LIB_NAME link)
add_library(${LIB_NAME} OBJECT ${LIB_NAME}/${LIB_NAME}.c)
target_include_directories(${LIB_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/${LIB_NAME})

