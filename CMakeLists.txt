cmake_minimum_required(VERSION 3.0.2)
project(SOGL)

function(static_compile p)
    target_compile_options( ${p}
        PUBLIC "/MT$<$<STREQUAL:$<CONFIGURATION>,Debug>:d>"
    )
endfunction()

set(CMAKE_CXX_FLAGS_RELEASE "/MT -O2" CACHE INTERNAL "" FORCE)
set(CMAKE_CXX_FLAGS_DEBUG "/MTd -O2" CACHE INTERNAL "" FORCE)

set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE INTERNAL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "" FORCE)
set(USE_MSVC_RUNTIME_LIBRARY_DLL OFF CACHE INTERNAL "" FORCE)

add_subdirectory(lib/glfw EXCLUDE_FROM_ALL)
include_directories(lib/glfw/include)
static_compile(glfw)

add_subdirectory(lib/glew/build/cmake EXCLUDE_FROM_ALL)
include_directories(lib/glew/include)
static_compile(glew_s)


file(GLOB_RECURSE SOURCE_LIST "src/*.cpp" "src/*.h")
add_executable(SOGL ${SOURCE_LIST})

find_package(OpenGL REQUIRED)
target_link_libraries(SOGL glew_s glfw ${OPENGL_LIBRARIES})