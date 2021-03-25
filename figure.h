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
	virtual void printFigureName() const = 0;

protected:
    Vertex2D* vertexs;
    unsigned vertexsCount;
};

class Triangle : public Figure {
public:
    Triangle();
    bool isFigure() const;
	void printFigureName() const override;
};

class Quadrangle : public Figure {
};

class Square : public Quadrangle {
public:
    Square();
    bool isFigure() const;
	void printFigureName() const override;
};

class Trapezoid : public Quadrangle {
public:
    Trapezoid();
    bool isFigure() const;
	void printFigureName() const override;
};

class Rhombus : public Quadrangle {
public:
    Rhombus();
    bool isFigure() const;
	void printFigureName() const override;
};
