//
// Created by krzysztof on 22.03.2018.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <string>
#include <unordered_map>
using namespace std;

namespace nets
{
    class View
    {
    public:

        View(string a);
        string Render(const unordered_map<string,string>&model) const;

    private:
        string Template;
    };
}

#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
