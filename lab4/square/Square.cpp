//
// Created by krzysztof on 20.03.2018.
//

#include "Square.h"
#include <vector>
using namespace std;
using namespace geometry;

double PointDistance(Point First,Point Second)
{
    return First.Distance(Second);
}
Square::Square(Point a, Point b, Point c, Point d):A(a),B(b),C(c),D(d) {}

double FindSide(const Point square[4])
{
    int counter=1;
    int NumberOfChanges=0;
    double smallest =PointDistance(square[0],square[1]);
    for(int a = 0;a<3;a++)
    {
        for(int b=a+1; b < 4;b++)
        {
            if(a == 0 && b==1)
                b++;
            double temp = PointDistance(square[a],square[b]);
            if(temp < smallest) {
                smallest = temp;
                counter = 1;
                NumberOfChanges++;
            } else if( smallest == temp)
                counter+=1;
        }
    }
    if(counter == 4 || !(NumberOfChanges>1))
        return smallest;
    return 0;
}
double Square::Circumference()
{
    Point square[4];
    square[0] = this->A;
    square[1] = this->B;
    square[2] = this->C;
    square[3] = this->D;
    return 4*FindSide(square);
}
double Square::Area()
{
    Point square[4];
    square[0] = this->A;
    square[1] = this->B;
    square[2] = this->C;
    square[3] = this->D;
    double temp = FindSide(square);
    return temp*temp;
}


