//
// Created by krzysztof on 04.04.2018.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>
#include <vector>
using namespace std;

namespace pool {
    class TextPool {
    public:
        TextPool();
        TextPool(TextPool && other);
        TextPool &operator=(TextPool && other);
        ~TextPool();
        TextPool(const initializer_list<experimental::string_view>);



        std::experimental::string_view Intern(const std::string &str);
        size_t StoredStringCount() const;

    private:
        set<experimental::string_view > pool;
    };
}


#endif //JIMP_EXERCISES_TEXTPOOL_H
