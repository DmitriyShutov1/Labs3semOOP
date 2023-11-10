#pragma once

#include <iostream>

class Point {
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
    friend std::istream& operator>>(std::istream& is, Point& p);
public:
    Point();
    double x, y;
    Point(double a, double b);
    void operator=(const Point& other);
    bool operator==(const Point& other);
};

