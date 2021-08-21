cmake_minimum_required(VERSION 3.20)

# Set Color
if(WIN32)
    set(COLOR_MSG_SUPPORTED FALSE)
else()
    set(COLOR_MSG_SUPPORTED TRUE)
endif()

string (ASCII 27 Esc)
set(ColourReset "${Esc}[m")
set(GREEN "${Esc}[1;32m")

function(log MESSAGE)
    message("${GREEN}${MESSAGE}${ColourReset}")
endfunction(log)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set the project name and version
project(text-query VERSION 1.0)

# Set CXXFLAGS
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_C_FLAGS -O2)

log("-- CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
log("-- CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")

set(SOURCES src/text_query.cc
            src/query_result.cc
            src/main.cc)

add_executable(text_query ${SOURCES})

target_include_directories(text_query PUBLIC inc/)

