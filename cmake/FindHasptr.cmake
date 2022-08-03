find_path(
    HASPTR_INCLUDE_DIR libhasptr/hasptr.hpp 
    /usr/local/include 
    /usr/include
     ${CMAKE_SOURCE_DIR}/class-design/libhasptr/
    )

clog(${CMAKE_CURRENT_LIST_FILE} ${CMAKE_CURRENT_LIST_LINE} "CMAKE_SOURCE_DIR=${CMAKE_SOURCE_DIR}")

find_library(
    HASPTR_LIBRARY
    NAMES hasptr 
    PATHS /usr/lib /usr/local/lib ${CMAKE_BINARY_DIR}/lib
    )

if(HASPTR_INCLUDE_DIR AND HASPTR_LIBRARY)
    set(HASPTR_FOUND TRUE)
endif(HASPTR_INCLUDE_DIR AND HASPTR_LIBRARY)