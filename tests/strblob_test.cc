#include "strblob.h"

#include <gtest/gtest.h>
#include <iostream>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

TEST(testCase, test_list_init) {
    StrBlob obj {"1", "2", "3"};
    ASSERT_EQ(obj.size(), 3);
    auto it = StrBlobPtr(obj, 0);
    ASSERT_EQ(*it, "1");
    ASSERT_EQ(*(++it), "2");
    ASSERT_EQ(*(++it), "3");
}

TEST(testCase, test_push_back) {
    StrBlob obj;
    for (int i = 0; i < 100; i++) {

        obj.push_back("[" + std::to_string(i) + "]" + "test string");

        ASSERT_EQ(obj.size(), i + 1);
    }
}

TEST(testCase, ranged_based_for_loop) {
    StrBlob obj {"0", "1", "2", "3", "4"};
    int     target = 0;
    for (auto i : obj) {
        ASSERT_EQ(i, std::to_string(target));
        ++target;
    }
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
