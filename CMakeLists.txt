cmake_minimum_required(VERSION 3.20)

# Logger -----------------------------------------------------------------------
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
# ------------------------------------------------------------------------------
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set the project name and version
project(text-query VERSION 1.0)

# Set CXXFLAGS
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_C_FLAGS -O2)


log("-- CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
log("-- CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")

# ------------------------------------------------------------------------------
# Google Test Tool
# ------------------------------------------------------------------------------
add_subdirectory(lib/googletest)
enable_testing()
include_directories(
    ${gtest_SOURCE_DIR}
    ${gtest_SOURCE_DIR}/include
    )
# ------------------------------------------------------------------------------
# Text Query
# ------------------------------------------------------------------------------
set(
    TEXT_QUERY 
    src/text-query/text_query.cc
    src/text-query/query_result.cc
    src/text-query/test.cc
)

add_executable(text_query ${TEXT_QUERY})

target_include_directories(text_query PUBLIC inc/text-query)

log("-- Target: text_query")
# ------------------------------------------------------------------------------
# StrBlob
# ------------------------------------------------------------------------------

set(
    STRBLOB_TEST 
    src/strblob/strblob.cc
    tests/strblob_test.cc
)

add_executable(strblob_test ${STRBLOB_TEST})

target_link_libraries(
    strblob_test
    gtest
    gtest_main
)

target_include_directories(strblob_test PUBLIC inc/strblob)

add_test(strblob_test strblob_test)
log("-- Target: strblob_test")
# ------------------------------------------------------------------------------
