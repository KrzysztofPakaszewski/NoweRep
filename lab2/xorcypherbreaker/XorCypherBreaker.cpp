//
// Created by krzysztof on 12.03.2018.
//
#include <algorithm>
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
    for(int a = temp.size()-1;a>0;a--)
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
        vector<string> Words;
        string temp;
        for(int a = 0; a< Decrypted.size();a++)
        {
            if(Decrypted[a] == ' ')
            {
                Words.push_back(temp);
                temp = "";
            }
            else
                temp+=Decrypted[a];
        }
        int counter = 0;
        for(int a = 0;a<10;a++)
        {
            if(find(Words.begin(),Words.end(),dictionary[a])!= Words.end())
                counter++;
        }
        if(counter > 3)
            break;
        CurrentLetter = ChangeCurrent(CurrentLetter,MostFrequentLetters);
    }
    return key;

}