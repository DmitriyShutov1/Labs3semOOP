#include <gtest/gtest.h>
#include <map>
#include "MyAllocator.h"
#include "MyQueue.h"

TEST(MyAllocatorTest, MapInsertTest) {
    std::map<int, int, std::less<int>, MyAllocator<std::pair<const int, int>>> myMap;

    myMap[1] = 10;
    myMap[2] = 20;
    int expectedVal1 = 0;
    int expectedVal2 = 10;
    int expectedVal3 = 20;
    EXPECT_EQ(expectedVal1, myMap.empty());
    EXPECT_EQ(expectedVal2, myMap[1]);
    EXPECT_EQ(expectedVal3, myMap[2]);
}

TEST(MyQueueTest, QueueInsertTest) {
    MyQueue<int, MyAllocator<int>> myQueue;

    myQueue.push(10);
    myQueue.push(20);

    int expectedVal1 = 10;
    int expectedVal2 = 20;

    EXPECT_EQ(expectedVal1, myQueue.front());
    EXPECT_EQ(expectedVal2, myQueue.back());
}