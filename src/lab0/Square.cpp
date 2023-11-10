#pragma once
#include "Square.h"
#include "Point.h"
#include "Figure.h"
#include "Vector.h"

Point Square::geometric_center(){
    Point center;
    center.x = (Coordinates[0].x + Coordinates[1].x + Coordinates[2].x + Coordinates[3].x) / 4.0;
    center.y = (Coordinates[0].y + Coordinates[1].y + Coordinates[2].y + Coordinates[3].y) / 4.0;
    return center;
}

Square::operator double() const{
    double square;
    double size1 = (Coordinates[1].x - Coordinates[0].x)*(Coordinates[1].x - Coordinates[0].x) + (Coordinates[1].y - Coordinates[0].y)*(Coordinates[1].y - Coordinates[0].y);
    double size2 = (Coordinates[2].x - Coordinates[0].x)*(Coordinates[2].x - Coordinates[0].x) + (Coordinates[2].y - Coordinates[0].y)*(Coordinates[2].y - Coordinates[0].y);
    if (size1 < size2){
        return size1;
    }
    if (size1 > size2){
        return size2;
    }
    return size1;
}

Square Square::Create_object(Vector<Point> &points){
    SquareValidator::Validate(points);
    return Square(points);
} 

Square::Square(Vector<Point> &points) {Coordinates = points;}


std::istream& operator>>(std::istream& is, Square& p) {
    Point A, B, C, D;
    is >> A >> B >> C >> D;
    Vector<Point> points{A, B, C, D};
    SquareValidator::Validate(points);
    p.Coordinates = points;
    return is;
}