project(libstrvec)


file(GLOB_RECURSE SRCS ${PROJECT_NAME}/*.cpp)
file(GLOB_RECURSE HDRS ${PROJECT_NAME}/*.hpp)

set(TARGET strvec)

add_library(${TARGET} ${SRCS})

set_target_properties(${TARGET} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# clog(${CMAKE_CURRENT_LIST_FILE} ${CMAKE_CURRENT_LIST_LINE} "${CMAKE_BINARY_DIR}")

target_include_directories(
    ${TARGET} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

target_compile_options(${TARGET} PRIVATE -g)

install(
    DIRECTORY libstrvec 
    DESTINATION include
    FILES_MATCHING
    PATTERN "*.hpp"
)

install(TARGETS ${TARGET} DESTINATION lib)

# test ------------------------------------------------------------------------

set(TEST strvec.test)
add_executable(${TEST} tests/strvec.test.cpp)
target_compile_options(${TEST} PRIVATE -g)
target_include_directories(${TEST} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${TEST} strvec gtest)

# find_package(strvec) 
# clog(${CMAKE_CURRENT_LIST_FILE} ${CMAKE_CURRENT_LIST_LINE} "strvec_INCLUDE_DIR=${strvec_INCLUDE_DIR}")
# clog(${CMAKE_CURRENT_LIST_FILE} ${CMAKE_CURRENT_LIST_LINE} "strvec_LIBRARY=${strvec_LIBRARY}")

# if(strvec_FOUND)
    # set(TEST strvec.test)
    # clog(${CMAKE_CURRENT_LIST_FILE} ${CMAKE_CURRENT_LIST_LINE} "build test for libstrvec")
    
#     add_executable(${TEST} tests/strvec.test.cpp)
    
#     target_compile_options(${TEST} PRIVATE -g)
#     target_include_directories(${TEST} PRIVATE ${strvec_INCLUDE_DIR})
#     target_link_libraries(${TEST} ${strvec_LIBRARY} gtest)
# else(strvec_FOUND)
# endif(strvec_FOUND)

# -----------------------------------------------------------------------------