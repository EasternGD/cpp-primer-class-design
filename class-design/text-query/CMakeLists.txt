project(text-query)

file(GLOB_RECURSE SRCS *.cpp)
file(GLOB_RECURSE HDRS *.hpp)

set(TARGET test-query.test)

add_executable(${TARGET} ${SRCS})

target_include_directories(
    ${TARGET} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)


