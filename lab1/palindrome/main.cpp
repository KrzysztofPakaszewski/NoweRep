//
// Created by krzysztof on 05.03.2018.
//

#include <iostream>
#include "Palindrome.h"

int main()
{
    for(;;)
    {
        int temp;
        cout << "0 - sprawdz palindrom\n1 - wyjscie\n";
        cin >> temp;
        if(temp)
            break;
        else
        {
            string clean;
            getline(cin,clean);
            cout << "Podaj napis\n";
            string word;
            getline(cin, word);
            if(is_palindrome(word))
                cout << "Podany napis jest palindromem\n";
            else
                cout << "Podany napis nie jest palindromem\n";
        }
    }
    return 0;
}