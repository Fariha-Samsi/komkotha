#ifndef UNSORTEDLLIST_H
#define UNSORTEDLLIST_H

#include <iostream>

#include "Exception.h"

using namespace std;

template <class Type>
class UnsortedLList
{
    public:
        UnsortedLList();
        ~UnsortedLList();

        bool isFull();
        bool isEmpty();
        unsigned long long getLength();
        void reset();
        void add(Type *);
        void remove(Type);
        void clear();
        void print();
        bool hasNext();
        Type * getItem(Type);
        Type * nextElement();

    private:
        unsigned long long length;

        struct Node
        {
            Type *dataItem;

            struct Node *previousNode, *nextNode;
        };

        struct Node *currentPosition, *listData;
};

#endif // UNSORTEDLLIST_H
