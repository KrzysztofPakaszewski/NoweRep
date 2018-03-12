//
// Created by krzysztof on 12.03.2018.
//

#ifndef JIMP_EXERCISES_XORCYPHERBREAKER_H
#define JIMP_EXERCISES_XORCYPHERBREAKER_H


#include <string>
#include <vector>
#include <iostream>
using namespace std;

string XorCypherBreaker(const vector<char> &cryptogram,
                             int key_length,
                             const vector<string> &dictionary);

string Decrypt(vector<char> cryptogram,vector<char> key );


#endif //JIMP_EXERCISES_XORCYPHERBREAKER_H
