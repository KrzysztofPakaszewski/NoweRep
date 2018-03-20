//
// Created by krzysztof on 20.03.2018.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H

#include "Point.h"
#include <cmath>
namespace geometry {
    class Square {
    public:
        Square(Point, Point, Point, Point);

        double Circumference();
        double Area();

        Point A, B, C, D;
    };
    double Distance(Point,Point);
}

#endif //JIMP_EXERCISES_SQUARE_H
