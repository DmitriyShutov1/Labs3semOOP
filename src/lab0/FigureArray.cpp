#include "FigureArray.h"


FigureArray::FigureArray(): size(0), capacity(10), figures(new Figure*[capacity]) {}
    FigureArray::~FigureArray() {
        delete[] figures;
    }

    double FigureArray::getTotalArea() {
        double totalArea = 0;
        for (int i = 0; i < size; i++) {
            totalArea += (double)(*figures[i]);
        }
        return totalArea;
    }
    
    void FigureArray::add(Figure* figure) {
        if (size == capacity) {
            resize();
        }
        figures[size] = figure;
        size++;
    }

    void FigureArray::removeLast() {
        if (size > 0) {
            figures[size - 1] = nullptr;
            size--;
        }
    }
    
    Figure* FigureArray::operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return figures[index];
    }
    
    void FigureArray::remove(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        for (int i = index + 1; i < size; i++) {
            figures[i - 1] = figures[i];
        }
        size--;
    }

    void FigureArray::printAll(){
        for (int i = 0; i < size; i++) {
            std::cout << (*figures[i]);
        }
    }

    void FigureArray::resize() {
        capacity *= 2;
        Figure** newFigures = new Figure*[capacity];
        for (int i = 0; i < size; i++) {
            newFigures[i] = figures[i];
        }
        delete[] figures;
        figures = newFigures;
    }

    