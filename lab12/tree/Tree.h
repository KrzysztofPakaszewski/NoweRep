//
// Created by pakakrzy on 29.05.18.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <vector>
#include <memory>
using namespace std;
namespace tree {
    template<class T>
    class Tree {
    public:
        Tree():size(0){}

        Tree(const T &elem) {
            node = elem;
            size=1;
            depth=1;
            Left= nullptr;
            Right= nullptr;
            parent= nullptr;
            root = this;
            level=1;
        }

        void Insert(const T &elem) {
            if (size == 0) {
                node = elem;
                depth=1;
                Left= nullptr;
                Right= nullptr;
                root = this;
                parent= nullptr;
                level=1;
            } else {
                size_t Newdepth =2;
                unique_ptr<Tree<T>>* next;
                if (elem < node)
                    next = &Left;
                else
                    next = &Right;
                unique_ptr<Tree<T>>* temp = next;
                while (*next != nullptr) {
                    if (elem < temp->operator->()->Value()) {
                        temp = next;
                        next = &next->operator->()->Left;
                    }
                    else {
                        temp = next;
                        next = &next->operator->()->Right;
                    }
                    Newdepth++;
                }
                if( Newdepth > depth)
                    depth= Newdepth;
                *next = make_unique<Tree<T>>(elem);
                next->operator->()->parent= temp;
                next->operator->()->root= root;
                next->operator->()->level = Newdepth;
            }
            size++;
        }

        bool Find(const T &elem){
            unique_ptr<Tree> *next= this;
            while( *next != nullptr && next->operator->()->Value() != elem) {
                if (elem < next->operator->()->Value())
                    next = &next->operator->()->Left;
                else
                    next = &next->operator->()->Right;

            }
            if(next == nullptr)
                return false;
            return true;

        }

        size_t Depth(){ return depth;}

        size_t Size(){ return size;}
        T Value(){ return node;}
        Tree<T>* LeftTree(){
            return &*Left;
        }
        Tree<T>* RightTree(){
            return &*Right;
        }

        Tree<T>* Parent(){
            if(level==1)
                return nullptr;
            if(level==2)
                return root;
            return &**parent;
        }
        Tree<T>* Root(){
            return root;
        }



    private:
        T node;
        Tree<T>* root;
        unique_ptr<Tree<T>>* parent;
        unique_ptr<Tree<T>> Left;
        unique_ptr<Tree<T>> Right;
        size_t size;
        size_t depth;
        size_t level;
    };
}

#endif //JIMP_EXERCISES_TREE_H
