file(GLOB_RECURSE src CONFIGURE_DEPENDS "*.c" "*.h")
add_library(QuIL STATIC ${src})
target_include_directories(QuIL PUBLIC "")

target_link_libraries(QuIL PRIVATE glfw)

set_target_properties(QuIL PROPERTIES LINKER_LANGUAGE C)