#include <iostream>
#include <cstdbool>

#include "figure.h"
#include "printFunctions.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
/*
Right vertexs for Figures:
Triangle - (4,1) (3,7) (-7,4)
Square - (1,3) (0,0) (4,2) (3,-1)
Rhombus - (3,3) (1,0) (5,0) (3,-3)
Trapezoid - (0,0) (5,-3) (5, 6) (0,6)
*/
    Trapezoid figure;
    bool isFigure_ = figure.setVertexs();
    if(isFigure_) {
        figure.print();

    }
    else {
        cout << "Вершины не подходят для создания фигуры." << endl;
    }
    return 0;
}
