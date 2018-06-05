//
// Created by mwypych on 01.06.17.
//

#include <gtest/gtest.h>
#include "ArabicRoman.h"

TEST(roman_to_arabic,ConvertsRomanToArabicMDReturns1500){
    EXPECT_EQ(1500,RomanToArabic("MD"));
}
TEST(roman_to_arabic,ConvertsRomanToArabicMMDCCLXXReturns2770){
    EXPECT_EQ(2770,RomanToArabic("MMDCCLXX"));
}
TEST(roman_to_arabic,ConvertsRomanToArabicXLVIReturns46){
    EXPECT_EQ(46,RomanToArabic("XLVI"));
}
TEST(roman_to_arabic,ConvertsRomanToArabicCDReturns400){
    EXPECT_EQ(400,RomanToArabic("CD"));
}
TEST(roman_to_arabic,ConvertsRomanToArabicReturns999){
    EXPECT_EQ(400,RomanToArabic("CD"));
}
TEST(roman_to_arabic,WrongInputResultsInThrowInvalidArgument){
    EXPECT_THROW(RomanToArabic("XA"),invalid_argument);
}