//
// Created by krzysztof on 15.03.2018.
//

#ifndef JIMP_EXERCISES_TINYURL_H
#define JIMP_EXERCISES_TINYURL_H

#include <memory>
#include <vector>
#include <string>
#include <utility>
#include <array>
using namespace std;
namespace tinyurl {

    struct TinyUrlCodec
    {
        vector < pair<array<char,6>,string>> Url;
    };
    std::unique_ptr<TinyUrlCodec> Init();

    void NextHash(std::array<char, 6> *state);

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec);

    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash);
}

#endif //JIMP_EXERCISES_TINYURL_H
