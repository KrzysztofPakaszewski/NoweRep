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
    class Element {
    public:
        Element(const T &elem) {
            data = elem;
            left = nullptr;
            right = nullptr;
            parent = nullptr;
        }

        unique_ptr<Element> Left() { return left; }

        unique_ptr<Element> Right() { return right; }

        unique_ptr<Element> Parent() { return parent; }

        T Data() { return data; }

    private:
        T data;
        unique_ptr<Element> left;
        unique_ptr<Element> right;
        unique_ptr<Element> parent;
    };

    template<class T>
    class Tree {
    public:
        Tree():size(0){}

        Tree(const T &elem) {
            root = elem;
            size=1;
            depth=1;
        }

        void Insert(const T &elem) {
            if (size == 0) {
                root = elem;
                depth=1;
            } else {
                size_t Newdepth =1;
                unique_ptr<Tree>* next;
                if (elem < root)
                    next = &Left;
                else
                    next = &Right;

                while (*next != nullptr) {
                    if (elem < root)
                        next = &Left;
                    else
                        next = &Right;
                    Newdepth++;

                }
                if( Newdepth> depth)
                    depth= Newdepth;
                *next = make_unique<Tree>(elem);
            }
            size++;
        }

        bool Find(const T &elem){
            unique_ptr<Tree> *next;
            while( next->Value() != elem && next != nullptr) {
                if (elem < root)
                    next = *Left;
                else
                    next = *Right;

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
