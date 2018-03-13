//
// Created by krzysztof on 13.03.2018.
//

#include "CCounter.h"

using namespace ccounter;


std::unique_ptr<Counter> ccounter::Init()
{
    return make_unique<Counter>();
}


void ccounter::Inc(std::string key, std::unique_ptr<Counter>* counter)
{
    bool Flag = true;
    for(int a = 0; a < counter->operator->()->Values.size() ;a++)
    {
        if(counter->operator->()->Values[a].first == key)
        {
            Flag = false;
            counter->operator->()->Values[a].second+=1;
            break;
        }
    }
    if(Flag)
    {
        counter->operator->()->Values.push_back({key,1});
    }
}

int ccounter::Counts(const std::unique_ptr<Counter> &counter, std::string key)
{
    for(int a = 0; a< counter.operator->()->Values.size(); a++)
    {
        if(counter.operator->()->Values[a].first == key)
        {
            return counter.operator->()->Values[a].second;
        }

    }
    return 0;

}

void ccounter::SetCountsTo(std::string key, int value, std::unique_ptr<Counter> *counter)
{
    bool Flag = true;
    for(int a = 0; a < (counter->operator->()->Values.size()) ;a++)
    {
        if(counter->operator->()->Values[a].first == key)
        {
            Flag = false;
            counter->operator->()->Values[a].second= value;
            break;
        }
    }
    if(Flag)
    {
        counter->operator->()->Values.push_back({key,value});
    }

}