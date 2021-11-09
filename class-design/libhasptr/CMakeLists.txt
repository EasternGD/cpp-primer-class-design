project(hasptr)

set(HDR libhasptr/hasptr.h)
set(SRC libhasptr/hasptr.cc)
set(TEST_SRC tests/hasptr.test.cc)

if(TEST_MODE)
    enable_testing()
    set(TARGET_NAME hasptr.test)
    add_executable(${TARGET_NAME} ${TEST_SRC} ${SRC})

    target_link_libraries(${TARGET_NAME} PUBLIC gtest_main)

else()
    set(TARGET_NAME hasptr)
    add_library(${TARGET_NAME} STATIC ${HDR} ${SRC})
endif(TEST_MODE)

target_include_directories(${TARGET_NAME}
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    )

