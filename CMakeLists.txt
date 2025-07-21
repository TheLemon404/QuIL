cmake_minimum_required(VERSION 3.31)
project(QuIL C)
set(CMAKE_C_STANDARD 11)

add_subdirectory(dependencies/glfw-3.4)

file(GLOB_RECURSE SRC "src/.c" "src/.h")
add_library(QuIL STATIC SRC)

target_link_libraries(QuIL PRIVATE glfw)

set_target_properties(QuIL PROPERTIES LINKER_LANGUAGE C)