//
// Created by krzysztof on 22.03.2018.
//
#include <regex>
#include <iostream>
#include "SimpleTemplateEngine.h"


int main()
{
    regex pattern {R"(.*?(\{\{(\w*?)\}\}).*?)"};
    smatch match;
    smatch match2;
    string temp = "Person:\\n\\tName: {{name}}\\n\\t2nd time name: {{name}}\\n\\tAge: {{age}}\\n\\tNo surname!";
    string temp2 = "{{something}}";
    if(regex_match(temp,match,pattern))
    {
        for(int a = 0 ;a<match.size();a++)
            cout <<a<<"\t"<< match[a] << endl;
    }
    if(regex_match(temp,match2,pattern))
    {
        for(int a = 0 ;a<match2.size();a++)
            cout <<a<<"\t"<< match2[a] << endl;
    }
    return 0;
}