//
// Created by krzysztof on 15.03.2018.
//
#include <iostream>
#include "TinyUrl.h"
int main()
{
    array<char,6> temp = {'0','0','0','0','0','0'};
    for(int a = 0; a< 6;a++)
        cout << temp[a];
    cout << endl;
    tinyurl::NextHash(&temp);
    for(int a = 0; a< 6;a++)
        cout << temp[a];
    cout << endl;
    return 0;
}