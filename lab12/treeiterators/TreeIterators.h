//
// Created by krzysztof on 31.05.2018.
//

#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H

#include <memory>
#include "Tree.h"


using namespace std;

namespace tree {
    template<class T>
    class InOrderTreeIterator{
    public:
        InOrderTreeIterator(Tree<T>* node){
            Node = node;
            while( Node->LeftTree()!= nullptr){
                Node = Node->LeftTree();
            }
        }
        T operator*() const{
            return Node->Value();
        }
        InOrderTreeIterator&operator++(){
            if(Node->RightTree()!= nullptr)
            {
                Node = Node->RightTree();
                while(Node->LeftTree()!= nullptr)
                    Node = Node->LeftTree();
            }
            else{
                if(Node == Node->Parent()->LeftTree())
                    Node= Node->Parent();
                else {
                    while (Node == Node->Parent()->RightTree())
                        Node = Node->Parent();
                    Node= Node->Parent();
                }
            }
        }
        bool operator!=(const InOrderTreeIterator &other) const{
            return Node->Value()!=other.Node->Value();
        }

    private:
        Tree<T>* Node;

    };
    template<class T>
    class InOrderTreeView{
    public:
        InOrderTreeView(Tree<T>* root){
            Root = root;
        }
        Tree<T>* ConstBegin() const{
            Tree<T>* temp = Root;
            while( temp->LeftTree()!= nullptr){
                temp = temp->LeftTree();
            }
            return temp;
        }
        Tree<T>* ConstEnd() const{
            Tree<T>* temp = Root;
            while( temp->RightTree()!= nullptr){
                temp = temp->RightTree();
            }
            return temp;
        }
        InOrderTreeIterator<T> cbegin() const{
            return InOrderTreeIterator<T>(ConstBegin());
        }
        InOrderTreeIterator<T> cend() const{
            return InOrderTreeIterator<T>(ConstEnd());
        }
        InOrderTreeIterator<T> begin() const{
            return InOrderTreeIterator<T>(cbegin());
        }
        InOrderTreeIterator<T> end() const{
            return InOrderTreeIterator<T>(cend());
        }

    private:
        Tree<T>* Root;
    };
    template<class T>
    InOrderTreeView<T> InOrder(Tree<T> *tree){
        return InOrderTreeView<T>(tree);
    }
}

#endif //JIMP_EXERCISES_TREEITERATORS_H
