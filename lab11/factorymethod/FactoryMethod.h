//
// Created by pakakrzy on 22.05.18.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H


#include <memory>
#include <vector>
#include <algorithm>
using namespace std;

namespace factoryMethod {
    template<class T>
    T Create() {
        return *make_unique<T>();
    };

    class MyType{
    public:
        MyType()= default;
        string SayHello(){
            return "hello";
        }
    };
}

//Suma
template<class T,class W>
auto Add(const T first, const W second){
    return first+second;
}


// Value
template<class T>
T Value(const T* first){
    return *first;
}

//Mean
template<class T>
auto Mean(vector<T> list){
    T temp=0;
    partial_sum(list.begin(),list.end(),[temp](T first){temp+=first;});
    return temp/list.size();
}






#endif //JIMP_EXERCISES_FACTORYMETHOD_H
