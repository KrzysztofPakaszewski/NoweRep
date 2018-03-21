//
// Created by krzysztof on 21.03.2018.
//
#include "Name.h"
#include <regex>
#include <iostream>
using namespace std;
using namespace model;

int main()
{
    Name osoba("Jan Adam Pawel Kowalski");
    cout<< osoba.FirstName()<<endl;
    cout<< osoba.Surname()<<endl;
    cout<< osoba.ToFirstNamesInitials()<<endl;
    cout<< osoba.ToFullInitials()<<endl;
    cout<< osoba.ToNamesSurname()<<endl;
    cout << osoba.ToSurnameNames()<<endl;
    return 0;
}