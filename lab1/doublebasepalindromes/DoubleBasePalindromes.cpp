//
// Created by krzysztof on 05.03.2018.
//

#include "DoubleBasePalindromes.h"
#include <sstream>
string Reverse2(string str)
{
    string temp = "";
    const char *character = str.c_str();
    if(character[0] == ('\0'))
        return "";
    temp+= Reverse2(character + 1);
    temp+=character[0];
    return temp;
}
string DecimalToBinary(int number)
{
    int Current = number;
    string temp;
    while(Current!=0)
    {
        if(Current%2==0)
            temp+="0";
        else
            temp+="1";
        Current = int(Current/2);
    }
    return Reverse2(temp);
}
bool is_palindrome1(string str)
{
    int number = int(str.size());
    int middle = int(number/2);
    for(int a = 0; a<middle; a++)
    {
        if(str[a] != str[number-1-a])
            return false;
    }
    return true;
}
bool checkDoubleBasePalindromes(int number)
{
    string bufferB;
    string bufferD;
    ostringstream oss;
    oss << number;
    bufferD = oss.str();
    bufferB = DecimalToBinary(number);
    if(is_palindrome1(bufferB) && is_palindrome1(bufferD))
        return true;
    else
        return false;
}

uint64_t DoubleBasePalindromes(int max_value_exlusive)
{
    uint64_t temp = 0;
    for(int a = 0; a < max_value_exlusive; a++)
    {
        if(checkDoubleBasePalindromes(a))
            temp += uint64_t(a);
    }
    return temp;
}