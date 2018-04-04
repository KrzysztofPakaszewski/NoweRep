//
// Created by krzysztof on 27.03.2018.
//
#include "Matrix.h"
#include <iostream>
using namespace algebra;
int main()
{
    Matrix m1{{0., 2.,7.}, {8.,5., 4.},{0.,5.,0.}};
    cout <<m1.Print() << endl;
    cout << m1.Det()<< endl;
    Matrix m2(m1.Inv());
    cout << m2.Print()<<endl;
    return 0;
}