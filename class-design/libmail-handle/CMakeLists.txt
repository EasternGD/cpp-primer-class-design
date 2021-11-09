project(mail-hanlde)

set(HDR libmail-handle/mail_handle.hpp)
set(SRC libmail-handle/mail_handle.cpp)
set(TEST_SRC tests/mail_handle.test.cpp)

if(TEST_MODE)
    enable_testing()
    set(TARGET_NAME mail_handle.test)
    add_executable(${TARGET_NAME} ${TEST_SRC} ${SRC})

    target_link_libraries(${TARGET_NAME} PUBLIC gtest_main)

else()
    set(TARGET_NAME mail_handle)
    add_library(${TARGET_NAME} STATIC ${HDR} ${SRC})
endif(TEST_MODE)

target_include_directories(${TARGET_NAME}
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    )

