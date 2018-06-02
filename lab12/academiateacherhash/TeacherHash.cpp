//
// Created by krzysztof on 29.05.2018.
//

#include "TeacherHash.h"
using namespace academia;

TeacherId::TeacherId(int a) :id(a){}
TeacherId::operator int()const { return id;}
Teacher::Teacher(TeacherId a, string b, string c):id(a),name(b),department(c){}
TeacherId Teacher::Id() const{ return id;}
string Teacher::Name()const { return name;}
string Teacher::Department()const{ return department;}

size_t TeacherHash::operator()(Teacher a) const{
    hash <string> StringHash;
    hash <int> IntHash;
    return IntHash((int)(a.Id())) <<1 + StringHash(a.Name())+ StringHash(a.Department());
}

bool TeacherId::operator!=(const TeacherId& other) const{
    return (int)(*this) != (int)(other);
}

Teacher::operator!=(const Teacher& other)const{
    return this->Id()!= other.Id() || this->Name() != other.Name() || this->Department()!= other.Department();
}
Teacher::operator==(const Teacher& other)const{
    return this->Id()== other.Id() && this->Name() == other.Name() && this->Department()== other.Department();
}