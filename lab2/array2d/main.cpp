//
// Created by pakakrzy on 06.03.18.
//
#include "Array2D.h"

int main()
{
    int** array = NewArray2D(10, 10);
    DrawTable(array,10,10);
    DeleteArray2D(array,10,10);
    return 0;
}