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
            return Node!=other.Node;
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
    template<class T>
    class PostOrderTreeIterator{
    public:
        PostOrderTreeIterator(Tree<T>* node){
            Node = node;
        }
        T operator*() const{
            return Node->Value();
        }
        PostOrderTreeIterator&operator++(){
            if(Node == Node->Parent()->LeftTree() && Node->Parent()->RightTree()!= nullptr)
            {
                Node=Node->Parent()->RightTree();
                while (Node->RightTree() != nullptr || Node->LeftTree() != nullptr) {
                    if (Node->LeftTree() != nullptr)
                        Node = Node->LeftTree();
                    else
                        Node = Node->RightTree();
                }

            }
            else
            {
                Node=Node->Parent();
            }
        }
        bool operator!=(const PostOrderTreeIterator &other) const{
            return Node!=other.Node;
        }

    private:
        Tree<T>* Node;
    };
    template<class T>
    class PostOrderTreeView{
    public:
        PostOrderTreeView(Tree<T>* root){
            Root = root;
        }
        Tree<T>* ConstBegin() const{
            Tree<T>* temp = Root;
            while (temp->RightTree() != nullptr || temp->LeftTree() != nullptr) {
                if (temp->LeftTree() != nullptr)
                    temp = temp->LeftTree();
                else
                    temp = temp->RightTree();
            }
            return temp;
        }
        Tree<T>* ConstEnd() const{
            Tree<T>* temp = Root;
            return temp;
        }
        PostOrderTreeIterator<T> cbegin() const{
            return PostOrderTreeIterator<T>(ConstBegin());
        }
        PostOrderTreeIterator<T> cend() const{
            return PostOrderTreeIterator<T>(ConstEnd());
        }
        PostOrderTreeIterator<T> begin() const{
            return PostOrderTreeIterator<T>(cbegin());
        }
        PostOrderTreeIterator<T> end() const{
            return PostOrderTreeIterator<T>(cend());
        }

    private:
        Tree<T>* Root;
    };
    template <class T>
    PostOrderTreeView<T> PostOrder(Tree<T>* tree){
        return PostOrderTreeView<T>(tree);
    }

    template<class T>
    class PreOrderTreeIterator{
    public:
        PreOrderTreeIterator(Tree<T>* node){
            Node = node;
        }
        T operator*() const{
            return Node->Value();
        }
        PreOrderTreeIterator&operator++(){
            if(Node->LeftTree()!= nullptr)
            {
                Node = Node->LeftTree();
            }
            else if( Node->RightTree()!=nullptr )
                Node = Node->RightTree();
            else{
                if(Node == Node->Parent()->LeftTree()) {
                    while(Node->RightTree()== nullptr)
                        Node=Node->Parent();
                    Node=Node->RightTree();
                }
                else {
                    while (Node == Node->Parent()->RightTree())
                        Node = Node->Parent();
                    Node=Node->Parent();
                    while(Node->RightTree()== nullptr)
                        Node=Node->Parent();
                    Node=Node->RightTree();
                }
            }
        }
        bool operator!=(const PreOrderTreeIterator &other) const{
            return Node!=other.Node;
        }

    private:
        Tree<T>* Node;

    };
    template<class T>
    class PreOrderTreeView{
    public:
        PreOrderTreeView(Tree<T>* root){
            Root = root;
        }
        Tree<T>* ConstBegin() const{
            return Root;
        }
        Tree<T>* ConstEnd() const{
            Tree<T>*temp = Root;
            while(temp->RightTree()!= nullptr || temp->LeftTree()!= nullptr){
                if(temp->RightTree()!= nullptr)
                    temp = temp->RightTree();
                else
                    temp=temp->LeftTree();
            }
            return temp;
        }
        PreOrderTreeIterator<T> cbegin() const{
            return PreOrderTreeIterator<T>(ConstBegin());
        }
        PreOrderTreeIterator<T> cend() const{
            return PreOrderTreeIterator<T>(ConstEnd());
        }
        PreOrderTreeIterator<T> begin() const{
            return PreOrderTreeIterator<T>(cbegin());
        }
        PreOrderTreeIterator<T> end() const{
            return PreOrderTreeIterator<T>(cend());
        }

    private:
        Tree<T>* Root;
    };
    template <class T>
    PreOrderTreeView<T> PreOrder(Tree<T>* tree){
        return PreOrderTreeView<T>(tree);
    }
}

#endif //JIMP_EXERCISES_TREEITERATORS_H
