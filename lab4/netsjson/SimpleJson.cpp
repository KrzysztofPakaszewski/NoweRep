//
// Created by krzysztof on 22.03.2018.
//

#include "SimpleJson.h"
#include <memory>
#include <sstream>

using namespace nets;


JsonValue::JsonValue(int number):integer(number),which(0){}
JsonValue::JsonValue(double number):doubleNum(number),which(1){}
JsonValue::JsonValue(string temp):stringObject(temp),which(2){}
JsonValue::JsonValue(bool temp):boolObject(temp),which(3){}
JsonValue::JsonValue(map<string,JsonValue> temp):mapObject(temp),which(4){}
JsonValue::JsonValue(vector<JsonValue> temp):JsonArray(temp),which(5){}

string JsonValue::choose() const
{
    string temp;
    if(this->which==0)
        temp = this->GetInteger();
    else if(this->which==1)
        temp = this->GetDouble();
    else if(this->which==2)
        temp = this->GetString(this->stringObject);
    else if(this->which==3)
        temp = this->GetBool();
    else if(this->which==4)
        temp = this->GetMap();
    else if(this->which==5)
        temp = this->GetArray();
    return temp;
}
string JsonValue::GetInteger() const
{
    stringstream os;
    os << integer;
    string temp = os.str();
    return temp;
}
string JsonValue::GetDouble() const
{
    stringstream os;
    os << doubleNum;
    string temp = os.str();
    return temp;
}
string JsonValue::GetString(string item) const
{
    string temp = "\"";
    string object = item;
    for(int a = 0 ; a< object.size();a++)
    {
        if(object[a]== '\"')
            temp += "\\\"";
        else if(object[a] == '\t')
            temp+= "\\\t";
        else if(object[a] == '\n')
            temp+="\\\n";
        else if (object[a] == '\\')
            temp+="\\\\";
        else
            temp+= object[a];
    }
    temp+= "\"";
    return temp;
}
string JsonValue::GetBool() const
{
    if(boolObject)
        return "true";
    return "false";
}
string JsonValue::GetMap() const
{
    string temp="{";

    for(auto pointer = this->mapObject.begin(); pointer!=mapObject.end();pointer++)
    {
        if(pointer == this->mapObject.begin())
            temp= temp +GetString(pointer->first)+ ": ";
        else
            temp= temp +", " +"\"" + pointer->first +"\": ";
        temp += pointer->second.choose();
    }
    temp+= "}";
    return temp;
}
string JsonValue::GetArray() const
{
    string temp="[";
    for(int a = 0;a<this->JsonArray.size();a++)
    {
        if(a==0)
            temp+= JsonArray[a].choose();
        else
            temp= temp + ", "+ JsonArray[a].choose();
    }
    temp+="]";
    return temp;
}

std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const
{
    if(which == 4) {
        for (auto pointer = this->mapObject.begin(); pointer != mapObject.end(); pointer++) {
            if (pointer->first == name) {
                return pointer->second;
            }
        }
    }
    return experimental::optional<JsonValue>{};
}
std::string JsonValue::ToString() const
{
    string result = this->choose();
    return result;
}

