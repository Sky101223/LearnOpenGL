project(src)

add_library(LIB SHARED ${LIB_FILES})

target_include_directories(LIB PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(Main 05-Math/learnGlm.cpp)

target_link_libraries(Main PUBLIC LIB ${GLFW_DLL})
