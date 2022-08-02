find_path(
    HASPTR_INCLUDE_DIR hasptr.hpp 
    /usr/local/include/libhasptr 
    /usr/include/libhasptr
     ${CMAKE_SOURCE_DIR}/ModuleMode
    )

find_library(
    HASPTR_LIBRARY
    NAMES hasptr 
    PATHS /usr/lib /usr/local/lib ${CMAKE_SOURCE_DIR}/ModuleMode
    )

if(HASPTR_INCLUDE_DIR　AND HASPTR_LIBRARY)
    set(HASPTR_FOUND TRUE)
endif(HASPTR_INCLUDE_DIR　AND HASPTR_LIBRARY)