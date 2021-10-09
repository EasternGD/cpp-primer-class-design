#include <gtest/gtest.h>
#include <iostream>
#include <libhasptr/hasptr.h>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

TEST(HasPtrTest, TestCounter) {

    // Test initial constructer counter
    HasPtr p1("Hiya!");
    auto   c1 = p1.use();
    EXPECT_EQ(1, *c1);

    // Test self assignment
    p1 = p1;
    c1 = p1.use();
    EXPECT_EQ(1, *c1);

    // Test copy constructor counter
    HasPtr p2(p1);
    auto   c2 = p2.use();
    EXPECT_EQ(2, *c1);
    EXPECT_EQ(2, *c2);

    // Test copy assignment counter
    HasPtr p3 = p2;
    auto   c3 = p3.use();
    EXPECT_EQ(3, *c1);
    EXPECT_EQ(3, *c2);
    EXPECT_EQ(3, *c3);
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
    string ex_str = "Give your class a < operator and define a vector of "
                    "HasPtrs. Give that vector some elements and then the "
                    "vector. Note when swap is called.";
    istringstream  iss(ex_str);
    vector<HasPtr> v;

    string word;
    while (iss >> word) v.push_back(word);
    sort(v.begin(), v.end());

    for (auto it = v.begin(); it != v.end(); it++) {
        if (it != --v.end()) { EXPECT_EQ(1, *it->ps() < *(++it)->ps()); }
    }
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
