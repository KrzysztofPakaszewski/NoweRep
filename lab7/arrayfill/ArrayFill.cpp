//
// Created by pakakrzy on 17.04.18.
//

#include "ArrayFill.h"
using namespace arrays;
IncrementalFill::IncrementalFill(int a, int b):start(a),step(b){};
UniformFill::UniformFill(int a):number(a){};
SquaredFill::SquaredFill(int first, int second):a(first),b(second){};
namespace arrays {
    void FillArray(int size, Base &filler, vector<int> *array) {
        array->clear();
        for(int a =0; a< size; a++)
        {
            array->emplace_back(filler.Get_Value(a));
        }
    }
}
RandomFill::RandomFill(unique_ptr<default_random_engine> gen , unique_ptr<uniform_int_distribution<int>> dist)
{
    generator = move(gen);
    distribution = move(dist);
}