#include "Figure.h"
#include <iostream>


class FigureArray {
public:
    FigureArray();
    ~FigureArray();
    double getTotalArea();
    void add(Figure* figure);
    void removeLast();
    Figure* operator[](int index);
    void remove(int index);
    void printAll();
    int size;
private:      
    int capacity;  
    Figure** figures;  
    void resize();
};