//
// Created by pakakrzy on 24.04.18.
//



#include <vector>
#include "Pesel.h"
using namespace academia;
Pesel::Pesel(const char* a)
{
    ValidatePesel(a);
    pesel= a;
}
void Pesel::ValidatePesel(string a){
    if(a.size()!=11)
        throw InvalidPeselLength("");

}

Pesel::Pesel() {}

InvalidPeselLength::InvalidPeselLength(const string &__arg) : invalid_argument(__arg) {}

InvalidPeselChecksum::InvalidPeselChecksum(const string &__arg) : invalid_argument(__arg) {}

InvalidPeselCharacter::InvalidPeselCharacter(const string &__arg) : invalid_argument(__arg) {}

AcademiaDataValidationError::AcademiaDataValidationError(const string &__arg) : invalid_argument(__arg) {}
