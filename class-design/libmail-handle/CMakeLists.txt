project(libmail-handle)


file(GLOB_RECURSE SRCS ${PROJECT_NAME}/*.cpp)
file(GLOB_RECURSE HDRS ${PROJECT_NAME}/*.hpp)

set(TARGET mail-handle)

add_library(${TARGET} STATIC ${SRCS})

# For Static
set_target_properties(${TARGET} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# set_target_properties(${TARGET} PROPERTIES
#     LIBRARY_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR}/lib)

clog(${CMAKE_CURRENT_LIST_FILE} ${CMAKE_CURRENT_LIST_LINE} "${CMAKE_BINARY_DIR}")

target_include_directories(
    ${TARGET} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

install(
    DIRECTORY libmail-handle 
    DESTINATION include
    FILES_MATCHING
    PATTERN "*.hpp"
)

install(TARGETS ${TARGET} DESTINATION lib)

# test ------------------------------------------------------------------------

find_package(mail-handle) 
clog(${CMAKE_CURRENT_LIST_FILE} ${CMAKE_CURRENT_LIST_LINE} "MAIL_HANDLE_INCLUDE_DIR=${MAIL_HANDLE_INCLUDE_DIR}")
clog(${CMAKE_CURRENT_LIST_FILE} ${CMAKE_CURRENT_LIST_LINE} "MAIL_HANDLE_LIBRARY=${MAIL_HANDLE_LIBRARY}")

if(MAIL_HANDLE_FOUND)
    set(TEST mail-handle.test)
    clog(${CMAKE_CURRENT_LIST_FILE} ${CMAKE_CURRENT_LIST_LINE} "build test for libmail-handle")
    
    add_executable(${TEST} tests/mail-handle.test.cpp)
    
    target_compile_options(${TEST} PRIVATE -g)
    target_include_directories(${TEST} PRIVATE ${MAIL_HANDLE_INCLUDE_DIR})
    target_link_libraries(${TEST} ${MAIL_HANDLE_LIBRARY} gtest)
else(MAIL_HANDLE_FOUND)
endif(MAIL_HANDLE_FOUND)

# -----------------------------------------------------------------------------