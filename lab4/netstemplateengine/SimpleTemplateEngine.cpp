//
// Created by krzysztof on 22.03.2018.
//

#include <iostream>
#include "SimpleTemplateEngine.h"
#include <memory>
#include <regex>

using namespace nets;

View::View(string a): Template(a){}

string View::Render(const unordered_map<string,string>&model) const
{
    string result = this->Template;
    regex pattern {R"(.*?(\{\{(\w*?)\}\}).*)"};
    smatch matches;
    int move=0;
    string temp2 = result.c_str()+move;
    while(regex_search(temp2,matches,pattern))
    {
        bool Flag = false;
        string temp = "{{" + matches[2].str() + "}}";
        size_t position = temp2.find(temp) +move;
        for(auto pointer = model.begin();pointer!= model.end() ;pointer++ )
        {
            if(matches[2].str() == pointer->first )
            {
                result.replace(position,temp.length(),pointer->second);
                move = position + pointer->second.length();
                Flag = true;
            }
        }
        if(!Flag) {
            result.replace(position, temp.length(), "");
            move = position;
        }
        temp2=result.c_str()+move;
    }
    return result;
}