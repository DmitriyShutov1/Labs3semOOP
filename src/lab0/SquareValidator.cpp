#pragma once

#include "SquareValidator.h"

void SquareValidator::Validate(Vector<Point> points){
    if (points.getSize() != 4) {
        throw std::invalid_argument("Invalid number of points");
    }
    double side1 = std::sqrt(std::pow(points[1].x - points[0].x, 2) + std::pow(points[1].y - points[0].y, 2));
    double side2 = std::sqrt(std::pow(points[2].x - points[1].x, 2) + std::pow(points[2].y - points[1].y, 2));
    double side3 = std::sqrt(std::pow(points[3].x - points[2].x, 2) + std::pow(points[3].y - points[2].y, 2));
    double side4 = std::sqrt(std::pow(points[0].x - points[3].x, 2) + std::pow(points[0].y - points[3].y, 2));

    if (side1 == side2 && side2 == side3 && side3 == side4) {
        double diagonal1 = std::sqrt(std::pow(points[2].x - points[0].x, 2) + std::pow(points[2].y - points[0].y, 2));
        double diagonal2 = std::sqrt(std::pow(points[3].x - points[1].x, 2) + std::pow(points[3].y - points[1].y, 2));
        if (std::abs(diagonal1 - diagonal2) > 0) {
            throw std::invalid_argument("Invalid angle between sides");
        }
    }
    else{
        throw std::invalid_argument("Sides are not equal");
    }
}
