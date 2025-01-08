cmake_minimum_required(VERSION 3.31.0)

project(LearnOpenGL
    VERSION 0.0.1
    DESCRIPTION "How to Learn OpenGL"
    HOMEPAGE_URL "https://github.com/Sky101223/LearnOpenGL"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(GLFW_DLL "D:/GLFW_DLL/lib-mingw-w64/glfw3.dll")

aux_source_directory(${PROJECT_SOURCE_DIR}/lib LIB_FILES)

include_directories(include)

add_subdirectory(src)