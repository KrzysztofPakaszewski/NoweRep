//
// Created by pakakrzy on 22.05.18.
//

#include <Logger.h>
int main()
{
    Type<string> a;
    Logger<Type<string>> temp(&a);
    temp.Error("error");
    cout << a.Get()<<endl;
    return 0;
}
