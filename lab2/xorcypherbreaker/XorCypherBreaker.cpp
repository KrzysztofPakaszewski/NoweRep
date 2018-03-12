//
// Created by krzysztof on 12.03.2018.
//

#include <cstring>
#include "XorCypherBreaker.h"
char CryptoAnalysis(vector<char> column) //most frequent letters in column
{
    int Table[256];
    for(int a = 0;a<256;a++)
        Table[a]=0;
    for(int a =0;a<column.size();a++)
    {
        Table[column[a]]+=1;
    }
    int MostFrequentIterator=0;
    for(int b =0;b<256;b++ )
    {
        if(Table[MostFrequentIterator]<Table[b])
            MostFrequentIterator=b;
    }
    return char(MostFrequentIterator);

}
string Decrypt(vector<char> cryptogram,string key )
{
    int temp =0;
    string decrypted;
    for(int a = 0;a<cryptogram.size();a++)
    {
        temp = temp % key.size();
        decrypted+= char(cryptogram[a]^key[temp]);
        temp++;
    }
    return decrypted;
}
vector<int> ChangeCurrent(vector<int> current,vector<char> Letters)
{
    vector<int> temp = current;
    temp[temp.size()-1] +=1;
    if(temp[temp.size()-1] > Letters.size()-1)
    {
        temp[temp.size()-1]=0;
        temp[temp.size()-2]+=1;
    }
    for(int a = 1;a<temp.size();a++)
    {
        if(temp[a]> Letters.size()-1) {
            temp[a - 1] += 1;
            temp[a]=0;

        }
    }
    return temp;
}
string XorCypherBreaker(const vector<char> &cryptogram,
                        int key_length,
                        const vector<string> &dictionary)
{
    vector<char> MostFrequentLetters={' ','e','t','a','o','i'}; //english
    vector<char> columns[key_length];
    int number =0;
    for(int a =0; a<cryptogram.size();a++)
    {
        number = number%key_length;
        columns[number].push_back(cryptogram[a]);
        number++;
    }
    vector<char> MostFrequent; //letters in columns
    for(int a = 0; a< key_length;a++)
        MostFrequent.push_back(CryptoAnalysis(columns[a]));

    vector<int> CurrentLetter;
    for(int a = 0; a< key_length;a++)
        CurrentLetter.push_back(0);
    string key="";
    while(true)
    {
        key ="";
        for(int a = 0; a< key_length;a++)
        {
            key+= char(MostFrequent[a]^MostFrequentLetters[CurrentLetter[a]]);
        }
        string Decrypted = Decrypt(cryptogram,key);
        int a = 0;
        if(strstr(Decrypted.c_str(),dictionary[0].c_str()))
            a+=1;
        if(strstr(Decrypted.c_str(),dictionary[1].c_str()))
            a++;
        if(strstr(Decrypted.c_str(),dictionary[2].c_str()))
            a++;
        if(strstr(Decrypted.c_str(),dictionary[3].c_str()))
            a++;
        if(strstr(Decrypted.c_str(),dictionary[4].c_str()))
            a++;
        if(strstr(Decrypted.c_str(),dictionary[5].c_str()))
            a++;
        if(a > 1)
            break;
        CurrentLetter = ChangeCurrent(CurrentLetter,MostFrequentLetters);
    }
    return key;

}