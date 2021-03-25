#include <iostream>
#include <cstdbool>

#include "figure.h"

using namespace std;

int main()
{
/*
Right vertexs for Figures:
Triangle - (4,1) (3,7) (-7,4)
Square - (1,3) (0,0) (4,2) (3,-1)
Rhombus - (3,3) (1,0) (5,0) (3,-3)
Trapezoid - (0,0) (5,-3) (5, 6) (0,6)
*/
    Triangle figure;
    bool isFigure_ = figure.setVertexs();
    if(isFigure_) {
        figure.print();
    }
    else {
        cout << "Vertices are not suitable for building a figure" << endl;
    }
    return 0;
}
