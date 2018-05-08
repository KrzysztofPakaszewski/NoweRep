//
// Created by pakakrzy on 08.05.18.
//


#include "Display.h"

void Display::Draw() {
    for(int a=0;a<20;a++){
        for(int b=0;b<48;b++)
            cout<< Screen[a][b];
        cout << "\n";
    }
}
Display::Display(){
    for(int a=0;a<20;a++){
        vector<char> temp;
        for(int b=0;b<48;b++)
            temp.emplace_back(0);
        Screen.emplace_back(temp);
    }
}

void Display::DrawShape(const Displayable& Shape){
    pair<int,int> pos= Shape.Position();
    vector<vector<char>> temp= Shape.Shape();
    for(int a=0;a<temp.size();a++)
    {
        for(int b =0;b<temp[0].size();b++){
            Screen[pos.first+a][pos.second+b]=temp[a][b];
        }
    }
}
Square::Square(int a, int b) {
    if(a> 16 || b>44 || a<0 || b<0)
        throw invalid_argument("Wrong position");
    x=a;
    y=b;
}
vector<vector<char>> Square::Shape()const{
    return {{'X','X','X','X'},
            {'X',0,0,'X'},
            {'X',0,0,'X'},
            {'X','X','X','X'}};
}
pair<int,int> Square::Position()const{
    return pair<int,int>(x,y);
};