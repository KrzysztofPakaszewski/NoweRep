//
// Created by pakakrzy on 08.05.18.
//

#ifndef JIMP_EXERCISES_DISPLAY_H
#define JIMP_EXERCISES_DISPLAY_H

#include <iostream>
#include <vector>
using  namespace std;


class Displayable{
public:
    virtual vector<vector<char>> Shape()const=0;
    virtual pair<int,int> Position()const=0;
};

class Square:public Displayable{
public:
    Square(int,int);
    vector<vector<char>> Shape()const override;
    pair<int,int> Position()const override;
private:
    int x,y;
};


class Display { // 20x48
public:
    Display();
    void Draw();
    void DrawShape(const Displayable& Shape);
private:
    vector<vector<char>> Screen;
};


#endif //JIMP_EXERCISES_DISPLAY_H
