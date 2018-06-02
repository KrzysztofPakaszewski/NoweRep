//
// Created by krzysztof on 29.05.2018.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H


#include <string>
#include <utility>
using namespace std;

namespace academia {
    class TeacherId{
    public:
        TeacherId(int);
        operator int() const;
        bool operator!=(const TeacherId& other) const;
    private:
        int id;
    };
    class Teacher{
    public:
        Teacher(TeacherId a, string b, string c);
        TeacherId Id() const;
        string Name() const;
        string Department() const;
        operator!=(const Teacher& other)const;
        operator==(const Teacher& other)const;
    private:
        TeacherId id;
        string name;
        string department;
    };
    class TeacherHash {
    public:
        TeacherHash()= default;
        size_t operator()(Teacher) const;
    };
}


#endif //JIMP_EXERCISES_TEACHERHASH_H
