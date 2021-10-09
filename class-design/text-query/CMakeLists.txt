project(text-query)

set(HDR libtext-query/text_query.h libtext-query/query_result.h)
set(SRC libtext-query/text_query.cc libtext-query/query_result.cc)
set(TEST_SRC tests/text_query.test.cc)

if(TEST_MODE)
    # enable_testing()
    set(TARGET_NAME text_query.test)
    add_executable(${TARGET_NAME} ${TEST_SRC} ${SRC})

    # target_link_libraries(${TARGET_NAME} PUBLIC gtest_main)

else()
    set(TARGET_NAME text_query)
    add_library(${TARGET_NAME} STATIC ${HDR} ${SRC})
endif(TEST_MODE)

target_include_directories(${TARGET_NAME}
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    )

