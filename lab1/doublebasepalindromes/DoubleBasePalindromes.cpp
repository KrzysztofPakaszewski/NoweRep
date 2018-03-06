//
// Created by krzysztof on 05.03.2018.
//

#include "DoubleBasePalindromes.h"

bool is_palindrome(string str)
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
    char bufferB[64];
    char bufferD[20];
    itoa(number,bufferB,2);
    itoa(number,bufferD,10);
    if(is_palindrome(bufferB) && is_palindrome(bufferD))
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