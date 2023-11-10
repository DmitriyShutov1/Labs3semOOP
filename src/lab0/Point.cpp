#pragma once
#include "Point.h"


Point::Point(double a, double b){
    x = a;
    y = b;
}

void Point::operator=(const Point& other){
    x = other.x;
    y = other.y;
}

Point::Point(){
    x = 0;
    y = 0;
}

bool Point::operator==(const Point& other){
    if (this->x == other.x and this->y == other.y){
        return 1;
    }
    return 0;
}

std::ostream& operator<<(std::ostream& os, const Point& p){
    os << "Point [ x : " << p.x << ", y : " << p.y << "]";	
	return os;
}

std::istream& operator>>(std::istream& is, Point& p){
    is >> p.x >> p.y;
    return is;
}