#pragma once

#include "TrapezoidValidator.h"

void TrapezoidValidator::Validate(Vector<Point> points){
    if (points.getSize() != 4) {
        throw std::invalid_argument("Invalid number of points");
    }
    double A = points[1].y - points[0].y;
    double B = points[2].y - points[3].y;
    if (A!=B){
        throw std::invalid_argument("Invalid angles");
    }
}