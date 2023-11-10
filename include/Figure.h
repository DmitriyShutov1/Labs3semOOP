#pragma once

#include <iostream>
#include "Point.h"
#include "Vector.h"

class Figure {
    friend std::ostream& operator<<(std::ostream& os, const Figure& p);
public:
    virtual operator double() const = 0;
    virtual Point geometric_center() = 0;
    Vector<Point> GetCoordinates();
    ~Figure() = default;
    void operator=(Figure &other);
    Figure& operator=(Figure &&other);
    bool operator==(Figure &other);
protected:
    Vector <Point> Coordinates;
};



    