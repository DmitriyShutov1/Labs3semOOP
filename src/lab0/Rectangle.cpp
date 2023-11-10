#pragma once
#include "Rectangle.h"
#include "Point.h"
#include "Figure.h"
#include "Vector.h"
#include <cmath>

Point Rectangle::geometric_center(){
    Point center;
    center.x = (Coordinates[0].x + Coordinates[1].x + Coordinates[2].x + Coordinates[3].x) / 4.0;
    center.y = (Coordinates[0].y + Coordinates[1].y + Coordinates[2].y + Coordinates[3].y) / 4.0;
    return center;
}

Rectangle::operator double() const{
    double size1 = sqrt((Coordinates[1].x - Coordinates[0].x)*(Coordinates[1].x - Coordinates[0].x) + (Coordinates[1].y - Coordinates[0].y)*(Coordinates[1].y - Coordinates[0].y));
    double size2 = sqrt((Coordinates[2].x - Coordinates[1].x)*(Coordinates[2].x - Coordinates[1].x) + (Coordinates[2].y - Coordinates[1].y)*(Coordinates[2].y - Coordinates[1].y));
    return size1*size2;
}

Rectangle Rectangle::Create_object(Vector<Point> &points){
    RectangleValidator::Validate(points);
    return Rectangle(points);
} 

Rectangle::Rectangle(Vector<Point> &points) {Coordinates = points;}

std::istream& operator>>(std::istream& is, Rectangle& p){
        Point A,B,C,D;
        is >> A >> B >> C >> D;
        Vector <Point> points{A,B,C,D};
        RectangleValidator::Validate(points);
        p.Coordinates = points;
        return is;
}