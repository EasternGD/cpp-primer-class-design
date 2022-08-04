find_path(
    MAIL_HANDLE_INCLUDE_DIR libmail-handle/mail-handle.hpp 
    /usr/local/include 
    /usr/include
     ${CMAKE_SOURCE_DIR}/class-design/libmail-handle/
    )

# clog(${CMAKE_CURRENT_LIST_FILE} ${CMAKE_CURRENT_LIST_LINE} "CMAKE_SOURCE_DIR=${CMAKE_SOURCE_DIR}")

find_library(
    MAIL_HANDLE_LIBRARY
    NAMES mail-handle 
    PATHS /usr/lib /usr/local/lib ${CMAKE_BINARY_DIR}/lib
    )

if(MAIL_HANDLE_INCLUDE_DIR AND MAIL_HANDLE_LIBRARY)
    set(MAIL_HANDLE_FOUND TRUE)
endif(MAIL_HANDLE_INCLUDE_DIR AND MAIL_HANDLE_LIBRARY)