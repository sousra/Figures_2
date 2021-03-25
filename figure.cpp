#include <iostream>
#include <cstdbool>
#include <cmath>

#include "figure.h"
#include "printFunctions.h"

using namespace std;

Figure::~Figure() {
    delete[] vertexs;
}

bool Figure::setVertexs() {
    vertexs = new Vertex2D[vertexsCount];
    for (unsigned i = 0; i < vertexsCount; ++i) {
        cout << i + 1 << ' ' << "vertex: ";
        cin >> vertexs[i].x >> vertexs[i].y;
    }

    sortVertexs();

    return isFigure();
}

void Figure::sortVertexs() {
    for (unsigned i = 0; i < vertexsCount - 1; ++i) {
        for (unsigned j = (vertexsCount - 1); j > i; --j) {
            if (vertexs[j - 1].y < vertexs[j].y) {
                swap(vertexs[j - 1], vertexs[j]);
            }
        }
    }

    for (unsigned i = 0; i < vertexsCount - 1; ++i) {
        for (unsigned j = (vertexsCount - 1); j > i; --j) {
            if ((vertexs[i].y == vertexs[j].y)
                && (vertexs[j - 1].x > vertexs[j].x))
            {
                swap(vertexs[j - 1], vertexs[j]);
            }
        }
    }
}

void Figure::print() const {
    int leftBorder = vertexs[0].x;
    for (unsigned i = 0; i < vertexsCount; ++i) {
        if (vertexs[i].x < leftBorder) {
            leftBorder = vertexs[i].x;
        }
    }

    printSpaces(vertexs[0].x - leftBorder);
    cout << '*';
    for (unsigned i = 1; i < vertexsCount; ++i) {
        if (vertexs[i].y == vertexs[i - 1].y) {
            printSpaces(vertexs[i].x - vertexs[i - 1].x - 1);
            cout << '*';
        }
        else {
            printEnters(vertexs[i - 1].y - vertexs[i].y);
            printSpaces(vertexs[i].x - leftBorder);
            cout << '*';
        }
    }
    cout << endl;
}


Triangle::Triangle() {
    vertexsCount = 3;
    vertexs = NULL;
}

bool Triangle::isFigure() const {
    double side1 = sqrt(pow(vertexs[0].x - vertexs[1].x, 2)
                        + pow(vertexs[0].y - vertexs[1].y, 2));
    double side2 = sqrt(pow(vertexs[0].x - vertexs[2].x, 2)
                        + pow(vertexs[0].y - vertexs[2].y, 2));
    double side3 = sqrt(pow(vertexs[1].x - vertexs[2].x, 2)
                        + pow(vertexs[1].y - vertexs[2].y, 2));
    return ((side1 + side2 > side3)
            && (side1 + side3 > side2)
            && (side2 + side3 > side1));

}

void Triangle::printFigureName() const {
	cout << "triangle" << endl;
}

Square::Square() {
    vertexsCount = 4;
    vertexs = NULL;
}

bool Square::isFigure() const {
    double side1 = sqrt(pow(vertexs[0].x - vertexs[1].x, 2)
                        + pow(vertexs[0].y - vertexs[1].y, 2));
    Verctor3D vector1 = {vertexs[0].x - vertexs[1].x, vertexs[0].y - vertexs[1].y, 0};

    double side2 = sqrt(pow(vertexs[0].x - vertexs[2].x, 2)
                        + pow(vertexs[0].y - vertexs[2].y, 2));
    Verctor3D vector2 = {vertexs[0].x - vertexs[2].x, vertexs[0].y - vertexs[2].y, 0};

    double cosA = (vector1.x * vector2.x
                    + vector1.y * vector2.y) / (side1 * side2);

    double side3 = sqrt(pow(vertexs[2].x - vertexs[3].x, 2)
                        + pow(vertexs[2].y - vertexs[3].y, 2));
    double side4 = sqrt(pow(vertexs[1].x - vertexs[3].x, 2)
                        + pow(vertexs[1].y - vertexs[3].y, 2));
    return ((side1 == side2) && (side2 == side3) && (side3 == side4)
            && (cosA == 0));
}

void Square::printFigureName() const {
    cout << "square" << endl;
}


Trapezoid::Trapezoid() {
    vertexsCount = 4;
    vertexs = NULL;
}

bool Trapezoid::isFigure() const {
    double side1 = sqrt(pow(vertexs[0].x - vertexs[1].x, 2)
                        + pow(vertexs[0].y - vertexs[1].y, 2));
    Verctor3D vector1 = {vertexs[0].x - vertexs[1].x, vertexs[0].y - vertexs[1].y, 0};

    double side2 = sqrt(pow(vertexs[0].x - vertexs[2].x, 2)
                        + pow(vertexs[0].y - vertexs[2].y, 2));
    Verctor3D vector2 = {vertexs[0].x - vertexs[2].x, vertexs[0].y - vertexs[2].y, 0};

    double side3 = sqrt(pow(vertexs[2].x - vertexs[3].x, 2)
                        + pow(vertexs[2].y - vertexs[3].y, 2));
    Verctor3D vector3 = {vertexs[2].x - vertexs[3].x, vertexs[2].y - vertexs[3].y, 0};

    double side4 = sqrt(pow(vertexs[1].x - vertexs[3].x, 2)
                        + pow(vertexs[1].y - vertexs[3].y, 2));
    Verctor3D vector4 = {vertexs[1].x - vertexs[3].x, vertexs[1].y - vertexs[3].y, 0};

    return (((side1 != side3) && (vector1.y * vector3.z - vector1.z * vector3.y == 0)
                                && (vector1.z * vector3.x - vector1.x * vector3.z == 0)
                                && (vector1.x * vector3.y - vector1.y * vector3.x == 0))
            || ((side2 != side4) && (vector2.y * vector4.z - vector2.z * vector4.y == 0)
                                && (vector2.z * vector4.x - vector2.x * vector4.z == 0)
                                && (vector2.x * vector4.y - vector2.y * vector4.x == 0)));
}

void Trapezoid::printFigureName() const {
    cout << "trapezoid" << endl;
}

Rhombus::Rhombus() {
    vertexsCount = 4;
    vertexs = NULL;
}

bool Rhombus::isFigure() const {
    double side1 = sqrt(pow(vertexs[0].x - vertexs[1].x, 2)
                        + pow(vertexs[0].y - vertexs[1].y, 2));
    double side2 = sqrt(pow(vertexs[0].x - vertexs[2].x, 2)
                        + pow(vertexs[0].y - vertexs[2].y, 2));
    double side3 = sqrt(pow(vertexs[2].x - vertexs[3].x, 2)
                        + pow(vertexs[2].y - vertexs[3].y, 2));
    double side4 = sqrt(pow(vertexs[1].x - vertexs[3].x, 2)
                        + pow(vertexs[1].y - vertexs[3].y, 2));
    return ((side1 == side2) && (side2 == side3) && (side3 == side4));
}

void Rhombus::printFigureName() const {
    cout << "rhombus" << endl;
}
