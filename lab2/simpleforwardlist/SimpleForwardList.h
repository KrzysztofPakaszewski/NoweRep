//
// Created by krzysztof on 06.03.2018.
//

#ifndef JIMP_EXERCISES_SIMPLEFORWARDLIST_H
#define JIMP_EXERCISES_SIMPLEFORWARDLIST_H


struct ForwardList
{
    ForwardList* next;
    int value;
};

ForwardList *CreateNode(int value);
void DestroyList(ForwardList *list);

ForwardList *PushFront(ForwardList *list, int value);
void Append(ForwardList *list, ForwardList *tail);


#endif //JIMP_EXERCISES_SIMPLEFORWARDLIST_H
