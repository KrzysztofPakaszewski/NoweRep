//
// Created by krzysztof on 06.03.2018.
//

#include "Polybius.h"


int main(int argc, char* argv[]) // 1 - input 2- output 3 - option
{
    ifstream input(argv[1]);
    if(!input)
    {
        cout << "File error\n";
        return 0;
    }
    ofstream output(argv[2]);
    if(!output)
    {
        cout << "File error\n";
        input.close();
        return 0;
    }
    string entries;
    while(!input.eof())
        getline(input,entries);
    int temp = atoi(argv[3]);
    if( temp ==1 )
    {
        output << PolybiusCrypt(entries);
    }
    if(temp == 0)
    {
        output << PolybiusDecrypt(entries);
    }
    input.close();
    output.close();
    return 0;
}