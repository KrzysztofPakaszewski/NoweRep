//
// Created by pakakrzy on 06.03.18.
//

#include <iomanip>
#include "Array2D.h"



int ** NewArray2D(int n_rows, int n_columns)
{
    if(n_rows <1 || n_columns <1)
        return 0;
    int ** array = new int* [n_rows];
    for(int a = 0; a < n_rows; a++)
        array[a] = new int[n_columns];
    FillArray2D(n_rows, n_columns, array);
    return array;
}

void FillArray2D(int n_rows, int n_columns, int *const *array) {
    int counter = 1;
    for(int a = 0; a<n_rows;a++)
    {
        for (int b = 0; b<n_columns;b++) {
            array[a][b] = counter;
            counter ++;
        }
    }
}
void DrawTable(int ** array, int n_rows, int n_columns)
{
    for( int a = 0; a<n_rows; a++)
    {
        for (int b = 0; b<n_columns;b++)
            cout << setw(5) << array[a][b] << setw(5);
        cout << endl;
    }
}

void DeleteArray2D(int ** array, int n_rows, int n_columns)
{
    for(int a = 0; a< n_rows;a++)
        delete[] array[a];
    delete[] array;
}