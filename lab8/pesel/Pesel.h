//
// Created by pakakrzy on 24.04.18.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <string>
#include <stdexcept>

using namespace std;
namespace academia {
    class InvalidPeselChecksum :public invalid_argument {
    public:
        InvalidPeselChecksum(const string &__arg);

    };
    class InvalidPeselCharacter : public invalid_argument{
    public:
        InvalidPeselCharacter(const string &__arg);
    };

    class InvalidPeselLength :public invalid_argument{
    public:
        InvalidPeselLength(const string &__arg);
    };
    class AcademiaDataValidationError :public invalid_argument{
    public:
        AcademiaDataValidationError(const string &__arg);
    };

    class Pesel {

    public:
        Pesel();

        Pesel(const char *);

        void ValidatePesel(string);


    private:
        string pesel;
    };
}

#endif //JIMP_EXERCISES_PESEL_H
