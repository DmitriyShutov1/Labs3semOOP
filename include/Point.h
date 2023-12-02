#pragma once

template <class T>
class Point {
public:
    T x;
    T y;
    Point(T _x, T _y) : x(_x), y(_y) {}
    Point() : x(0), y(0) {}
    bool operator!=(const Point<T>& other) const {
        return (x != other.x || y != other.y);
    }
};

