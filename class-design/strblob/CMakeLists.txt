project(strblob)

set(HDR libstrblob/strblob.h)
set(SRC libstrblob/strblob.cc)
set(TEST_SRC tests/strblob.test.cc)

if(TEST_MODE)
    enable_testing()
    set(TARGET_NAME strblob.test)
    add_executable(${TARGET_NAME} ${TEST_SRC} ${SRC})

    target_link_libraries(${TARGET_NAME} PUBLIC gtest_main)

else()
    set(TARGET_NAME strblob)
    add_library(${TARGET_NAME} STATIC ${HDR} ${SRC})
endif(TEST_MODE)

target_include_directories(${TARGET_NAME}
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    )

