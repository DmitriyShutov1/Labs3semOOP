#pragma once
#include <memory>
#include <iostream>
#include "Point.h"

template <class T>
class Figure {
public:
    virtual double area() const = 0;
    virtual Point<T> geometric_center() = 0;
    friend std::ostream& operator<<(std::ostream& os, const Figure<T>& P) {
        for (size_t i = 0; i < P._size; ++i) {
            os << P._points[i].x << " " << P._points[i].y << std::endl;
        }
        return os;
    }
    Figure<T>& operator=(const Figure<T>& other) {
        if (this != &other) {
            _size = other._size;
            _points.reset(new Point<T>[_size]);
            for (size_t i = 0; i < _size; ++i) {
                _points[i] = other._points[i];
            }
        }
        return *this;
    }   
    Figure<T>& operator=(Figure<T>&& other) {
        if (this != &other) {
            _size = other._size;
            _points = std::move(other._points);
            other._size = 0;
        }
        return *this;
    }
    bool operator==(const Figure<T>& other) const {
        if (_size != other._size) {
            return false;
        }
        for (size_t i = 0; i < _size; ++i) {
            if (_points[i] != other._points[i]) {
                return false;
            }
        }
        return true;
    }
    ~Figure() = default;
protected:
    size_t _size;
    std::shared_ptr<Point<T>[]> _points;
};


