//
// Created by krzysztof on 04.04.2018.
//

#include <iostream>
#include "TextPool.h"
using namespace pool;


TextPool::TextPool()
{

}
TextPool::TextPool(TextPool && other)
{
    if(this != &other) {
        this->pool = other.pool;
        other.pool.clear();
    }
}
TextPool & TextPool::operator=(TextPool && other)
{
    if(this != &other) {
        this->pool = other.pool;
        other.pool.clear();
    }
}
TextPool::~TextPool()
{

}
TextPool::TextPool(initializer_list<string> list)
{
    for(auto pointer = list.begin();pointer!=list.end();pointer++)
    {
        if(pool.find(pointer[0]) == pool.end())
            pool.insert(pointer[0]);
    }
}
std::experimental::string_view TextPool::Intern(const std::string &str)
{
    if(pool.find(str)==pool.end())
    {
        pool.insert(str);
    }
    return *pool.find(str);
}
size_t TextPool::StoredStringCount() const
{
    return pool.size();
}