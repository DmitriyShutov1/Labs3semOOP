#include <gtest/gtest.h>
#include "MyIterator.h"

TEST(MyIteratorTest, IncrementOperatorTest) {
    int arr[] = {1, 2, 3};
    MyIterator<int> iter(&arr[0]);

    ++iter;
    int expectedValue = 2;

    EXPECT_EQ(expectedValue, *iter);
}

TEST(MyIteratorTest, EqualityOperatorTest) {
    int arr[] = {1, 2, 3};
    MyIterator<int> iter1(&arr[0]);
    MyIterator<int> iter2(&arr[0]);

    EXPECT_TRUE(iter1 == iter2);
}

TEST(MyIteratorTest, InequalityOperatorTest) {
    int arr[] = {1, 2, 3};
    MyIterator<int> iter1(&arr[0]);
    MyIterator<int> iter2(&arr[1]);

    EXPECT_TRUE(iter1 != iter2);
}

TEST(MyIteratorTest, DereferenceOperatorTest) {
    int arr[] = {1, 2, 3};
    MyIterator<int> iter(&arr[0]);

    int expectedValue = 1;

    EXPECT_EQ(expectedValue, *iter);
}

TEST(MyIteratorTest, ArrowOperatorTest) {
    struct TestStruct {
        int value;
    };

    TestStruct arr[] = {{1}, {2}, {3}};
    MyIterator<TestStruct> iter(&arr[0]);

    int expectedValue = 1;

    EXPECT_EQ(expectedValue, iter->value);
}