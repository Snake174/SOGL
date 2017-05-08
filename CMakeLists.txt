cmake_minimum_required(VERSION 3.0.2)
project(SOGL)

option(BUILD_EXAMPLES "Build examples" ON)

function(static_compile p)
    target_compile_options(${p}
        PUBLIC "/MT$<$<STREQUAL:$<CONFIGURATION>,Debug>:d>"
    )
endfunction()

macro ( mark_as_internal _var )
  set ( ${_var} ${${_var}} CACHE INTERNAL "hide this!" FORCE )
endmacro( mark_as_internal _var ) 

set(CMAKE_CXX_FLAGS_RELEASE "/MT -O2" CACHE INTERNAL "" FORCE)
set(CMAKE_CXX_FLAGS_DEBUG "/MTd -O2" CACHE INTERNAL "" FORCE)

set(BUILD_UTILS OFF CACHE INTERNAL "" FORCE)
set(GLFW_INSTALL OFF CACHE INTERNAL "" FORCE)
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


include_directories(lib/glm/glm)

include_directories(lib/stb)
include_directories(include)

mark_as_internal(GLEW_OSMESA)
mark_as_internal(GLEW_REGAL)
mark_as_internal(GLFW_DOCUMENT_INTERNALS)
mark_as_internal(GLFW_USE_HYBRID_HPG)
mark_as_internal(GLFW_VULKAN_STATIC)

file(GLOB_RECURSE SOURCE_LIST "src/*.cpp" "include/*.h")
add_library(SOGL STATIC ${SOURCE_LIST})

find_package(OpenGL REQUIRED)
target_link_libraries(SOGL glew_s glfw ${OPENGL_LIBRARIES})

if(BUILD_EXAMPLES)
	add_subdirectory(examples)
endif()