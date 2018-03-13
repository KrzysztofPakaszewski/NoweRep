//
// Created by krzysztof on 13.03.2018.
//

#ifndef JIMP_EXERCISES_CCOUNTER_H
#define JIMP_EXERCISES_CCOUNTER_H

#include <string>
#include <memory>
#include <vector>
#include <map>

using namespace std;

namespace ccounter
{
    struct Counter
    {
        vector<pair<string,int>> Values;
    };
    std::unique_ptr<Counter> Init();
    void Inc(std::string key, std::unique_ptr<Counter>* counter);
    int Counts(const std::unique_ptr<Counter> &counter, std::string key);
    void SetCountsTo(std::string key, int value, std::unique_ptr<Counter> *counter);
}


#endif //JIMP_EXERCISES_CCOUNTER_H
