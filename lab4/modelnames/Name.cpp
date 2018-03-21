//
// Created by krzysztof on 21.03.2018.
//

#include "Name.h"
#include <regex>
using namespace std;
using namespace model;

Name::Name(const string &first_names_surname)
{
    regex pattern {R"((.*?)\s+(.*?)\s+((.*?)\s+(.*)\s+)?)"}; // 1-2-4-5
    string temp = first_names_surname + " ";
    smatch matches;
    if(regex_match(temp,matches,pattern))
    {
        string * pointer[4];
        pointer[0] = &(this->first_name_);
        pointer[1] = &(this->second_name_);
        pointer[2] = &(this->third_name_);
        pointer[3] = &(this->last_name_);
        int NameCount=3;
        int gap=0;
        for(int a = matches.size()-1; a>0;a-- )
        {
            if(a==3)
                continue;
            if(matches[a]!="")
            {
                *pointer[NameCount]=matches[a];
                NameCount--;
                NameCount-=gap;
                gap=0;
            } else
            {
                gap++;
            }

        }
    }

}

string Name::FirstName() const
{
    return this->first_name_;
}
optional<string> Name::SecondName() const
{
    if(this->second_name_!="")
        return this->second_name_;
    return {};
}

optional<string> Name::ThirdName() const
{
    if(this->third_name_!="")
        return this->third_name_;
    return {};
}

string Name::Surname() const
{
    return this->last_name_;
}
string Name::ToFullInitials() const
{
    string initials;
    initials = initials+ this->FirstName()[0]+". ";
    if(this->SecondName())
    {
        initials =initials+ this->SecondName().value()[0]+". ";
    }
    if(this->ThirdName())
    {
        initials =initials+ this->ThirdName().value()[0]+". ";
    }
    initials= initials+ this->Surname()[0] + ".";
    return initials;
}
string Name::ToFirstNamesInitials() const
{
    string initials;
    initials = initials+ this->FirstName()[0]+". ";
    if(this->SecondName())
    {
        initials =initials+ this->SecondName().value()[0]+". ";
    }
    if(this->ThirdName())
    {
        initials =initials + this->ThirdName().value()[0]+". ";
    }
    initials+= this->Surname();
    return initials;
}

string Name::ToSurnameNames() const
{
    string names;
    names=Surname()+" ";
    names+=FirstName();
    if(this->SecondName())
    {
        names =names+ " "+SecondName().value();
    }
    if(this->ThirdName())
    {
        names =names+" "+ ThirdName().value();
    }
    return names;
}
string Name::ToNamesSurname() const
{
    string names;
    names+=FirstName();
    if(this->SecondName())
    {
        names =names+ " "+SecondName().value();
    }
    if(this->ThirdName())
    {
        names =names+" "+ ThirdName().value();
    }
    names=names+ " "+Surname();
    return names;

}
bool Name::IsBeforeBySurname(const Name &other) const
{
    string tempCurrent = this->Surname();
    string tempOther=other.Surname();
    int a = 0;
    while(a<tempCurrent.size() && a<tempOther.size())
    {
        if(int(tempCurrent[a])<97 )
            tempCurrent[a]= char(int(tempCurrent[a])+32);
        if(int(tempOther[a])<97 )
            tempOther[a]= char(int(tempOther[a])+32);
        if(int(tempCurrent[a])< int(tempOther[a]))
            return true;
        else if(int(tempCurrent[a])> int(tempOther[a]))
            return false;
        else
            a++;
    }
    if(a==tempCurrent.size())
        return true;
    return false;
}
bool Name::IsBeforeByFirstName(const Name &other) const
{

}