#pragma once
#include <iostream>
#include <cstdbool>

#include "printFunctions.h"

using namespace std;

typedef struct {
    int x, y;
}Vertex2D;

typedef struct {
    int x, y, z;
}Verctor3D;

class Figure {
public:
    Figure() = default;
    virtual ~Figure();
    bool setVertexs();
    void sortVertexs();
    void print() const;
    virtual bool isFigure() const = 0;

protected:
    Vertex2D* vertexs;
    unsigned vertexsCount;
};

class Triangle : public Figure {
public:
    Triangle();
    bool isFigure() const;
};

class Square : public Figure {
public:
    Square();
    bool isFigure() const;
};

class Trapezoid : public Figure {
public:
    Trapezoid();
    bool isFigure() const;
};

class Rhombus : public Figure {
public:
    Rhombus();
    bool isFigure() const;
};
