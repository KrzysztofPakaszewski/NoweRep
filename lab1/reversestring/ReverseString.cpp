//
// Created by krzysztof on 05.03.2018.
//

#include "ReverseString.h"

string Reverse(string str)
{
    string temp = "";
    const char *character = str.c_str();
    if(character[0] == ('\0'))
        return "";
    temp+= Reverse(character + 1);
    temp+=character[0];
    return temp;
}
