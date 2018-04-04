//
// Created by krzysztof on 27.03.2018.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <string>
#include <vector>
#include <initializer_list>
#include <complex>

using namespace std;
namespace algebra {
    class Matrix {
    public:
        Matrix(size_t columns, size_t rows);

        Matrix(vector<vector<complex<double >>>);

        Matrix();

        Matrix(initializer_list<std::vector<std::complex<double>>>);

        Matrix(string);

        Matrix(const Matrix &other);

        complex<double> Get(size_t column, size_t row) const;

        pair<size_t,size_t> Size();

        void Set(size_t column, size_t row, complex<double> number);

        Matrix Add(const Matrix other) const;

        Matrix Sub(const Matrix other) const;

        Matrix Mul(const Matrix other) const;

        Matrix Mul(const complex<double>) const;

        Matrix Pow(const int number)const;

        Matrix Div(const Matrix other) const;

        complex<double> Det() const;

        Matrix Inv() const;

        string Print() const;



    private:
        size_t columns;
        size_t rows;
        vector<vector<complex<double >>> array;
    };
}


#endif //JIMP_EXERCISES_MATRIX_H
