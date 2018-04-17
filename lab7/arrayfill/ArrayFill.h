//
// Created by pakakrzy on 17.04.18.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H

#include <vector>
#include <random>
#include <memory>
using namespace std;
namespace arrays {
    class Base {
    public:
        virtual int Get_Value(int index)=0;

    };
    class IncrementalFill: public Base{
    public:
        IncrementalFill(int start,int step =1);
        int Get_Value(int index){
            return start+index*step;
        }

    private:
        int start;
        int step;
    };
    class UniformFill : public Base{
    public:
        UniformFill(int number =0);
        int Get_Value(int index){
            return number;
        }
    private:
        int number;
    };
    class SquaredFill: public Base{
    public:
        SquaredFill(int a=1, int b=0);
        int Get_Value(int index){
            return a*index*index+b;
        }

    private:
        int a;
        int b;
    };
    class RandomFill : public Base{
    public:
        RandomFill(unique_ptr<default_random_engine> , unique_ptr<uniform_int_distribution<int>>);
        int Get_Value(int index){
            return distribution->operator()(*generator);
        }

    private:
        unique_ptr< default_random_engine > generator;
        unique_ptr<uniform_int_distribution<int>> distribution;


    };
    void FillArray(int size, Base&, vector<int>*);

}


#endif //JIMP_EXERCISES_ARRAYFILL_H
