#include <gtest/gtest.h>
#include <iostream>
#include <libhasptr/hasptr.hpp>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

TEST(HasPtrTest, TestCounter) {

    // Test initial constructer counter
    HasPtr p1("Hiya!");
    EXPECT_EQ(1, *p1.use());

    // Test self assignment
    p1 = p1;
    EXPECT_EQ(1, *p1.use());

    // Test copy constructor counter
    HasPtr p2(p1);
    EXPECT_EQ(2, *p1.use());
    EXPECT_EQ(2, *p2.use());

    // Test copy assignment counter
    HasPtr p3("Tmp");
    EXPECT_EQ(1, *p3.use());

    size_t* addr = p3.use();

    p3 = p2;

    EXPECT_EQ(*addr, 0);
    EXPECT_EQ(3, *p1.use());
    EXPECT_EQ(3, *p2.use());
    EXPECT_EQ(3, *p3.use());
}

TEST(HasPtrTest, TestSwap) {
    HasPtr lhs("lhs");
    HasPtr rhs("rhs");

    swap(lhs, rhs);
    EXPECT_EQ(*lhs.ps(), "rhs");
    EXPECT_EQ(*rhs.ps(), "lhs");
}

TEST(HasPtrTest, TestCmpOpt) {
    // ex 13.31
    string         ex_str = "abc a ab abcde abcd abcdefg abcdef";
    istringstream  iss(ex_str);
    vector<HasPtr> v;

    string word;
    while (iss >> word) v.push_back(word);
    std::sort(v.begin(), v.end());

    for (auto it = v.begin(); it != v.end(); it++) {
        if (it != --v.end()) { EXPECT_EQ(1, *it->ps() < *(it + 1)->ps()); }
    }
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
