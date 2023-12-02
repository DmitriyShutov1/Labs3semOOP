#include <gtest/gtest.h>
#include "MyQueue.h"
#include "MyAllocator.h"

template <typename T>
class MyQueueTest : public testing::Test {
protected:
    MyQueue<T> queue;

    void SetUp() override {
        for (int i = 1; i <= 5; ++i) {
            queue.push(i);
        }
    }
};

typedef testing::Types<int, double, float> MyTypes;
TYPED_TEST_SUITE(MyQueueTest, MyTypes);

TYPED_TEST(MyQueueTest, SizeTest) {
    int expectedValue = 5;
    EXPECT_EQ(expectedValue, this->queue.size());
}

TYPED_TEST(MyQueueTest, EmptyTest) {
    EXPECT_FALSE(this->queue.empty());
}

TYPED_TEST(MyQueueTest, FrontTest) {
    int expectedValue = 1;
    EXPECT_EQ(expectedValue, this->queue.front());
}

TYPED_TEST(MyQueueTest, BackTest) {
    int expectedValue = 5;
    EXPECT_EQ(expectedValue, this->queue.back());
}

TYPED_TEST(MyQueueTest, PopTest) {
    this->queue.pop();
    int expectedValue = 4;
    EXPECT_EQ(expectedValue, this->queue.size());
}

TYPED_TEST(MyQueueTest, IteratorTest) {
    typename MyQueue<TypeParam>::iterator it = this->queue.begin();
    ++it;
    ++it;
    int expectedValue = 3;
    EXPECT_EQ(expectedValue, *it);
}