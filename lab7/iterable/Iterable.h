//
// Created by krzysztof on 23.04.2018.
//

#ifndef JIMP_EXERCISES_ITERABLE_H
#define JIMP_EXERCISES_ITERABLE_H

#include <string>
#include <vector>
#include <memory>
using namespace std;

namespace utility {
    class IterableIterator {
    public:
        virtual pair<int,string> Dereference() const=0;
        virtual IterableIterator& Next()=0;
        virtual bool NotEquals(const unique_ptr<IterableIterator> &other) const =0;
        ~IterableIterator()= default;
    };

    class ZipperIterator : public IterableIterator{
    public:
        explicit ZipperIterator(std::vector<int>::const_iterator left,
                                std::vector<std::string>::const_iterator right,
                                std::vector<int>::const_iterator left_end,
                                std::vector<std::string>::const_iterator right_end);
        pair<int,string> Dereference() const override;
        IterableIterator& Next() override ;
        bool NotEquals(const unique_ptr<IterableIterator> &other) const override ;
    private:
        vector<int>::const_iterator left;
        vector<string>::const_iterator right;
        vector<int>::const_iterator left_end;
        vector<string>::const_iterator right_end;
    };

    class IterableIteratorWrapper{
    public:
        IterableIteratorWrapper(unique_ptr<IterableIterator> iterator);
        bool operator!=(const IterableIteratorWrapper &other)const ;
        std::pair<int, std::string> operator*()const;
        IterableIteratorWrapper &operator++();

    private:
        unique_ptr<IterableIterator> iterator;
    };


    class Iterable{
    public:
        virtual unique_ptr<IterableIterator> ConstBegin() const=0;
        virtual std::unique_ptr<IterableIterator> ConstEnd() const=0;
        IterableIteratorWrapper cbegin() const;
        IterableIteratorWrapper cend() const;
        IterableIteratorWrapper begin() const;
        IterableIteratorWrapper end() const;
    };

    class Zipper : public  Iterable{
    public:
        Zipper(vector<int>, vector<string>);
        unique_ptr<IterableIterator> ConstBegin() const override;
        std::unique_ptr<IterableIterator> ConstEnd() const override;
    private:
        vector<int> first;
        vector<string> second;

    };
    class ProductIterator : public IterableIterator{
    public:
        explicit ProductIterator(std::vector<int>::const_iterator left,
        std::vector<std::string>::const_iterator right,
                std::vector<int>::const_iterator left_end,
        std::vector<std::string>::const_iterator right_end,
                                 std::vector<std::string>::const_iterator right_start);
        pair<int,string> Dereference() const override;
        IterableIterator& Next() override ;
        bool NotEquals(const unique_ptr<IterableIterator> &other) const override ;

    private:
        vector<int>::const_iterator left;
        vector<string>::const_iterator right;
        vector<int>::const_iterator left_end;
        vector<string>::const_iterator right_end;
        vector<std::string>::const_iterator right_start;
    };

    class Product: public Iterable{
    public:
        Product(vector<int>, vector<string>);
        unique_ptr<IterableIterator> ConstBegin() const override;
        std::unique_ptr<IterableIterator> ConstEnd() const override;

    private:
        vector<int> first;
        vector<string> second;
    };

    class EnumerateIterator:public IterableIterator{
    public:
        explicit EnumerateIterator(vector<string>::const_iterator begin,vector<string>::const_iterator end);
        pair<int,string> Dereference() const override;
        IterableIterator& Next() override ;
        bool NotEquals(const unique_ptr<IterableIterator> &other) const override ;

    private:
        vector<string>::const_iterator begin;
        size_t index;
        vector<string>::const_iterator end;
    };
    class Enumerate :public Iterable{
    public:
        Enumerate(vector<string>);
        unique_ptr<IterableIterator> ConstBegin() const override;
        std::unique_ptr<IterableIterator> ConstEnd() const override;

    private:
        vector<string> first;
    };
}


#endif //JIMP_EXERCISES_ITERABLE_H
