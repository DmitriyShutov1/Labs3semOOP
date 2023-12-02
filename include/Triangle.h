#pragma once
#include <memory>
#include <iostream>
#include <cmath>
#include "Point.h"
#include "Figure.h"

template <class T>
class Triangle : public Figure<T> {
public:
    double area() const override {
        T area;
        T h = this->_points[1].y - this->_points[0].y;
        T l = this->_points[2].x - this->_points[0].x;
        area = h * l;
        return area/2.0;
    }

    Point<T> geometric_center() override {
        T a1 = (this->_points[2].x - this->_points[0].x) / 2.0 + this->_points[0].x;
        T a2 = (this->_points[1].y - this->_points[0].y) / 2.0 + this->_points[0].y;
        Point<T> center(a1, a2);
        return center;
    }

    Triangle(std::shared_ptr<Point<T>[]> points, size_t size) {
        this->_points = points;
        this->_size = size;
        if (size != 3) {
            throw std::invalid_argument("Invalid count of points");
        }
    }

    friend std::istream& operator>>(std::istream& is, Triangle<T>& P) {
        for (size_t i = 0; i < P._size; ++i) {
            is >> P._points[i].x >> P._points[i].y;
        }
        return is;
    }

    ~Triangle() = default;
};