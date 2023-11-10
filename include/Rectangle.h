#pragma once

#include <iostream>
#include "Point.h"
#include "Figure.h"
#include "Vector.h"
#include "RectangleValidator.h"


class Rectangle: public Figure{
    friend std::istream& operator>>(std::istream& is, Rectangle& p);
    public:
        virtual Point geometric_center() override;
        virtual operator double() const override;
        static Rectangle Create_object(Vector<Point> &points);
    private:
        Rectangle(Vector<Point> &points);
};