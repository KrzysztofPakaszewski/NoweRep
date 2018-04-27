//
// Created by krzysztof on 23.04.2018.
//

#include <iostream>
#include "Iterable.h"
using namespace utility;

ZipperIterator::ZipperIterator(std::vector<int>::const_iterator left, std::vector<std::string>::const_iterator right,
                               std::vector<int>::const_iterator left_end,std::vector<std::string>::const_iterator right_end):
        left(left),right(right), left_end(left_end),right_end(right_end){}

pair<int,string> ZipperIterator::Dereference() const{
    if(right == right_end || left==left_end){
        pair<int,string> temp;
        if(right == right_end)
            temp.first=0;
        else
            temp.first=*left;
        if(left==left_end)
            temp.second="";
        else
            temp.second=*right;
        return temp;
    }
    return pair<int,string>{*left, *right};
};
IterableIterator& ZipperIterator::Next()
{
    if(left+1!= left_end) {
        ++left;
    }
    if(right+1 != right_end){
        ++right;
    }
    if(left+1 == left_end && right+1 == right_end)
    {
        left = left_end;
        right=right_end;
    }
    return *this;
}
bool ZipperIterator::NotEquals(const unique_ptr<IterableIterator> &other) const{
    return this->Dereference() != other.operator->()->Dereference();
}

IterableIteratorWrapper::IterableIteratorWrapper(unique_ptr<IterableIterator> temp){
    iterator = move(temp);
}
bool IterableIteratorWrapper::operator!=(const IterableIteratorWrapper &other)const{
    return this->iterator->NotEquals(other.iterator);
}
std::pair<int, std::string> IterableIteratorWrapper::operator*()const{
    return iterator->Dereference();
};
IterableIteratorWrapper &IterableIteratorWrapper::operator++(){
    auto temp =unique_ptr<IterableIterator>(&iterator->Next());
    iterator.release();
    iterator = move(temp);
    return *this;
}

IterableIteratorWrapper Iterable::cbegin() const{
    return IterableIteratorWrapper(ConstBegin());
}
IterableIteratorWrapper Iterable::cend() const
{
    return IterableIteratorWrapper(ConstEnd());
}
IterableIteratorWrapper Iterable::begin() const
{
    return cbegin();
}
IterableIteratorWrapper Iterable::end() const
{
    return cend();
}

Zipper::Zipper(vector<int> a, vector<string> b):first(a),second(b){
};
unique_ptr<IterableIterator> Zipper::ConstBegin() const{
    return make_unique<ZipperIterator>(first.begin(),second.begin(),first.end(),second.end());
}
std::unique_ptr<IterableIterator> Zipper::ConstEnd() const{
    return make_unique<ZipperIterator>(first.end(),second.end(),first.end(),second.end());
}

ProductIterator::ProductIterator(std::vector<int>::const_iterator left,
std::vector<std::string>::const_iterator right,
        std::vector<int>::const_iterator left_end,
std::vector<std::string>::const_iterator right_end, std::vector<std::string>::const_iterator right_start)
:left(left),right(right),left_end(left_end),right_end(right_end),right_start(right_start){}


pair<int,string> ProductIterator::Dereference() const{
    if(right == right_end || left==left_end){
        pair<int,string> temp;
        if(right == right_end)
            temp.first=0;
        else
            temp.first=*left;
        if(left==left_end)
            temp.second="";
        else
            temp.second=*right;
        return temp;
    }
    return pair<int,string>{*left, *right};
};
IterableIterator& ProductIterator::Next()  {
    if(left==left_end )
        return *this;
    ++right;
    if(right == right_end )
    {
        ++left;
        if(left !=left_end) {
            right = right_start;
        }
    }
    return *this;

}
bool ProductIterator::NotEquals(const unique_ptr<IterableIterator> &other) const
{
    return this->Dereference() != other->Dereference();
}

Product::Product(vector<int> a, vector<string> b):first(a),second(b){}
unique_ptr<IterableIterator> Product::ConstBegin() const {
    return make_unique<ProductIterator>(first.begin(),second.begin(),first.end(),second.end(),second.begin());
}
std::unique_ptr<IterableIterator> Product::ConstEnd() const {
    return make_unique<ProductIterator>(first.end(),second.end(),first.end(),second.end(),second.begin());
}

EnumerateIterator::EnumerateIterator(vector<string>::const_iterator begin,vector<string>::const_iterator end):begin(begin),end(end),index(1){}
pair<int,string> EnumerateIterator::Dereference() const {
    if(begin == end)
        return pair<int,string>(0,"");
    return pair<int,string>(index,*begin);
};
IterableIterator& EnumerateIterator::Next()  {
    if(begin != end) {
        ++begin;
        ++index;
    }
    return *this;
}
bool EnumerateIterator::NotEquals(const unique_ptr<IterableIterator> &other) const
{
    return this->Dereference() != other->Dereference();
}

Enumerate::Enumerate( vector<string> b):first(b){}
unique_ptr<IterableIterator> Enumerate::ConstBegin() const {
    return make_unique<EnumerateIterator>(first.begin(),first.end());
}
std::unique_ptr<IterableIterator> Enumerate::ConstEnd() const {
    return make_unique<EnumerateIterator>(first.end(),first.end());
}