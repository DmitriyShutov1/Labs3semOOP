#pragma once

#include <iostream>
#include "Point.h"
#include "Figure.h"
#include "Vector.h"
#include "SquareValidator.h"

class Square: public Figure{
    friend std::istream& operator>>(std::istream& is, Square& p);
    public:
        virtual Point geometric_center() override;
        virtual operator double() const override;
        static Square Create_object(Vector<Point> &points);
    private:
        Square(Vector<Point> &points);
};

