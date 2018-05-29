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
            root = elem;
            size=1;
            depth=1;
            Left = nullptr;
            Right = nullptr;
        }

        void Insert(const T &elem) {
            if (size == 0) {
                root = elem;
                depth=1;
                Left = nullptr;
                Right = nullptr;
            } else {
                size_t Newdepth =2;
                unique_ptr<Tree>* next;
                if (elem < root)
                    next = &Left;
                else
                    next = &Right;

                while (*next != nullptr) {
                    if (elem < next->operator->()->Value())
                        next = &next->operator->()->Left;
                    else
                        next = &next->operator->()->Right;
                    Newdepth++;
                }
                if( Newdepth> depth)
                    depth= Newdepth;
                *next = make_unique<Tree>(elem);
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
        T Value(){ return root;}

    private:
        T root;
        unique_ptr<Tree> Left;
        unique_ptr<Tree> Right;
        size_t size;
        size_t depth;
    };
}

#endif //JIMP_EXERCISES_TREE_H
