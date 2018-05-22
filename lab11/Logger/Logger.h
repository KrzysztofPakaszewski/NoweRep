//
// Created by pakakrzy on 22.05.18.
//

#ifndef JIMP_EXERCISES_LOGGER_H
#define JIMP_EXERCISES_LOGGER_H

#include <iostream>
#include <memory>
using namespace std;

template<class T>
class Logger {
public:
    Logger(T* a){
        Save = make_unique<T>(*a);
    }
    template<class W>
    void Debug(W a){
        *Save <<a;
    }
    template<class W>
    void Info(W a){
        *Save <<a;
    }
    template<class W>
    void Warning(W a){
        *Save <<a;
    }
    template<class W>
    void Error(W a)
    {
        *Save <<a;
    }

private:
    unique_ptr<T> Save;
};

template<class W>
class Type{
public:
    Type()= default;

    template <class T>
    friend void operator<<(Type& temp,T& second);

    string Get(){ return temp;}
private:
    W temp;
};
template <class T>
void operator<<(Type<T>& temp, T& second){temp += second;}


#endif //JIMP_EXERCISES_LOGGER_H
