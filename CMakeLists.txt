cmake_minimum_required(VERSION 3.20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(cpp-primer-class-design VERSION 1.0)

# Set CXXFLAGS
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS -g)

add_subdirectory(class-design)
add_subdirectory(tests)
