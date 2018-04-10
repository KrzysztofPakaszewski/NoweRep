//
// Created by pakakrzy on 10.04.18.
//

#include "StudentRepository.h"
using namespace academia;

StudyYear::StudyYear():year(1){}
StudyYear::StudyYear(int a):year(a){}

StudyYear StudyYear::operator++(int){
    year++;
}
StudyYear StudyYear::operator++(){
    year++;
}
StudyYear StudyYear::operator--(){
    year--;
}
StudyYear StudyYear::operator--(int){
    year--;
}
StudyYear::operator int(){
    return year;
}
Student::Student(string a,string b ,string c,string d,int e):id(a),first_name(b),last_name(c),program(d),year(e){}

StudentRepository::StudentRepository(){}
StudentRepository::StudentRepository(initializer_list<Student> list){
    for(auto pointer = list.begin();pointer!=list.end();pointer++)
    {
        rep.emplace_back(*pointer);
    }
}
void Student::ChangeFirstName(string temp){
    first_name=temp;
}
string Student::Id(){
    return id;
}
string Student::FirstName(){
    return first_name;
}
size_t StudentRepository::StudentCount(){
    return rep.size();
}
Student& StudentRepository::operator[](string id){
    for(int a =0; a<StudentCount();a++ )
    {
        if(rep[a].Id()==id)
        {
            return rep[a];
        }
    }
}