//
// Created by krzysztof on 17.04.2018.
//

#include "Point3D.h"

Point3D::Point3D(){
    cout << "konstruktor bezparametrowy klasy Point3D"<<endl;
    x_ = 0;
    y_ =0;
    z_ =0;
};
Point3D::Point3D(double x, double y, double z){
    cout << "konstruktor parametrowy klasy Point3D"<<endl;
    x_ = x;
    y_ =y;
    z_ =z;
}
Point3D::~Point3D(){
    cout << "Destruktor klasy Point3D"<<endl;
}
double Point3D::GetZ()const{
    return z_;
}
double Point3D::Distance(Point3D& other){
    return sqrt(pow(this->GetX()-other.GetX(),2)+pow(this->GetY()-other.GetY(),2)+pow(this->GetZ()-other.GetZ(),2));
}