//
// Created by krzysztof on 30.05.2018.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H

template <class T, class B>
class SequentialIdGenerator {
public:
    SequentialIdGenerator(){start=0;}
    SequentialIdGenerator(B base):start(base){}
    T NextValue(){
        T temp = T(start);
        ++start;
        return temp;
    }

private:
    B start;
};


#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
