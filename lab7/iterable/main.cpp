//
// Created by krzysztof on 23.04.2018.
//
#include <iostream>
#include "Iterable.h"
using namespace utility;
int main(){
    vector<int>v1{1,2,3};
    vector<string>v2{"a","b","c"};
    for(const auto &ptr :Zipper(v1,v2)){
        cout << "(" << ptr.first << ", \"" << ptr.second << "\") \n";
    }

    return 0;
}