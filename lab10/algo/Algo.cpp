//
// Created by pakakrzy on 15.05.18.
//

#include "Algo.h"

using namespace algo;
std::set<std::string> Keys(const std::map<std::string, int> &m){
    set<string> keys;
    transform(m.begin(),m.end(),back_inserter(keys),[](pair<string,int> t){return t.first;});
    return keys;
}

std::vector<int> Values(const std::map<std::string, int> &m){
    vector<int> keys;
    transform(m.begin(),m.end(),back_inserter(keys),[](pair<string,int> t){return t.second;});
    return keys;
}

std::map<std::string, int> DivisableBy(const std::map<std::string, int> &m,int divisor){

};

void SortInPlace(std::vector<int> *v){
    sort(v->begin(),v->end());
}

std::vector<int> Sort(const std::vector<int> &v){
    vector<int> temp = v;
    sort(temp.begin(),temp.end());
    return temp;
}

void SortByFirstInPlace(std::vector<std::pair<int,int>> *v){
    sort(v->begin(),v->end(),[](pair<int,int> t,pair <int,int> a){ return t.first<a.first;});
}

void SortBySecondInPlace(std::vector<std::pair<int,int>> *v){
    sort(v->begin(),v->end(),[](pair<int,int> t,pair <int,int> a){ return t.second<a.second;});
}

void SortByThirdInPlace(std::vector<std::tuple<int,int,int>> *v){
    sort(v->begin(),v->end(),[](tuple<int,int,int> t,tuple <int,int,int> a){ return get<2>(t) < get<2>(a);});
}

std::vector<std::string> MapToString(const std::vector<double> &v){
    vector<string> temp;
    transform(v.begin(),v.end(),back_inserter(temp),[](double t){ return to_string(t);});
    return temp;
}

std::string Join(const std::string &joiner, const std::vector<double> &v){

}

int Sum(const std::vector<int> &v){
    int temp=0;
    partial_sum(v.begin(),v.end(),[temp](int a){return temp+a;});
    return temp;
}

int Product(const std::vector<int> &v){

    int temp=1;
    partial_sum(v.begin(),v.end(),[temp](int a){return temp*a;});
    return temp;
}
bool Contains(const std::vector<int> &v, int element){
    if( count(v.begin(),v.end(),[element](int temp){ return temp==element;})==0)
        return false;
    return true;
}
bool ContainsKey(const std::map<std::string, int> &v, const std::string &key){
    if( count(v.begin(),v.end(),[key](pair<string,int> temp){ return temp.first==key;})==0)
        return false;
    return true;
}
bool ContainsValue(const std::map<std::string, int> &v, int value){
    if( count(v.begin(),v.end(),[value](pair<string,int> temp){ return temp.second==value;})==0)
        return false;
    return true;
}
std::vector<std::string> RemoveDuplicates(const std::vector<std::string> &v){

}
void RemoveDuplicatesInPlace(std::vector<std::string> *v){

}
void InitializeWith(int initial_value, std::vector<int> *v){

}
std::vector<int> InitializedVectorOfLength(int length, int initial_value){

}
void CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out){
    copy_n(v.begin(),n_elements,back_inserter(*out));
}
int HowManyShortStrings(const std::vector<std::string> &v, int inclusive_short_length){

}