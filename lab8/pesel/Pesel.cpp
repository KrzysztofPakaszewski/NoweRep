//
// Created by pakakrzy on 24.04.18.
//



#include <vector>
#include <sstream>
#include "Pesel.h"
using namespace academia;
Pesel::Pesel(const char* a)
{
    ValidatePesel(a);
    pesel= a;
}
void Pesel::ValidatePesel(string a){
    if(a.size()!=11)
        throw InvalidPeselLength(a,a.size());
    for(int b=0;b<a.size();b++)
    {
        if(int(a[b])<48 ||int(a[b])>57)
            throw InvalidPeselCharacter(a);
    }
    if(CheckSum(a) != int(a[10])-48)
        throw InvalidPeselChecksum(a,CheckSum(a));

}
int Pesel::CheckSum(string a){
    vector<int> temp;
    for(int b=0;b<a.size();b++)
    {
        temp.emplace_back(int(a[b])%48);
    }
    int sum= temp[0]*9+7*temp[1]+3*temp[2]+temp[3]+temp[4]*9+7*temp[5]+3*temp[6]+temp[7]+9*temp[8]+7*temp[9];
    return sum%10;
}

Pesel::Pesel() {}

InvalidPeselLength::InvalidPeselLength(const string &__arg) : invalid_argument(__arg) {}

InvalidPeselCharacter::InvalidPeselCharacter(const string &__arg) : invalid_argument(__arg),arg(__arg) {}

AcademiaDataValidationError::AcademiaDataValidationError(const string &__arg) : runtime_error(__arg) {}

InvalidPeselChecksum::InvalidPeselChecksum(const string &__arg) : AcademiaDataValidationError(__arg) {}

InvalidPeselChecksum::InvalidPeselChecksum(const string &__arg,int sum) :sum(sum),AcademiaDataValidationError(__arg),arg(__arg){}

InvalidPeselLength::InvalidPeselLength(const string &__arg,int a):length(a),invalid_argument(__arg),arg(__arg){}