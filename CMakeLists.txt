cmake_minimum_required(VERSION 3.31)
project(QuIL C)
set(CMAKE_C_STANDARD 17)

add_subdirectory(submodules/glfw)
add_subdirectory(examples)
add_subdirectory(src)