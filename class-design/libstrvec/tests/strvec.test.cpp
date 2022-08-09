#include <gtest/gtest.h>
#include <iostream>
#include <libstrvec/strvec.hpp>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

TEST(StrVecTest, TestCreator) {
    StrVec sv;
    EXPECT_EQ(0, sv.size());
    EXPECT_EQ(0, sv.capacity());
}

TEST(StrVecTest, TestPushBack) {
    StrVec sv;
    sv.push_back("test");

    EXPECT_EQ(1, sv.size());
    EXPECT_EQ(1, sv.capacity());
    EXPECT_STREQ("test", sv.back().data());
}

TEST(StrVecTest, TestCopyConstructor) {
    StrVec tmp;
    tmp.push_back("test");
    StrVec sv(tmp);
    EXPECT_STREQ("test", sv.back().data());
}

TEST(StrVecTest, TestCopyAssignmentOperator) {
    StrVec tmp;
    tmp.push_back("test");
    StrVec sv;
    sv.push_back("tmp");
    sv = tmp;
    EXPECT_STREQ("test", sv.back().data());
}

TEST(StrVecTest, TestReserve) {
    StrVec sv;
    sv.push_back("test");
    EXPECT_EQ(1, sv.capacity());

    sv.reserve(100);
    EXPECT_EQ(100, sv.capacity());
    EXPECT_STREQ("test", sv.back().data());
    
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
