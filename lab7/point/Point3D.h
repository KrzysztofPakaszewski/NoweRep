//
// Created by krzysztof on 17.04.2018.
//

#ifndef JIMP_EXERCISES_POINT3D_H
#define JIMP_EXERCISES_POINT3D_H


#include "Point.h"

class Point3D : public Point{
public:
    Point3D();
    Point3D(double x, double y, double z);
    ~Point3D();
    double GetZ()const;
    double Distance(Point3D& other);
private:
    double z_;
};


#endif //JIMP_EXERCISES_POINT3D_H
