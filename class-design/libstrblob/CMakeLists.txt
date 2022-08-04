project(libstrblob)


file(GLOB_RECURSE SRCS ${PROJECT_NAME}/*.cpp)
file(GLOB_RECURSE HDRS ${PROJECT_NAME}/*.hpp)

set(TARGET strblob)

add_library(${TARGET} STATIC ${SRCS})

# For Static
set_target_properties(${TARGET} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# set_target_properties(${TARGET} PROPERTIES
#     LIBRARY_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR}/lib)

# clog(${CMAKE_CURRENT_LIST_FILE} ${CMAKE_CURRENT_LIST_LINE} "${CMAKE_BINARY_DIR}")

target_include_directories(
    ${TARGET} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

install(
    DIRECTORY libstrblob
    DESTINATION include
    FILES_MATCHING
    PATTERN "*.hpp"
)

install(TARGETS ${TARGET} DESTINATION lib)

# test ------------------------------------------------------------------------

set(TEST strblob.test)
add_executable(${TEST} tests/strblob.test.cpp)
target_compile_options(${TEST} PRIVATE -g)
target_include_directories(${TEST} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${TEST} strblob gtest)

# Third Patry Use Strblob
# find_package(strblob) 
# clog(${CMAKE_CURRENT_LIST_FILE} ${CMAKE_CURRENT_LIST_LINE} "STRBLOB_INCLUDE_DIR=${STRBLOB_INCLUDE_DIR}")
# clog(${CMAKE_CURRENT_LIST_FILE} ${CMAKE_CURRENT_LIST_LINE} "STRBLOB_LIBRARY=${STRBLOB_LIBRARY}")

# if(STRBLOB_FOUND)
#     set(TEST strblob.test)
#     clog(${CMAKE_CURRENT_LIST_FILE} ${CMAKE_CURRENT_LIST_LINE} "build test for libstrblob")
    
#     add_executable(${TEST} tests/strblob.test.cpp)
    
#     target_compile_options(${TEST} PRIVATE -g)
#     target_include_directories(${TEST} PRIVATE ${STRBLOB_INCLUDE_DIR})
#     target_link_libraries(${TEST} ${STRBLOB_LIBRARY} gtest)
# else(STRBLOB_FOUND)
# endif(STRBLOB_FOUND)

# -----------------------------------------------------------------------------