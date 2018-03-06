//
// Created by krzysztof on 06.03.2018.
//

#include "SimpleForwardList.h"



ForwardList *CreateNode(int value)
{
    ForwardList* temp = new ForwardList;
    temp->value = value;
    temp->next = nullptr;
    return temp;
}


void DestroyList(ForwardList *list)
{
    ForwardList * curr = list;
    ForwardList * temp;
    while(curr != nullptr)
    {
        temp = curr;
        curr = curr->next;
        delete[] temp;
    }
}


ForwardList *PushFront(ForwardList *list, int value)
{
    if(list == nullptr)
        return nullptr;
    ForwardList* temp = new ForwardList;
    temp ->value = value;
    temp -> next = list;
    return temp;
}
void Append(ForwardList *list, ForwardList *tail)
{
    if(list!= nullptr && tail != nullptr)
    {
        ForwardList *temp = list;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = tail;
    }
}