//
// Created by krzysztof on 17.04.2018.
//
#include "Ksztalt.h"
#include <vector>
#include <random>
#include <memory>
int main()
{
    vector<unique_ptr<Ksztalt>> lista;
    default_random_engine generator;
    uniform_int_distribution<int> distribution(1,3);
    for(int a =0; a< 10; a++)
    {
        int temp = distribution(generator);
        if(temp == 1){
            lista.emplace_back(make_unique<Kwadrat>());
        } else if(temp ==2){
            lista.emplace_back(make_unique<Kolo>());
        } else{
            lista.emplace_back(make_unique<Trojkat>());
        }

    }
    for(int a =0; a< 10; a++){
        lista[a]->rysuj();
    }
    return 0;
}