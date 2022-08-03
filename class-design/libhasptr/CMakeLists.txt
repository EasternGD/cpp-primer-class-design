project(libhasptr)


file(GLOB_RECURSE SRCS ${PROJECT_NAME}/*.cpp)
file(GLOB_RECURSE HDRS ${PROJECT_NAME}/*.hpp)

set(TARGET hasptr)

add_library(${TARGET} SHARED ${SRCS})

set_target_properties(${TARGET} PROPERTIES
         LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# clog(${CMAKE_CURRENT_LIST_FILE} ${CMAKE_CURRENT_LIST_LINE} "${CMAKE_BINARY_DIR}")

target_include_directories(
    ${TARGET} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

install(
    DIRECTORY libhasptr 
    DESTINATION include
    FILES_MATCHING
    PATTERN "*.hpp"
)

install(TARGETS ${TARGET} DESTINATION lib)

# test

find_package(hasptr) 
clog(${CMAKE_CURRENT_LIST_FILE} ${CMAKE_CURRENT_LIST_LINE} "HASPTR_INCLUDE_DIR=${HASPTR_INCLUDE_DIR}")
clog(${CMAKE_CURRENT_LIST_FILE} ${CMAKE_CURRENT_LIST_LINE} "HASPTR_LIBRARY=${HASPTR_LIBRARY}")

if(HASPTR_FOUND)
    set(TEST hasptr.test)
    clog(${CMAKE_CURRENT_LIST_FILE} ${CMAKE_CURRENT_LIST_LINE} "build test for libhasptr")
    
    add_executable(${TEST} tests/hasptr.test.cpp)
    
    target_compile_options(${TEST} PRIVATE -g)
    target_include_directories(${TEST} PRIVATE ${HASPTR_INCLUDE_DIR})
    target_link_libraries(${TEST} ${HASPTR_LIBRARY} gtest)
else(HASPTR_FOUND)
endif(HASPTR_FOUND)