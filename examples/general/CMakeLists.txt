cmake_minimum_required(VERSION 3.31)
project(QuIL_examples_general C)
set(CMAKE_C_STANDARD 17)

add_executable(QuIL_examples_general general_example.c)

target_link_libraries(QuIL_examples_general PRIVATE QuIL glfw)
