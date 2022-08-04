find_path(
    STRBLOB_INCLUDE_DIR libstrblob/strblob.hpp 
    /usr/local/include 
    /usr/include
     ${CMAKE_SOURCE_DIR}/class-design/libstrblob
    )

# clog(${CMAKE_CURRENT_LIST_FILE} ${CMAKE_CURRENT_LIST_LINE} "CMAKE_SOURCE_DIR=${CMAKE_SOURCE_DIR}")

find_library(
    STRBLOB_LIBRARY
    NAMES strblob 
    PATHS /usr/lib /usr/local/lib ${CMAKE_BINARY_DIR}/lib
    )

if(STRBLOB_INCLUDE_DIR AND STRBLOB_LIBRARY)
    set(STRBLOB_FOUND TRUE)
endif(STRBLOB_INCLUDE_DIR AND STRBLOB_LIBRARY)