#include "UnsortedLList.h"

template <class Type>
UnsortedLList<Type>::UnsortedLList()
{
    length = 0;
    listData = currentPosition = NULL;
}

template <class Type>
UnsortedLList<Type>::~UnsortedLList()
{
    clear();
}

template <class Type>
unsigned long long UnsortedLList<Type>::getLength()
{
    return length;
}

template <class Type>
bool UnsortedLList<Type>::isFull()
{
	try
	{
		Node *node = new Node;

		delete node;
	}
	catch (bad_alloc exception)
	{
		return true;
	}

	return false;
}

template <class Type>
bool UnsortedLList<Type>::isEmpty()
{
    return length == 0 || listData == NULL;
}

template <class Type>
void UnsortedLList<Type>::add(Type *dataItem)
{
    if (isFull())
    {
        throw Exception("error: memory allocation failed.\n");
    }

    Node* node = new Node;
	node->dataItem = dataItem;
	node->nextNode = listData;
	listData = node;

	length++;
}

template <class Type>
void UnsortedLList<Type>::remove(Type dataItem)
{
    Node *previousNode = NULL, *currentNode = listData;

	while (currentNode != NULL)
    {
		if (*(currentNode->dataItem) == dataItem)
		{
			if (previousNode == NULL)
			{
				listData = currentNode->nextNode;
			}
			else
			{
				previousNode->nextNode = currentNode->nextNode;
			}

			delete currentNode;

			length--;

			break;
		}
		else
        {
			previousNode = currentNode;
			currentNode = currentNode->nextNode;
		}
	}
}

template <class Type>
void UnsortedLList<Type>::clear()
{
	Node* currentPosition = NULL;

	while (listData != NULL)
    {
        currentPosition = listData;
		listData = listData->nextNode;

		if (this->currentPosition == currentPosition)
        {
            this->currentPosition = this->currentPosition->nextNode;
		}

		delete currentPosition;

		length--;
	}
}

template <class Type>
void UnsortedLList<Type>::reset()
{
    currentPosition = NULL;
}

template <class Type>
Type * UnsortedLList<Type>::getItem(Type item){
	Node* currentNode = listData;

	while (currentNode != NULL)
    {
		if (item == *(currentNode->dataItem))
        {
            return currentNode->dataItem;
        }
		else
        {
			currentNode = currentNode->nextNode;
		}
	}

	return NULL;
}

template <class Type>
bool UnsortedLList<Type>::hasNext()
{
    if (currentPosition == NULL)
    {
        return listData != NULL;
    }

    return currentPosition->nextNode != NULL;
}

template <class Type>
Type * UnsortedLList<Type>::nextElement()
{
    if (currentPosition == NULL)
    {
        currentPosition = listData;
    }
    else
    {
        currentPosition = currentPosition->nextNode;
    }

	return currentPosition->dataItem;
}

template <class Type>
void UnsortedLList<Type>::print()
{
    Node* currentNode = listData;

    while (currentNode != NULL)
    {
        cout << (*(currentNode->dataItem)).getPhoneNumber() << ", ";

        currentNode = currentNode->nextNode;
    }
}
