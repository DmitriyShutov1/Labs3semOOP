#include <gtest/gtest.h>
#include "FigureArray.h"

template <typename T>
class FigureArrayTest : public testing::Test {
protected:
    void SetUp() override {
        squarePoints = std::shared_ptr<Point<T>[]>(new Point<T>[4]);
        squarePoints[0] = Point<T>(0.0, 0.0);
        squarePoints[1] = Point<T>(0.0, 10.0);   //100
        squarePoints[2] = Point<T>(10.0, 10.0);
        squarePoints[3] = Point<T>(10.0, 0.0);

        rectanglePoints = std::shared_ptr<Point<T>[]>(new Point<T>[4]);
        rectanglePoints[0] = Point<T>(0.0, 0.0);
        rectanglePoints[1] = Point<T>(0.0, 10.0);
        rectanglePoints[2] = Point<T>(5.0, 10.0);  //50
        rectanglePoints[3] = Point<T>(5.0, 0.0);

        trianglePoints = std::shared_ptr<Point<T>[]>(new Point<T>[3]);
        trianglePoints[0] = Point<T>(0.0, 0.0);
        trianglePoints[1] = Point<T>(10.0, 10.0);
        trianglePoints[2] = Point<T>(20.0, 0.0); //100
    }
    std::shared_ptr<Point<T>[]> squarePoints;
    std::shared_ptr<Point<T>[]> rectanglePoints;
    std::shared_ptr<Point<T>[]> trianglePoints;
};

typedef testing::Types<int, double, float> MyTypes;
TYPED_TEST_SUITE(FigureArrayTest, MyTypes);

TYPED_TEST(FigureArrayTest, AreaTest) {
    std::shared_ptr<Triangle<TypeParam>> triangle(new Triangle<TypeParam>(this->trianglePoints, 3));
    std::shared_ptr<Square<TypeParam>> square(new Square<TypeParam>(this->squarePoints, 4));
    std::shared_ptr<Rectangle<TypeParam>> rectangle(new Rectangle<TypeParam>(this->rectanglePoints, 4));
    FigureArray<TypeParam> figureArray(3);
    figureArray.addFigure(triangle);
    figureArray.addFigure(square);
    figureArray.addFigure(rectangle);
    TypeParam expectedArea = 250;
    TypeParam realArea = figureArray.totalArea();
    EXPECT_EQ(expectedArea, realArea);
}

TYPED_TEST(FigureArrayTest, RemoveTest) {
    std::shared_ptr<Triangle<TypeParam>> triangle(new Triangle<TypeParam>(this->trianglePoints, 3));
    std::shared_ptr<Square<TypeParam>> square(new Square<TypeParam>(this->squarePoints, 4));
    std::shared_ptr<Rectangle<TypeParam>> rectangle(new Rectangle<TypeParam>(this->rectanglePoints, 4));
    FigureArray<TypeParam> figureArray(3);
    figureArray.addFigure(triangle);
    figureArray.addFigure(square);
    figureArray.addFigure(rectangle);
    int beforeCount = 3;
    int afterCount = 2;
    int beforeSize = figureArray.getSize();
    EXPECT_EQ(beforeCount, beforeSize);
    figureArray.removeFigure(0);
    int afterSize = figureArray.getSize();
    EXPECT_EQ(afterCount, afterSize);
}

TYPED_TEST(FigureArrayTest, OperatorTest) {
    std::shared_ptr<Triangle<TypeParam>> triangle(new Triangle<TypeParam>(this->trianglePoints, 3));
    std::shared_ptr<Square<TypeParam>> square(new Square<TypeParam>(this->squarePoints, 4));
    std::shared_ptr<Rectangle<TypeParam>> rectangle(new Rectangle<TypeParam>(this->rectanglePoints, 4));
    FigureArray<TypeParam> figureArray(3);
    figureArray.addFigure(triangle);
    figureArray.addFigure(square);
    figureArray.addFigure(rectangle);
    
    TypeParam TrArea = (*figureArray[0]).area();
    TypeParam RealArea = 100;
    EXPECT_EQ(TrArea, RealArea);

    bool SqAndRecEq = ((*figureArray[1]) == (*figureArray[2]));
    bool ExEq = 0;
    EXPECT_EQ(SqAndRecEq, ExEq);

    (*figureArray[1]) = (*figureArray[2]);
    bool SqAndRecEq1 = ((*figureArray[1]) == (*figureArray[2]));
    bool ExEq1 = 1;
    EXPECT_EQ(SqAndRecEq1, ExEq1);
}

