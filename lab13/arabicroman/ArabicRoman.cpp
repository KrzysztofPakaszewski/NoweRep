//
// Created by pakakrzy on 05.06.18.
//

#include <stdexcept>
#include "ArabicRoman.h"

string ArabicToRoman(int n){
    if(n>3999 || n<1)
        throw invalid_argument("number out of range");
    string result;
    int input =n;
    int temp = n/1000;
    if(temp>0){
        for(int a=0;a<temp;a++)
            result+="M";
    }
    input=input%1000;
    temp = input/500;
    if(temp>0){
        for(int a=0;a<temp;a++)
            result+="D";
    }
    input=input%500;
    temp = input/100;
    if(temp>0){
        if(temp==4)
            result+="CD";
        else {
            for (int a = 0; a < temp; a++)
                result += "C";
        }
    }
    input=input%100;
    temp = input/50;
    if(temp>0){
        for(int a=0;a<temp;a++)
            result+="L";
    }
    input=input%50;
    temp=input/10;
    if(temp>0){
        if(temp==4)
            result+="XL";
        else {
            for (int a = 0; a < temp; a++)
                result += "X";
        }
    }
    input=input%10;
    temp=input/5;
    if(temp>0){
        for (int a = 0; a < temp; a++)
            result += "V";
    }
    input=input%5;
    temp=input;
    if(temp>0){
        if(temp==4)
            result+="IV";
        else {
            for (int a = 0; a < temp; a++)
                result += "I";
        }
    }
    return result;
}
int RomanToArabic(string t){
    int temp=0;
    for(int a=0; a<t.size() ;a++){
        if(t[a]!= 'M' &&t[a]!= 'C'&&t[a]!= 'D'&&t[a]!= 'X'&&t[a]!= 'I'&&t[a]!= 'V'&&t[a]!= 'L')
            throw invalid_argument("Wrong input");
        if(t[a]=='M')
        {
            temp+=1000;
        }
        if(t[a]=='C')
        {
            if(a+1<t.size() && t[a+1]=='D') {
                temp += 400;
                a+=2;
            }
            else if(a+1<t.size() && t[a+1]=='M') {
                temp += 900;
                a+=2;
            }
            else
                temp+=100;
        }
        if(t[a]=='X')
        {
            if(a+1<t.size() && t[a+1]=='L') {
                temp += 40;
                a=a+2;
            }
            else if(a+1<t.size() && t[a+1]=='C') {
                temp += 90;
                a=a+2;
            }
            else
                temp+=10;
        }
        if(t[a]=='I')
        {
            if(a+1<t.size() && t[a+1]=='V') {
                temp += 4;
                a=+2;
            }
            else if(a+1<t.size() && t[a+1]=='X') {
                temp += 9;
                a=+2;
            }
            else
                temp+=1;
        }
        if(t[a]=='V')
        {
            temp+=5;
        }
        if(t[a]=='L')
        {
            temp+=50;
        }
        if(t[a]=='D')
        {
            temp+=500;
        }

    }
    return temp;
}