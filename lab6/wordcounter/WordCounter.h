//
// Created by krzysztof on 10.04.2018.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

namespace datastructures {
    class Word{
    public:
        Word();
        Word(string);
        bool operator==(const Word&)const;
        operator string()const{ return word;}
        bool operator<(const Word&)const;
    private:
        string word;
    };
    class Counts{
    public:
        Counts();
        Counts(int);
        Counts &operator++();
        Counts &operator++(int);
        bool operator==(const Counts&)const;
        bool operator<(const Counts&)const;
        bool operator>(const Counts&)const;
        explicit operator size_t()const;
    private:
        size_t counter;
    };

    bool compare(pair<Word,Counts> First,pair<Word,Counts> Second);

    class WordCounter {
    public:
        WordCounter();
        WordCounter(initializer_list<Word>);
        WordCounter(vector<string>);
        WordCounter(WordCounter&);
        WordCounter(const WordCounter&);
        WordCounter&operator=(WordCounter&);
        WordCounter& operator=(const WordCounter&);
        ~WordCounter();
        size_t DistinctWords();
        size_t TotalWords();
        friend ostream& operator<<(ostream& output,const WordCounter& WordC);

        static WordCounter FromInputStream(istream&);

        set<Word> Words();
        size_t operator[](string);
    private:
        vector<pair<Word,Counts>> rep;
    };
    ostream& operator<<(ostream& output,const WordCounter& WordC);
}


#endif //JIMP_EXERCISES_WORDCOUNTER_H
