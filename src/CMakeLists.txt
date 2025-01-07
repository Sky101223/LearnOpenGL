project(src)

add_library(GLAD_LIB SHARED glad.c)

target_include_directories(GLAD_LIB
    PUBLIC
    ${INCLUDE_DIR}
)
include_directories(${GLFW_INCLUDE_DIR})

add_executable(Main Main.cpp)

target_link_libraries(Main PRIVATE GLAD_LIB ${GLFW_DLL})