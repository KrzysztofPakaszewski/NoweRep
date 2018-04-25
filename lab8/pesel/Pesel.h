//
// Created by pakakrzy on 24.04.18.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <string>
#include <stdexcept>

using namespace std;
namespace academia {
    class AcademiaDataValidationError :public runtime_error{
    public:
        AcademiaDataValidationError(const string &__arg);
    };
    class InvalidPeselChecksum :public AcademiaDataValidationError {
    public:
        InvalidPeselChecksum(const string &__arg);
        InvalidPeselChecksum(const string &__arg,int sum);
        const char* what() const throw(){
            stringstream os;
            os<<sum;
            string temp = "Invalid PESEL("+ arg+") checksum: "+ os.str();
            return temp.c_str();
        }

    protected:
        string arg;
        int sum;
    };
    class InvalidPeselCharacter : public invalid_argument{
    public:
        InvalidPeselCharacter(const string &__arg);
        const char* what() const throw(){
            string temp = "Invalid PESEL("+arg+") character set";
            return temp.c_str();
        }

    protected:
        string arg;
    };

    class InvalidPeselLength :public invalid_argument{
    public:
        InvalidPeselLength(const string &__arg);
        InvalidPeselLength(const string &__arg,int a);
        const char* what() const throw(){
            stringstream os;
            os<<length;
            string temp = "Invalid PESEL("+arg+") length: "+os.str();
            return temp.c_str();
        }
    protected:
        string arg;
        int length;
    };

    class Pesel {

    public:
        Pesel();

        Pesel(const char *);

        void ValidatePesel(string);

        int CheckSum(string a);

    private:
        string pesel;
    };
}

#endif //JIMP_EXERCISES_PESEL_H
