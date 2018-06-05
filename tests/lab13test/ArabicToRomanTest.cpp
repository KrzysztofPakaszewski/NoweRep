//
// Created by mwypych on 01.06.17.
//

#include <gtest/gtest.h>
#include "ArabicRoman.h"


TEST(arabic_to_roman,ConvertOfArabic1ReturnsStringI){
    EXPECT_EQ("I",ArabicToRoman(1));
}
TEST(arabic_to_roman,ConvertOfArabic2ReturnsStringII){
    EXPECT_EQ("II",ArabicToRoman(2));
}
TEST(arabic_to_roman,ConvertOfArabic4ReturnsStringIV){
    EXPECT_EQ("IV",ArabicToRoman(4));
}
TEST(arabic_to_roman,ConvertOfArabic5ReturnsStringV){
    EXPECT_EQ("V",ArabicToRoman(5));
}
TEST(arabic_to_roman,ConvertOfArabic2000ReturnsStringMM){
    EXPECT_EQ("MM",ArabicToRoman(2000));
}
TEST(arabic_to_roman,ConvertOfArabic1500ReturnsStringMD){
    EXPECT_EQ("MD",ArabicToRoman(1500));
}
TEST(arabic_to_roman,ConvertOfArabic40ReturnsStringXL){
    EXPECT_EQ("XL",ArabicToRoman(40));
}
TEST(arabic_to_roman,ConvertOfArabic436ReturnsStringCDXXXVI){
    EXPECT_EQ("CDXXXVI",ArabicToRoman(436));
}
TEST(arabic_to_roman,ConvertOfArabic0ThrowsInvalidArgument){
    EXPECT_THROW(ArabicToRoman(0),invalid_argument);
}
TEST(arabic_to_roman,ConvertOfArabic4000ThrowsInvalidArgument){
    EXPECT_THROW(ArabicToRoman(4000),invalid_argument);
}