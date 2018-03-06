//
// Created by pakakrzy on 06.03.18.
//

#ifndef JIMP_EXERCISES_ARRAY2D_H
#define JIMP_EXERCISES_ARRAY2D_H

#include <iostream>
using namespace std;

int ** NewArray2D(int n_rows, int n_columns);
void FillArray2D(int n_rows, int n_columns, int *const *array);
void DrawTable(int ** array, int n_rows, int n_columns);
void DeleteArray2D(int ** array, int n_rows, int n_columns);

#endif //JIMP_EXERCISES_ARRAY2D_H
