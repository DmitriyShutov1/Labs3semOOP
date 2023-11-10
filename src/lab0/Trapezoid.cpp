#pragma once
#include "Trapezoid.h"
#include "Point.h"
#include "Figure.h"
#include "Vector.h"

Point Trapezoid::geometric_center(){
    Point center;
    center.x = (Coordinates[0].x + Coordinates[1].x + Coordinates[2].x + Coordinates[3].x) / 4.0;
    center.y = (Coordinates[0].y + Coordinates[1].y + Coordinates[2].y + Coordinates[3].y) / 4.0;
    return center;
}

Trapezoid::operator double() const{
    double height = std::abs(Coordinates[1].y - Coordinates[0].y);
    double base1 = std::abs(Coordinates[2].x - Coordinates[1].x);
    double base2 = std::abs(Coordinates[3].x - Coordinates[0].x);
    double square = ((base1 + base2) * height) / 2.0;
    return square;
}

Trapezoid Trapezoid::Create_object(Vector<Point> &points){
    TrapezoidValidator::Validate(points);
    return Trapezoid(points);
} 

Trapezoid::Trapezoid(Vector<Point> &points) {Coordinates = points;}


std::istream& operator>>(std::istream& is, Trapezoid& p) {
    Point A, B, C, D;
    is >> A >> B >> C >> D;
    Vector<Point> points{A, B, C, D};
    TrapezoidValidator::Validate(points);
    p.Coordinates = points;
    return is;
}