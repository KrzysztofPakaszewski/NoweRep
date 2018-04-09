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
TextPool::TextPool(const initializer_list<experimental::string_view> list)
{
    for(auto pointer = list.begin();pointer!=list.end();pointer++)
    {
        pool.emplace(*pointer);
    }
}
std::experimental::string_view TextPool::Intern(const std::string &str)
{
    return *pool.emplace(str).first;
}
size_t TextPool::StoredStringCount() const
{
    return pool.size();
}