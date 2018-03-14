//
// Created by krzysztof on 14.03.2018.
//

#include "SmartTree.h"

using namespace datastructures;

std::unique_ptr<SmartTree> datastructures::CreateLeaf(int value)
{
    auto temp = make_unique<SmartTree>();
    temp->value=value;
    temp->left= nullptr;
    temp->right= nullptr;
    return temp;
}

std::unique_ptr<SmartTree> datastructures::InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree)
{
    tree ->left = move(left_subtree);
    return tree;
}

std::unique_ptr<SmartTree> datastructures::InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree)
{
    tree ->right = move(right_subtree);
    return tree;
}

void datastructures::PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out)
{
    if(unique_ptr != nullptr)
    {
        PrintTreeInOrder(unique_ptr->left,out);
        *out << unique_ptr->value << ", ";
        PrintTreeInOrder(unique_ptr->right,out);
    }
}

std::string datastructures::DumpTree(const std::unique_ptr<SmartTree> &tree)
{
    if(tree!= nullptr)
    {
        string temp;
        temp+= "[";
        temp+=to_string(tree->value);
        temp+=" ";
        temp+=DumpTree(tree->left);
        temp+=" ";
        temp+=DumpTree(tree->right);
        temp+="]";
        return temp;
    }
    return "[none]";
}

std::unique_ptr<SmartTree> datastructures::RestoreTree(const std::string &tree)
{
    if(tree != "[none]")
    {
        string temp;
        int a = 1;
        for(; a< tree.size()-1; a++)
        {
            if(tree[a] == ' ')
                break;
            temp+=tree[a];
        }
        auto pointer = CreateLeaf(stoi(temp, nullptr,10));
        int counterLeft =1;
        int counterRight = 0;
        temp ="[";
        a+=2;
        for(;a<tree.size()-1;a++)
        {
            temp+=tree[a];
            if(tree[a] == '[')
                counterLeft++;
            if(tree[a] == ']')
                counterRight++;
            if(counterLeft == counterRight)
                break;
        }
        pointer->left=RestoreTree(temp);
        temp ="[";
        a+=2;
        for(;a<tree.size()-1;a++)
        {
            temp+=tree[a];
            if(tree[a] == '[')
                counterLeft++;
            if(tree[a] == ']')
                counterRight++;
            if(counterLeft == counterRight)
                break;
        }
        pointer->right=RestoreTree(temp);
        return pointer;
    }
    return nullptr;
}