//
// Created by krzysztof on 05.03.2018.
//

#include "Palindrome.h"

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
