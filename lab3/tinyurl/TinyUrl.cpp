//
// Created by krzysztof on 15.03.2018.
//

#include "TinyUrl.h"
using namespace tinyurl;


std::unique_ptr<TinyUrlCodec> tinyurl::Init()
{
    return make_unique<TinyUrlCodec>();
}

void tinyurl::NextHash(std::array<char, 6> *state)
{
    state->at(5) +=1;
    for(int a = 5; a> 0; a++)
    {
        if(state->at(a) == char(123))
        {
            state->at(a) = '0';
            state->at(a-1) +=1;
        }
        else if(state->at(a)==char(91))
        {
            state->at(a)=char(97);
        }
        else if( state->at(a) == char(58))
            state->at(a)=char(65);
    }
}

std::string tinyurl::Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec)
{
    if(codec->operator->()->Url.size() ==0)
    {
        array<char,6> temp = {'0','0','0','0','0','0'};
        codec->operator->()->Url.push_back({temp,url});
        return "000000";
    }
    for(int a = 0; a< codec->operator->()->Url.size();a++)
    {
        if(codec->operator->()->Url[a].second == url)
        {
            string Encoded;
            for(int b = 0;b<6;b++)
                Encoded+=codec->operator->()->Url[a].first[b];
            return Encoded;
        }
    }
    array<char,6> temp = codec->operator->()->Url[codec->operator->()->Url.size()-1].first;
    NextHash(&temp);
    codec->operator->()->Url.push_back({temp,url});
    string Encoded;
    for(int a = 0; a< temp.size();a++)
        Encoded+=codec->operator->()->Url[a].first[a];
    return Encoded;
}

std::string tinyurl::Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash)
{
    if(hash.size()>6)
        return "Wrong Hash";
    array<char,6> array;
    for(int a =0;a<hash.size();a++)
        array[a] = hash[a];
    for(int a = 0; a< codec.operator->()->Url.size();a++)
    {
        if(codec.operator->()->Url[a].first == array)
        {
            return codec.operator->()->Url[a].second;
        }
    }
    return "No URL found";
}