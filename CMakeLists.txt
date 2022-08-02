project(cpp-primer-class-design)

cmake_minimum_required(VERSION 3.22)

set(CMAKE_EXPORT_COMPILE_COMMAND ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++14")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(Logger)

add_subdirectory(class-design)
add_subdirectory(googletest)




