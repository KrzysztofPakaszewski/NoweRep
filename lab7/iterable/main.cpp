//
// Created by krzysztof on 23.04.2018.
//
#include <iostream>
#include "Iterable.h"
using namespace utility;
int main(){
    const vector<int> vi {7, -3};
    const vector<string> vs {"4", "9991", "adfskld"};
    for(const auto &ptr :Product(vi,vs)){
        cout << "(" << ptr.first << ", \"" << ptr.second << "\") \n";
    }

    return 0;
}