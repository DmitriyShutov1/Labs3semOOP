#pragma once
#include <memory>
#include <iostream>
#include <cmath>
#include "Point.h"
#include "Figure.h"

template <class T>
class Rectangle : public Figure<T> {
public:
    double area() const override {
        T size1 = sqrt((this->_points[1].x - this->_points[0].x)*(this->_points[1].x - this->_points[0].x) + (this->_points[1].y - this->_points[0].y)*(this->_points[1].y - this->_points[0].y));
        T size2 = sqrt((this->_points[2].x - this->_points[1].x)*(this->_points[2].x - this->_points[1].x) + (this->_points[2].y - this->_points[1].y)*(this->_points[2].y - this->_points[1].y));
        return size1*size2;
    }

    Point<T> geometric_center() override {
        T a1 = (this->_points[0].x + this->_points[1].x + this->_points[2].x + this->_points[3].x) / 4.0;
        T a2 = (this->_points[0].y + this->_points[1].y + this->_points[2].y + this->_points[3].y) / 4.0;
        Point<T> center(a1, a2);
        return center;
    }

    Rectangle(std::shared_ptr<Point<T>[]> points, size_t size) {
        this->_points = points;
        this->_size = size;
        T side1 = std::sqrt(std::pow(points[1].x - points[0].x, 2) + std::pow(points[1].y - points[0].y, 2));
        T side2 = std::sqrt(std::pow(points[2].x - points[1].x, 2) + std::pow(points[2].y - points[1].y, 2));
        T side3 = std::sqrt(std::pow(points[3].x - points[2].x, 2) + std::pow(points[3].y - points[2].y, 2));
        T side4 = std::sqrt(std::pow(points[0].x - points[3].x, 2) + std::pow(points[0].y - points[3].y, 2));

        if (side1 == side3 && side2 == side4) {
            T diagonal1 = std::sqrt(std::pow(points[2].x - points[0].x, 2) + std::pow(points[2].y - points[0].y, 2));
            T diagonal2 = std::sqrt(std::pow(points[3].x - points[1].x, 2) + std::pow(points[3].y - points[1].y, 2));
            if (std::abs(diagonal1 - diagonal2) > 0) {
                throw std::invalid_argument("Invalid angle between sides");
            }
        }
        else{
            throw std::invalid_argument("Sides are not equal");
        }
    }

    friend std::istream& operator>>(std::istream& is, Rectangle<T>& P) {
        for (size_t i = 0; i < P._size; ++i) {
            is >> P._points[i].x >> P._points[i].y;
        }
        return is;
    }

    ~Rectangle() = default;
};