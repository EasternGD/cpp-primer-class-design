project(cpp-primer-class-design)

cmake_minimum_required(VERSION 3.22)

set(CMAKE_EXPORT_COMPILE_COMMAND ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++14")

add_subdirectory(class-design)
add_subdirectory(googletest)




