//
// Created by krzysztof on 06.03.2018.
//

#include "Polybius.h"
#include <cstdlib>

string FindNumber(char character)
{
    char Table[5][5];
    int count = 97;
    for(int a = 0; a<5;a++)
    {
        for (int b =0; b<5; b++)
        {
            if(count == 106)
                count++;
            Table[a][b]=char(count);
            count++;
        }
    }
    string temp;
    char buff[2];
    if(character == 'j')
        character = 'i';
    for(int a = 0; a<5; a++)
    {
        for(int b = 0; b<5; b++)
        {
            if(Table[a][b]==character)
            {
                itoa((a+1)*10+b+1,buff,10);
                temp+=buff;
                return temp;
            }
        }
    }
}

char FindChar(int number)
{
    char Table[5][5];
    int count = 97;
    for(int a = 0; a<5;a++)
    {
        for (int b =0; b<5; b++)
        {
            if(count == 106)
                count++;
            Table[a][b]=char(count);
            count++;
        }
    }
    for(int a = 0; a<5; a++)
    {
        for(int b = 0; b<5; b++)
        {
            if((a+1)*10+b+1 == number)
                return Table[a][b];
        }
    }
}

string PolybiusCrypt(string message)
{
    string crypted;
    for(int a = 0; a< message.size(); a++)
    {
        int temp = int(message[a]);
        if(temp == 32)
            continue;
        if(temp>64 && temp <91)
            crypted+=FindNumber(char(temp+32));
        else
            crypted+=FindNumber(message[a]);
    }
    return crypted;
}
string PolybiusDecrypt(string crypted)
{
    char temp[3];
    temp[3] = 0;
    string decrypted;
    for(int a = 0; a < crypted.size(); a+=2)
    {
        temp[0]=crypted[a];
        temp[1]=crypted[a+1];
        decrypted+= FindChar(atoi(temp));
    }
    return decrypted;
}