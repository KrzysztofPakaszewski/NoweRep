//
// Created by pakakrzy on 10.04.18.
//
#include <iostream>
#include "StudentRepository.h"
using  namespace academia;
int main()
{
    StudyYear a(2);
    cout << int(a)<<endl;
    a++;
    ++a;
    cout << int(a)<<endl;
    a--;
    --a;
    cout << int(a)<<endl;
    Student b{"a","a","a","a",2};
    StudentRepository repository
            {{"2030", "Michał", "Karak", "architektura", 5}, {"2031", "Katarzyna", "Bach", "informatyka", 3},
             {"2035", "Orson", "Sabach", "górnictwo", 2}};
    cout <<repository["2030"].FirstName()<<endl;
    repository["2030"].ChangeFirstName("ziemowit");
    cout <<repository["2030"].FirstName()<<endl;
    return 0;
}