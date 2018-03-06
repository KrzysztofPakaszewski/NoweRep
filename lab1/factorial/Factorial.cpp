//
// Created by mwypych on 02.02.17.
//
#include <climits>
#include "Factorial.h"

bool CheckOverFlow(int value, int temp);

int positive(int a)
{
    if (a<0)
        return -a;
    return a;
}

int Factorial(int value) { // Recursive
    int temp;
    if(value> 1000)
        return 0;
    if (value<0) {
        if (value == -1)
            return -1;
        temp = Factorial(value + 1);
    }
    else if(value== 0 || value == 1) {
        return 1;
    }
    else
        temp = Factorial(value - 1);
    if(CheckOverFlow(value, temp))
        return 0;
    else
        return temp*value;
}

bool CheckOverFlow(int value, int temp) { return positive(temp) > INT_MAX / positive(value); }

int factorialIT(int value) // iteration
{
    int temp=1;
    if (value < 0)
    {
        for( int a = value; a<0;a++)
        {
            temp = temp*a;
            if(positive(temp)> INT_MAX/positive(a))
                return 0;
        }
    }
    else
    {
        for (int a = value; a>0;a--)
        {
            temp = temp*a;
            if(positive(temp)> INT_MAX/positive(a))
                return 0;
        }
    }
    return temp;
}
