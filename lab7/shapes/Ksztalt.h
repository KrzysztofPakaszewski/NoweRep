//
// Created by krzysztof on 17.04.2018.
//

#ifndef JIMP_EXERCISES_KSZTALT_H
#define JIMP_EXERCISES_KSZTALT_H

#include <iostream>
#include <cmath>
using namespace std;

class Ksztalt {
public:
    virtual void rysuj()=0;
};
class Trojkat: public Ksztalt{
public:
    Trojkat();
    void rysuj();

};
class Kwadrat: public Ksztalt{
public:
    Kwadrat();
    void rysuj();
};
class Kolo: public Ksztalt{
public:
    Kolo();
    void rysuj();

};


#endif //JIMP_EXERCISES_KSZTALT_H
