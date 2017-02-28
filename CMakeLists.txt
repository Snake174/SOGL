cmake_minimum_required(VERSION 3.0)
project(SOGL)

macro ( mark_as_internal _var )
  set ( ${_var} ${${_var}} CACHE INTERNAL "hide this!" FORCE )
endmacro( mark_as_internal _var ) 

set(CMAKE_CXX_FLAGS_RELEASE "/MT" CACHE INTERNAL "" FORCE)
set(CMAKE_CXX_FLAGS_DEBUG "/MTd" CACHE INTERNAL "" FORCE)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(USE_MSVC_RUNTIME_LIBRARY_DLL OFF CACHE BOOL "" FORCE)

add_subdirectory(lib/glfw)
include_directories(lib/glfw/include)

add_subdirectory(lib/glew/build/cmake)
include_directories(lib/glew/include)

mark_as_internal(GLFW_BUILD_DOCS)
mark_as_internal(GLFW_BUILD_TESTS)
mark_as_internal(GLFW_BUILD_EXAMPLES)
mark_as_internal(GLEW_OSMESA)
mark_as_internal(GLEW_REGAL)
mark_as_internal(GLFW_DOCUMENT_INTERNALS)
mark_as_internal(GLFW_INSTALL)
mark_as_internal(GLFW_USE_HYBRID_HPG)
mark_as_internal(GLFW_VULKAN_STATIC)
mark_as_internal(LIB_SUFFIX)
mark_as_internal(BUILD_UTILS)
mark_as_internal(BUILD_SHARED_LIBS)
mark_as_internal(USE_MSVC_RUNTIME_LIBRARY_DLL)

file(GLOB_RECURSE SOURCE_LIST "src/*.cpp" "src/*.h")
add_executable(SOGL ${SOURCE_LIST})

find_package(OpenGL REQUIRED)
target_link_libraries(SOGL glew_s glfw ${OPENGL_LIBRARIES})