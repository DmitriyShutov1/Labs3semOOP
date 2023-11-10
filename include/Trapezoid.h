#pragma once

#include <iostream>
#include "Point.h"
#include "Figure.h"
#include "Vector.h"
#include "TrapezoidValidator.h"

class Trapezoid: public Figure{
    friend std::istream& operator>>(std::istream& is, Trapezoid& p);
    public:
        virtual Point geometric_center() override;
        virtual operator double() const override;
        static Trapezoid Create_object(Vector<Point> &points);
    private:
        Trapezoid(Vector<Point> &points);
};