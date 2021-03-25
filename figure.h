#pragma once
#include <iostream>
#include <cstdbool>

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
	virtual void printFigureName() const = 0;
	virtual bool isFigure() const = 0;
	virtual bool belongsFigure(int, int) const = 0;

protected:
    Vertex2D* vertexs;
    unsigned vertexsCount;
};

class Triangle : public Figure {
public:
    Triangle();
	void printFigureName() const override;
	bool isFigure() const override;
	bool belongsFigure(int, int) const override;
};

class Quadrangle : public Figure {
public:
    Quadrangle();
    virtual ~Quadrangle() = default;
    bool belongsFigure(int, int) const override;
};

class Square : public Quadrangle {
public:
    Square() = default;
	void printFigureName() const override;
	bool isFigure() const override;
};

class Trapezoid : public Quadrangle {
public:
    Trapezoid() = default;
	void printFigureName() const override;
	bool isFigure() const override;
};

class Rhombus : public Quadrangle {
public:
    Rhombus() = default;
	void printFigureName() const override;
	bool isFigure() const override;
};
