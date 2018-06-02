//
// Created by krzysztof on 29.05.2018.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H

#include <chrono>
#include <utility>
using namespace std;

namespace profiling {
    template <typename T>
    auto TimeRecorder(const T &&function){
        chrono::steady_clock::time_point start = chrono::steady_clock::now();
        function();
        chrono::steady_clock::time_point end = chrono::steady_clock::now();
        return pair<T,double>{function(), chrono::duration_cast<chrono::milliseconds>(end-start).count()};
    };
}



#endif //JIMP_EXERCISES_TIMERECORDER_H
