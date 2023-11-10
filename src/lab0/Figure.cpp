#pragma once
#include "Figure.h"

Vector<Point> Figure::GetCoordinates(){
        return Coordinates;
}

void Figure::operator=(Figure &other){
        Coordinates = other.GetCoordinates();
}

Figure& Figure::operator=(Figure &&other){
        Coordinates = std::move(other.GetCoordinates());
        return *this;
}

bool Figure::operator==(Figure &other){
        return (Coordinates == other.GetCoordinates());
}

std::ostream& operator<<(std::ostream& os, const Figure& p){
    os << p.Coordinates[0] << std::endl << p.Coordinates[1] << std::endl << p.Coordinates[2] << std::endl << p.Coordinates[3] << std::endl; 
    return os;
}