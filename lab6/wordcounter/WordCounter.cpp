//
// Created by krzysztof on 10.04.2018.
//

#include "WordCounter.h"

using namespace datastructures;

Word::Word(){}
Word::Word(string a):word(a){};
bool Word::operator==(const Word& other)const{
    return (string)(*this)==(string)(other);
}
bool Word::operator<(const Word& other)const{
    return (string)(*this) < (string)(other);
}




Counts::Counts():counter(0){}
Counts::Counts(int a):counter(a){}
Counts& Counts::operator++(){
    ++counter;
}
Counts &Counts::operator++(int){
    counter++;
}
Counts::operator size_t()const{
    return counter;
}
bool Counts::operator==(const Counts& other)const{
    if(this->counter == other.counter)
        return true;
    return false;
}
bool Counts::operator<(const Counts& other)const{
    return (size_t)(*this) < (size_t)(other);
}
bool Counts::operator>(const Counts&other)const{
    return (size_t)(*this) > (size_t)(other);
}



WordCounter::WordCounter(WordCounter& other){
    rep = other.rep;
    other.rep.clear();
}
WordCounter::WordCounter(const WordCounter& other){
    rep = other.rep;
}
WordCounter&WordCounter::operator=(WordCounter& other){
    rep = other.rep;
    other.rep.clear();
}
WordCounter& WordCounter::operator=(const WordCounter& other){
    rep = other.rep;
}
WordCounter::WordCounter(){}
WordCounter::~WordCounter(){

}
WordCounter::WordCounter(initializer_list<Word> list){
    for(auto pointer = list.begin();pointer!= list.end();pointer++){
        bool flag = true;
        for(int a =0; a< rep.size();a++)
        {
            if(rep[a].first == *pointer){
                rep[a].second++;
                flag = false;
                break;
            }
        }
        if(flag)
        {
            rep.emplace_back(pair<Word,Counts>{*pointer,Counts(1)});
        }
    }
}
WordCounter::WordCounter(vector<string> list){
    for(auto pointer = list.begin();pointer!= list.end();pointer++){
        bool flag = true;
        for(int a =0; a< rep.size();a++)
        {
            if(rep[a].first == Word(*pointer)){
                rep[a].second++;
                flag = false;
                break;
            }
        }
        if(flag)
        {
            rep.emplace_back(pair<Word,Counts>{*pointer,Counts(1)});
        }
    }
}
size_t WordCounter::DistinctWords(){
    return rep.size();
}
size_t WordCounter::TotalWords(){
    size_t sum=0;
    for(int a =0; a< rep.size();a++){
        sum+= (size_t)(rep[a].second);
    }
    return sum;
}
size_t WordCounter::operator[](string word){
    for(int a =0; a< rep.size();a++){
        if(rep[a].first==Word(word))
        {
            return (size_t)(rep[a].second);
        }
    }
    return 0;
}

set<Word> WordCounter::Words(){
    set<Word> temp;
    for(int a =0;a<rep.size();a++)
    {
        temp.emplace(rep[a].first);
    }
    return temp;
}
namespace datastructures {
    bool compare(pair<Word,Counts> First,pair<Word,Counts> Second) {
        return First.second > Second.second;
    }
    ostream &operator<<(ostream &output, const WordCounter &WordC) {
        vector<pair<Word, Counts>> temp = WordC.rep;
        sort(temp.begin(), temp.end(), compare);
        string sep1 = " - ";
        string sep2 = ", ";
        for (auto pointer = temp.begin(); pointer != temp.end(); pointer++) {
            output << string((*pointer).first);
            output << sep1;
            stringstream os;
            os << (size_t) (*pointer).second;
            output << os.str();
            output << sep2;
        }
        return output;
    }
}
bool isWhiteSpace(char a){
    return (a==' ' || a=='\t' || a =='\n');
}
WordCounter WordCounter::FromInputStream(istream& input){
    string in;
    stringstream buffer;
    buffer << input.rdbuf();
    in= buffer.str();
    vector<string> words;
    string temp;
    for(int a = 0; a< in.size();a++)
    {
        if(isWhiteSpace(in[a])){
            if( temp != "") {
                words.push_back(temp);
                temp = "";
            }
            continue;
        }
        temp+= in[a];
    }
    if(temp != "")
        words.push_back(temp);
    return WordCounter(words);
}