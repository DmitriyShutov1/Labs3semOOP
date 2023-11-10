#include "gtest/gtest.h"
#include "Figure.h"
#include "Point.h"
#include "Vector.h"
#include "Square.h"
#include "Rectangle.h"
#include "Trapezoid.h"
#include "FigureArray.h"

// Define the fixture for testing class Square
class SquareTest : public testing::Test {
protected:
    Vector<Point> points;

    void SetUp() override {
        // Create a square with side length 4
        points.push_back(Point(0, 0));
        points.push_back(Point(0, 4));
        points.push_back(Point(4, 4));
        points.push_back(Point(4, 0));
    }
};

TEST_F(SquareTest, OperatorsTest1) {
    Trapezoid trapezoid = Trapezoid::Create_object(points);
    Square square = Square::Create_object(points);
    Rectangle rectangle = Rectangle::Create_object(points);
    Figure* A = &trapezoid;
    Figure* B = &square;
    Figure* C = &rectangle;
    EXPECT_EQ(((*A)==(*B)), 1);
    EXPECT_EQ(((*B)==(*C)), 1);
}

TEST_F(SquareTest, OperatorsTest2) {
    Trapezoid trapezoid = Trapezoid::Create_object(points);
    Vector <Point> points1 = {{0,0},{0,6},{6,6},{6,0}};
    Square square = Square::Create_object(points1);
    Vector <Point> points2 = {{0,0},{0,8},{8,8},{8,0}};
    Rectangle rectangle = Rectangle::Create_object(points2); 
    Figure* A = &trapezoid;
    Figure* B = &square;
    Figure* C = &rectangle;
    (*A) = (*B);
    (*B) = (*C);
    EXPECT_EQ((*A).GetCoordinates(), points1);
    EXPECT_EQ((*B).GetCoordinates(), points2);
}

// Test the creation of a square object
TEST_F(SquareTest, CreateObject) {
    Square square = Square::Create_object(points);
    EXPECT_EQ((double)square, 16.0);
}

TEST_F(SquareTest, CreateObjectError) {
    Vector<Point> points = {{0, 0}, {0, 4}, {4, 4}};  // Неправильное количество точек

    ASSERT_THROW({
        Square square = Square::Create_object(points);
    }, std::invalid_argument);
}

TEST_F(SquareTest, CreateObjectError1) {
    Vector<Point> points = {{0, 0}, {0, 4}, {4, 4}, {4,1}};  // Неправильное количество точек

    ASSERT_THROW({
        Square square = Square::Create_object(points);
    }, std::invalid_argument);
}

// Test the geometric center calculation of a square object
TEST_F(SquareTest, GeometricCenter) {
    Square square = Square::Create_object(points);
    Point center = square.geometric_center();
    EXPECT_EQ(center.x, 2.0);
    EXPECT_EQ(center.y, 2.0);
}

// Define the fixture for testing class Rectangle
class RectangleTest : public testing::Test {
protected:
    Vector<Point> points;

    void SetUp() override {
        // Create a rectangle with length 5 and width 3
        points.push_back(Point(0, 0));
        points.push_back(Point(0, 3));
        points.push_back(Point(5, 3));
        points.push_back(Point(5, 0)); 
    }
};

// Test the creation of a rectangle object
TEST_F(RectangleTest, CreateObject) {
    Rectangle rectangle = Rectangle::Create_object(points);
    EXPECT_EQ((double)rectangle, 15.0);
}

TEST_F(RectangleTest, GeometricCenter) {
    Rectangle rectangle = Rectangle::Create_object(points);
    Point center = rectangle.geometric_center();
    EXPECT_EQ(center.x, 2.5);
    EXPECT_EQ(center.y, 1.5);
}

TEST_F(RectangleTest, CreateObjectError) {
    Vector<Point> points = {{0, 0}, {0, 4}, {4, 4}};  // Неправильное количество точек

    ASSERT_THROW({
        Rectangle square = Rectangle::Create_object(points);
    }, std::invalid_argument);
}

TEST_F(RectangleTest, CreateObjectError1) {
    Vector<Point> points = {{0, 0}, {0, 4}, {4, 4}, {4,1}};  // Неправильное количество точек

    ASSERT_THROW({
        Rectangle square = Rectangle::Create_object(points);
    }, std::invalid_argument);
}

// Define the fixture for testing class Trapezoid
class TrapezoidTest : public testing::Test {
protected:
    Vector<Point> points;
    void SetUp() override {
        // Create a trapezoid with base1 length 4, base2 length 6, and height 5
        points.push_back(Point(0, 0));
        points.push_back(Point(3, 5));
        points.push_back(Point(6, 5));
        points.push_back(Point(9, 0));
    }
};

// Test the creation of a trapezoid object
TEST_F(TrapezoidTest, CreateObject) {
    Trapezoid trapezoid = Trapezoid::Create_object(points);
    EXPECT_EQ((double)trapezoid, 30);
}

// Test the geometric center calculation of a trapezoid object
TEST_F(TrapezoidTest, GeometricCenter) {
    Trapezoid trapezoid = Trapezoid::Create_object(points);
    Point center = trapezoid.geometric_center();
    EXPECT_EQ(center.x, 4.5);
    EXPECT_EQ(center.y, 2.5);
}

TEST_F(TrapezoidTest, CreateObjectError) {
    Vector<Point> points = {{0, 0}, {0, 4}, {4, 4}};  // Неправильное количество точек

    ASSERT_THROW({
        Trapezoid square = Trapezoid::Create_object(points);
    }, std::invalid_argument);
}

TEST_F(TrapezoidTest, CreateObjectError1) {
    Vector<Point> points = {{0, 0}, {0, 4}, {4, 4}, {4,1}};  // Неправильное количество точек

    ASSERT_THROW({
        Trapezoid square = Trapezoid::Create_object(points);
    }, std::invalid_argument);
}

TEST(FigureArrayTest, GetTotalArea) {
    FigureArray array;
    
    Vector <Point> points = {{0,0},{0,4},{4,4},{4,0}};
    Trapezoid trapezoid = Trapezoid::Create_object(points);
    Vector <Point> points1 = {{0,0},{0,6},{6,6},{6,0}};
    Square square = Square::Create_object(points1);
    Vector <Point> points2 = {{0,0},{0,8},{8,8},{8,0}};
    Rectangle rectangle = Rectangle::Create_object(points2); 
    
    array.add(&trapezoid);
    array.add(&square);
    array.add(&rectangle);
    
    EXPECT_EQ(array.size, 3);
}

TEST(FigureArrayTest, GetTotalArea1) {
    FigureArray array;
    
    Vector <Point> points = {{0,0},{0,4},{4,4},{4,0}};
    Trapezoid trapezoid = Trapezoid::Create_object(points);
    Vector <Point> points1 = {{0,0},{0,6},{6,6},{6,0}};
    Square square = Square::Create_object(points1);
    Vector <Point> points2 = {{0,0},{0,8},{8,8},{8,0}};
    Rectangle rectangle = Rectangle::Create_object(points2); 
    
    array.add(&trapezoid);
    array.add(&square);
    array.add(&rectangle);
    
    EXPECT_EQ(array.getTotalArea(), 116);
}

// Run all the tests
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS(); 
}