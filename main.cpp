#include <iostream>
#include <memory>
#include <string>
#include <algorithm>
#include "Point.h"
#include "Square.h"
#include "Figure.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "FigureArray.h"

int main() {
    // Создание объектов фигур
    std::shared_ptr<Point<double>[]> trianglePoints(new Point<double>[3]{
        Point<double>(0.0, 0.0),
        Point<double>(10.0, 10.0),
        Point<double>(20.0, 0.0)
    });

    std::shared_ptr<Point<double>[]> squarePoints(new Point<double>[4]{
        Point<double>(0.0, 0.0),
        Point<double>(0.0, 10.0),
        Point<double>(10.0, 10.0),
        Point<double>(10.0, 0.0)
    });

    std::shared_ptr<Point<double>[]> rectanglePoints(new Point<double>[4]{
        Point<double>(0.0, 0.0),
        Point<double>(0.0, 20.0),
        Point<double>(10.0, 20.0),
        Point<double>(10.0, 0.0)
    });

    std::shared_ptr<Triangle<double>> triangle(new Triangle<double>(trianglePoints, 3));
    std::shared_ptr<Square<double>> square(new Square<double>(squarePoints, 4));
    std::shared_ptr<Rectangle<double>> rectangle(new Rectangle<double>(rectanglePoints, 4));

    // Создание объекта FigureArray и добавление фигур
    FigureArray<double> figureArray(3);
    figureArray.addFigure(triangle);
    figureArray.addFigure(square);
    figureArray.addFigure(rectangle);

    double TrArea = (*figureArray[0]).area();
    std::cout << TrArea << std::endl << "Kolya has great ass" << std::endl << (*triangle).area() << std::endl;
}
