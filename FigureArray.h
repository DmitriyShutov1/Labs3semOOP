#pragma once
#include <memory>
#include <iostream>
#include "Square.h"
#include "Triangle.h"
#include "Rectangle.h"

template <class T>
class FigureArray {
private:
    std::shared_ptr<std::shared_ptr<Figure<T>>[]> figures;
    int size;
    int capacity;
public:
    FigureArray(size_t size) : size(0), capacity(size) {
        figures.reset(new std::shared_ptr<Figure<T>>[capacity]);
    }

    void addFigure(const std::shared_ptr<Figure<T>>& figure) {
        if (size == capacity) {
            capacity *= 2;
            std::shared_ptr<Figure<T>>* newFigures = new std::shared_ptr<Figure<T>>[capacity];
            for (size_t i = 0; i < size; ++i) {
                newFigures[i] = figures[i];
            }
            figures.reset(newFigures);
        }
        figures[size] = figure;
        size += 1;
    }

    double totalArea() const {
        double total = 0.0;
        for (size_t i = 0; i < size; ++i) {
            total += figures[i]->area();
        }
        return total;
    }

    void printFigures() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << *figures[i] << std::endl;
        }
    }

    void printGeometricCenter() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << (*figures[i]).geometric_center().x << (*figures[i]).geometric_center().y << std::endl;
        }
    }

    std::shared_ptr<Figure<T>>& operator[](size_t index) {
        return figures[index];
    }

    void removeFigure(size_t index) {
        if (index < size) {
            for (size_t i = index; i < size - 2; ++i) {
                figures[i] = figures[i + 1];
            }
            figures[size - 1] = nullptr;
            size -= 1;
        }
    }

    int getSize(){
        return size;
    }
};