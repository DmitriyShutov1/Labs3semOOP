#include <gtest/gtest.h>
#include "Triangle.h"

template <typename T>
class TriangleTest : public testing::Test {
protected:
    void SetUp() override {
        squarePoints = std::shared_ptr<Point<T>[]>(new Point<T>[4]);
        squarePoints[0] = Point<T>(0.0, 0.0);
        squarePoints[1] = Point<T>(5.0, 5.0);
        squarePoints[2] = Point<T>(10.0, 0.0);
    }

    std::shared_ptr<Point<T>[]> squarePoints;
};

typedef testing::Types<int, double, float> MyTypes;
TYPED_TEST_SUITE(TriangleTest, MyTypes);

TYPED_TEST(TriangleTest, AreaTest) {
    Triangle<TypeParam> square(this->squarePoints, 3);
    TypeParam actualArea = square.area();
    TypeParam expectedArea = static_cast<TypeParam>(25.0);
    EXPECT_EQ(expectedArea, actualArea);
}

TYPED_TEST(TriangleTest, GeoTest) {
    Triangle<TypeParam> square(this->squarePoints, 3);
    Point<TypeParam> realCenter = square.geometric_center();
    Point<TypeParam> expectedCenter(5.0,2.5);
    EXPECT_EQ(realCenter.x, expectedCenter.x);
    EXPECT_EQ(realCenter.y, expectedCenter.y);
}

