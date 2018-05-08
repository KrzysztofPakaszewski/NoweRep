//
// Created by pakakrzy on 08.05.18.
//
#include "Serialization.h"
using namespace academia;


int main()
{
    Building temp(23,"nazwa",{Room{1,"1",Room::Type ::LECTURE_HALL},{Room{1,"1",Room::Type ::COMPUTER_LAB}}});
    return 0;
}