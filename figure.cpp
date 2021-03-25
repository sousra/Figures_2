#include <iostream>
#include <cstdbool>
#include <cmath>

#include "figure.h"

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
    int maxX = vertexs[0].x, minX = vertexs[0].x, maxY = vertexs[0].y, minY = vertexs[0].y;
    for (int i = 0; i < vertexsCount; ++i) {
        if (vertexs[i].x > maxX) {
            maxX = vertexs[i].x;
        }
        if (vertexs[i].x < minX) {
            minX = vertexs[i].x;
        }
        if (vertexs[i].y > maxY) {
            maxY = vertexs[i].y;
        }
        if (vertexs[i].y < minY) {
            minY = vertexs[i].y;
        }
    }

    for (int i = maxY; i >= minY; --i) {
        for (int j = minX; j <= maxX; ++j) {
            if (belongsFigure(j, i)) {
                cout << '*';
            }
            else {
                cout << ' ';
            }
        }
        cout << endl;
    }
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

bool Triangle::belongsFigure(int x, int y) const {
    return (
            (
             ((x - vertexs[0].x) * (vertexs[1].y - vertexs[0].y) == (y - vertexs[0].y) * (vertexs[1].x - vertexs[0].x))
            && (((vertexs[0].x <= x && x <= vertexs[1].x) && (vertexs[1].y <= y && y <= vertexs[0].y))
                || ((vertexs[0].x <= x && x <= vertexs[1].x) && (vertexs[0].y <= y && y <= vertexs[1].y))
                || ((vertexs[1].x <= x && x <= vertexs[0].x) && (vertexs[1].y <= y && y <= vertexs[0].y))
                || ((vertexs[1].x <= x && x <= vertexs[0].x) && (vertexs[0].y <= y && y <= vertexs[1].y)))
             )

            ||

            (
             ((x - vertexs[0].x) * (vertexs[2].y - vertexs[0].y) == (y - vertexs[0].y) * (vertexs[2].x - vertexs[0].x))
            && (((vertexs[0].x <= x && x <= vertexs[2].x) && (vertexs[2].y <= y && y <= vertexs[0].y))
                || ((vertexs[0].x <= x && x <= vertexs[2].x) && (vertexs[0].y <= y && y <= vertexs[2].y))
                || ((vertexs[2].x <= x && x <= vertexs[0].x) && (vertexs[0].y <= y && y <= vertexs[2].y))
                || ((vertexs[2].x <= x && x <= vertexs[0].x) && (vertexs[2].y <= y && y <= vertexs[0].y)))
             )

            ||

            (
             ((x - vertexs[1].x) * (vertexs[2].y - vertexs[1].y) == (y - vertexs[1].y) * (vertexs[2].x - vertexs[1].x))
            && (((vertexs[2].x <= x && x <= vertexs[1].x) && (vertexs[2].y <= y && y <= vertexs[1].y))
                || ((vertexs[2].x <= x && x <= vertexs[1].x) && (vertexs[1].y <= y && y <= vertexs[2].y))
                || ((vertexs[1].x <= x && x <= vertexs[2].x) && (vertexs[1].y <= y && y <= vertexs[2].y))
                || ((vertexs[1].x <= x && x <= vertexs[2].x) && (vertexs[2].y <= y && y <= vertexs[1].y)))
             )
            );
}


Quadrangle::Quadrangle() {
    vertexsCount = 4;
    vertexs = NULL;
}

bool Quadrangle::belongsFigure(int x, int y) const {
    return (
            (
             ((x - vertexs[0].x) * (vertexs[1].y - vertexs[0].y) == (y - vertexs[0].y) * (vertexs[1].x - vertexs[0].x))
            && (((vertexs[0].x <= x && x <= vertexs[1].x) && (vertexs[1].y <= y && y <= vertexs[0].y))
                || ((vertexs[0].x <= x && x <= vertexs[1].x) && (vertexs[0].y <= y && y <= vertexs[1].y))
                || ((vertexs[1].x <= x && x <= vertexs[0].x) && (vertexs[1].y <= y && y <= vertexs[0].y))
                || ((vertexs[1].x <= x && x <= vertexs[0].x) && (vertexs[0].y <= y && y <= vertexs[1].y)))
             )

            ||

            (
             ((x - vertexs[0].x) * (vertexs[2].y - vertexs[0].y) == (y - vertexs[0].y) * (vertexs[2].x - vertexs[0].x))
            && (((vertexs[0].x <= x && x <= vertexs[2].x) && (vertexs[2].y <= y && y <= vertexs[0].y))
                || ((vertexs[0].x <= x && x <= vertexs[2].x) && (vertexs[0].y <= y && y <= vertexs[2].y))
                || ((vertexs[2].x <= x && x <= vertexs[0].x) && (vertexs[0].y <= y && y <= vertexs[2].y))
                || ((vertexs[2].x <= x && x <= vertexs[0].x) && (vertexs[2].y <= y && y <= vertexs[0].y)))
             )

            ||

            (
             ((x - vertexs[1].x) * (vertexs[3].y - vertexs[1].y) == (y - vertexs[1].y) * (vertexs[3].x - vertexs[1].x))
            && (((vertexs[3].x <= x && x <= vertexs[1].x) && (vertexs[3].y <= y && y <= vertexs[1].y))
                || ((vertexs[3].x <= x && x <= vertexs[1].x) && (vertexs[1].y <= y && y <= vertexs[3].y))
                || ((vertexs[1].x <= x && x <= vertexs[3].x) && (vertexs[1].y <= y && y <= vertexs[3].y))
                || ((vertexs[1].x <= x && x <= vertexs[3].x) && (vertexs[3].y <= y && y <= vertexs[1].y)))
             )

            ||

            (
             ((x - vertexs[2].x) * (vertexs[3].y - vertexs[2].y) == (y - vertexs[2].y) * (vertexs[3].x - vertexs[2].x))
            && (((vertexs[3].x <= x && x <= vertexs[2].x) && (vertexs[3].y <= y && y <= vertexs[2].y))
                || ((vertexs[3].x <= x && x <= vertexs[2].x) && (vertexs[2].y <= y && y <= vertexs[3].y))
                || ((vertexs[2].x <= x && x <= vertexs[3].x) && (vertexs[2].y <= y && y <= vertexs[3].y))
                || ((vertexs[2].x <= x && x <= vertexs[3].x) && (vertexs[3].y <= y && y <= vertexs[2].y)))
             )
            );
}


void Square::printFigureName() const {
    cout << "square" << endl;
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

void Trapezoid::printFigureName() const {
    cout << "trapezoid" << endl;
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


void Rhombus::printFigureName() const {
    cout << "rhombus" << endl;
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
