//
// Created by krzysztof on 27.03.2018.
//

#include "Matrix.h"
#include <memory>
#include <iostream>

using namespace algebra;
Matrix::Matrix(size_t columns, size_t rows)
{
    for(int a = 0; a< rows;a++)
    {
        vector<complex<double>> temp;
        for(int b = 0; b< columns;b++)
        {
            temp.push_back({0,0});
        }
        array.push_back(temp);
    }
    this->columns = columns;
    this->rows = rows;
}

Matrix::Matrix(vector<vector<complex<double >>> list)
{
    array = list;
    this->rows = list.size();
    this->columns = list[0].size();
}

Matrix::Matrix()
{
    columns=0;
    rows=0;
}

Matrix::Matrix(const Matrix &other)
{
    array = other.array;
    columns = other.columns;
    rows = other.rows;
}

Matrix::Matrix(initializer_list<std::vector<std::complex<double>>> list)
{
    bool flag = true;
    for(auto pointer = list.begin();pointer!=list.end();pointer++)
    {
        vector<complex<double>> temp;
        for(int b = 0; b< pointer->size();b++)
        {
            temp.push_back(pointer[0][b] );
        }
        if(flag) {
            columns = temp.size();
            flag =false;
        }
        else if(columns != temp.size()){
            cout << "ERROR, BAD MATRIX\n";
        }
        array.push_back(temp);
    }
    rows = array.size();
}



complex<double> Interpret(string number)
{
    string real;
    string imaginary;
    bool Flag = true;
    for(int a = 0;a< number.size();a++)
    {
        if( Flag)
        {
            if(number[a] == 'i')
            {
                Flag = false;
            }
            else
            {
                real+=number[a];
            }
        }
        else
        {
            imaginary+= number[a];
        }
    }
    complex<double> result;
    if(Flag)
    {
        if( real =="")
            result = {0,0};
        else
            result={stod(real),0};
    }
    else
    {
        result={stod(real),stod(imaginary)};

    }
    return result;
}

Matrix::Matrix(string matrix)
{
    string number;
    vector<complex<double >> row;
    bool flag = true;
    for(int a = 0; a< matrix.size();a++)
    {
        if(matrix[a] == '[')
            continue;

        if(matrix[a] == ' ')
        {
            if(number == "")
                continue;
            row.push_back(Interpret(number));
            number = "";
        }

        if(matrix[a] == ';' || matrix[a] == ']')
        {
            if(number != "")
                row.push_back(Interpret(number));
            number = "";
            if(flag) {
                columns = row.size();
                flag = false;
            }
            else if( columns != row.size())
                cout << "ERROR, BAD MATRIX\n";
            array.push_back(row);
            row.clear();
        }
        else
            number+= matrix[a];
    }
    rows = array.size();
}

complex<double> Matrix::Get(size_t column, size_t row) const
{
    return array[row][column];
}
pair<size_t,size_t> Matrix::Size()
{
    return {columns,rows};
}
void Matrix::Set(size_t column, size_t row, complex<double> number)
{
    array[row][column] = number;
}
Matrix Matrix::Add(const Matrix other) const
{
    if(this->rows ==other.rows  && this->columns == other.columns)
    {
        vector<vector<complex<double>>> result;

        for(int a = 0; a<rows;a++)
        {
            vector<complex<double>> row;
            for(int b = 0; b< columns;b++)
            {
                row.push_back(this->Get(b,a)+ other.Get(b,a));
            }
            result.push_back(row);
        }
        Matrix Mresult(result);
        return Mresult;
    }
}

Matrix Matrix::Sub(const Matrix other) const
{
    if(this->rows ==other.rows  || this->columns == other.columns)
    {
        vector<vector<complex<double>>> result;

        for(int a = 0; a<rows;a++)
        {
            vector<complex<double>> row;
            for(int b = 0; b< columns;b++)
            {
                row.push_back(this->Get(b,a)- other.Get(b,a));
            }
            result.push_back(row);
        }
        Matrix Mresult(result);
        return Mresult;
    }
}
Matrix Matrix::Mul(const Matrix other) const
{
    if(this->columns == other.rows)
    {
        vector<vector<complex<double>>> result;

        for(int a = 0; a<rows;a++)
        {
            vector<complex<double>> row;
            for(int b = 0; b< other.columns;b++)
            {
                complex<double> temp = {0,0};
                for(int c = 0; c< columns;c++)
                {
                    temp= temp + (this->array[a][c]*other.array[c][b]);
                }
                row.push_back(temp);
            }
            result.push_back(row);
        }
        Matrix Mresult(result);
        return Mresult;
    }
    return Matrix();
}
Matrix Matrix::Mul(const complex<double> number) const
{
    vector<vector<complex<double>>> result;

    for(int a = 0; a<rows;a++)
    {
        vector<complex<double>> row;
        for(int b = 0; b< columns;b++)
        {
            row.push_back(number* this->Get(b,a));
        }
        result.push_back(row);
    }
    Matrix Mresult(result);
    return Mresult;
}
Matrix Matrix::Pow(const int number)const
{
    Matrix result (*this);
    for(int a = 0;a<number-1;a++)
    {
        result = result.Mul(*this);
    }
    if(number == 0)
    {
        vector<vector<complex<double >>> temp;
        for(int a =0;a<rows;a++)
        {
            vector<complex<double>> row;
            for(int b =0;b<columns;b++)
            {
                if( a == b)
                {
                    row.push_back({1,0});
                }
                else
                {
                    row.push_back({0,0});
                }
            }
            temp.push_back(row);
        }
        return Matrix(temp);
    }
    return result;
}
string Matrix::Print() const
{
    string result = "[";
    for(int a = 0; a < rows;a++)
    {
        if(a!= 0)
            result+="; ";
        for(int b = 0; b< columns;b++)
        {
            if(b!=0)
                result+=", ";
            ostringstream os;
            os<< array[a][b].real();
            result = result + os.str();
            ostringstream as;
            as << array[a][b].imag();
            result = result+ "i"+ as.str();
        }
    }
    result+= "]";
    return result;
}

complex<double> Matrix::Det() const
{
    if(this->columns == this->rows) {
        vector<vector<complex<double>>> temp = this->array;
        for(int column = 0; column< this->rows;  column++)
        {
            for(int row = column+1; row < this->columns ; row++)
            {
                if(temp[column][column]== complex<double>({0,0}))
                {
                    for(int a = 0;a< this->columns;a++)
                    {
                        temp[row-1][a] = temp[row-1][a] +temp[row][a];
                    }
                }
                complex<double> scalar = temp[row][column]/temp[column][column];
                for(int a = 0; a < this->columns ; a++)
                {
                    temp[row][a] = temp[row][a] - scalar*temp[column][a];
                }
            }
        }
        complex<double> result ={1,0};
        for(int a = 0; a< this->rows;a++)
        {
            result*= temp[a][a];
        }
        if(result.real()==-0)
            result.real(0);
        if(result.imag()==-0)
            result.imag(0);
        return result;
    }
    return {0,0};
}
Matrix Matrix::Inv()const
{
    complex<double> Zero = {0,0};
    if(this->Det() != Zero)
    {
        vector<vector<complex<double>>> temp = this->array;
        Matrix result(this->columns,this->rows);
        for(int a = 0; a< this->rows;a++)
        {
            result.array[a][a] = {1,0};
        }
        for(int column = 0; column< this->rows;  column++)
        {
            for(int row = column+1; row < this->columns ; row++)
            {
                if(temp[column][column]== complex<double>({0,0}))
                {
                    for(int a = 0;a< this->columns;a++)
                    {
                        temp[row-1][a] = temp[row-1][a] +temp[row][a];
                    }
                }
                complex<double> scalar = temp[row][column]/temp[column][column];
                for(int a = 0; a < this->columns ; a++)
                {
                    temp[row][a] = temp[row][a] - scalar*temp[column][a];
                    result.array[row][a] = result.array[row][a] - scalar*result.array[column][a];
                }
            }
        }
        for(int column = this->columns-1; column>=0;  column--)
        {
            for(int row = column-1; row >= 0 ; row--)
            {
                if(temp[column][column]== complex<double>({0,0}))
                {
                    for(int a = 0;a< this->columns;a++)
                    {
                        temp[row+1][a] = temp[row+1][a] +temp[row][a];
                    }
                }
                complex<double> scalar = temp[row][column]/temp[column][column];
                for(int a = 0; a < this->columns ; a++)
                {
                    temp[row][a] = temp[row][a] - scalar*temp[column][a];
                    result.array[row][a] = result.array[row][a] - scalar*result.array[column][a];
                }
            }
        }
        for(int row = 0; row< this->rows;row++)
        {
            complex<double> scalar = temp[row][row];
            for(int a = 0;a<this->columns;a++ )
            {
                result.array[row][a] = result.array[row][a]/scalar;
            }
        }
        for(int a = 0;a<result.rows;a++)
        {
            for(int b = 0;b<result.columns;b++)
            {
                if (result.array[a][b].real() == -0)
                    result.array[a][b].real(0);
                if (result.array[a][b].imag() == -0)
                    result.array[a][b].imag(0);
            }
        }
        return result;

    }
    return Matrix();
}
Matrix Matrix::Div(const Matrix other) const
{
    complex<double> Zero = {0,0};
    if(other.Det()!=Zero)
    {
        return this->Mul(other.Inv());
    }
    return Matrix();
}