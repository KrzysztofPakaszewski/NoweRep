//
// Created by pakakrzy on 17.04.18.
//

#include "ArrayFill.h"
using namespace arrays;
IncrementalFill::IncrementalFill(int a, int b):start(a),step(b){};
UniformFill::UniformFill(int a):number(a){};
SquaredFill::SquaredFill(int a, int b):a(a),b(b){};
namespace arrays {
    void FillArray(int size, Base &filler, vector<int> *array) {
        int a = 0;
        for (auto &i: *array) {
            i = filler.Get_Value(a);
            a++;
        }
    }
}