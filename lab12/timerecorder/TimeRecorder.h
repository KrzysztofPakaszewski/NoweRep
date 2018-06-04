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
    auto TimeRecorder(T function ){
        chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
        auto temp =function();
        chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
        return make_pair(temp, chrono::duration_cast<chrono::milliseconds>(end-start).count());
    };
}



#endif //JIMP_EXERCISES_TIMERECORDER_H
