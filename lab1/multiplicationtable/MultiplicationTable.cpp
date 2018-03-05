//
// Created by krzysztof on 05.03.2018.
//

#include "MultiplicationTable.h"

void MultiplicationTable(int tab[][10])
{
    for(int a = 0;a<10;a++)
        for(int b = 0; b<10;b++)
            tab[a][b]=(a+1)*(b+1);
}

void DrawTable(int tab[][10])
{
    for(int a = 0; a<10; a++)
    {
        for (int b = 0; b<10; b++)
        {
                cout <<setw(5)<< tab[a][b] << setw(5);
        }
        cout << endl;
    }
}
