//
// Created by krzysztof on 31.05.2018.
//
#include "TreeIterators.h"
#include <string>
#include <iostream>

int main(){
    tree::Tree<string> test_tree("Opochtli");
    test_tree.Insert("Quetzalcoatl");
    test_tree.Insert("Tezcatlipoca");
    test_tree.Insert("Tlaloc");
    test_tree.Insert("Xantico");
    test_tree.Insert("Meztli");
    test_tree.Insert("Centeotl");
    test_tree.Insert("Xolotl");
    test_tree.Insert("Citlalicue");
    test_tree.Insert("Toci");
    test_tree.Insert("Xiuhtecuhtli");
    for( const string &a : tree::PreOrder(&test_tree))
        cout<< a << endl;
    if("Xanticp" > "Toci")
        cout << "true";
    else
        cout << "false";
    return 0;
}