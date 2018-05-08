//
// Created by pakakrzy on 08.05.18.
//
#include "Display.h"

int main()
{
    Display temp;
    temp.Draw();
    cout <<"\n";
    temp.DrawShape(Square(10,5));
    temp.DrawShape(Square(10,20));
    temp.Draw();
    cout <<"\n";
    return 0;
}