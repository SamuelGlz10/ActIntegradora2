#include <gtest/gtest.h>
#include "LinealSearch.h"

TEST(LinealSearchTest, FoundElement) {
    vector<int> arr = {1, 3, 5, 7, 9};
    EXPECT_EQ(search(arr, 5), 2);
}

TEST(LinealSearchTest, NotFoundElement) {
    vector<int> arr = {2, 4, 6, 8};
    EXPECT_EQ(search(arr, 5), -1);
}

TEST(LinealSearchTest, EmptyArray) {
    vector<int> arr;
    EXPECT_EQ(search(arr, 1), -1);
}
