#include <gtest/gtest.h>
#include "Square.h"

template <typename T>
class SquareTest : public testing::Test {
protected:
    void SetUp() override {
        squarePoints = std::shared_ptr<Point<T>[]>(new Point<T>[4]);
        squarePoints[0] = Point<T>(0.0, 0.0);
        squarePoints[1] = Point<T>(0.0, 10.0);
        squarePoints[2] = Point<T>(10.0, 10.0);
        squarePoints[3] = Point<T>(10.0, 0.0);
    }

    std::shared_ptr<Point<T>[]> squarePoints;
};

typedef testing::Types<int, double, float> MyTypes;
TYPED_TEST_SUITE(SquareTest, MyTypes);

TYPED_TEST(SquareTest, AreaTest) {
    Square<TypeParam> square(this->squarePoints, 4);
    TypeParam actualArea = square.area();
    TypeParam expectedArea = static_cast<TypeParam>(100.0);
    EXPECT_EQ(expectedArea, actualArea);
}

TYPED_TEST(SquareTest, GeoTest) {
    Square<TypeParam> square(this->squarePoints, 4);
    Point<TypeParam> realCenter = square.geometric_center();
    Point<TypeParam> expectedCenter(5.0,5.0);
    EXPECT_EQ(realCenter.x, expectedCenter.x);
    EXPECT_EQ(realCenter.y, expectedCenter.y);
}

