#include "SortedLList.h"

template <class Type>
SortedLList<Type>::SortedLList()
{
    length = 0;
    listData = currentPosition = NULL;
}

template <class Type>
SortedLList<Type>::~SortedLList()
{
    clear();
}

template <class Type>
unsigned long long SortedLList<Type>::getLength()
{
    return length;
}

template <class Type>
bool SortedLList<Type>::isFull()
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
bool SortedLList<Type>::isEmpty()
{
    return length == 0 || listData == NULL;
}

template <class Type>
void SortedLList<Type>::add(Type *dataItem)
{
    if (isFull())
    {
        throw Exception("error: memory allocation failed.\n");
    }

    bool positionFound = false;

    Node *node = new Node, *previousNode = NULL, *currentNode = listData;
	node->dataItem = dataItem;
	node->nextNode = listData;
	listData = node;

    while (!positionFound && currentNode != NULL)
    {
		if (currentNode->dataItem < dataItem)
		{
			previousNode = currentNode;
			currentNode = currentNode->nextNode;
		}
		else
		{
			positionFound = true;
			node->nextNode = currentNode;

			if (previousNode == NULL)
            {
				listData = node;
			}
			else
			{
				previousNode->nextNode = node;
			}
		}
	}

    if (!positionFound)
	{
		positionFound = true;

		node->nextNode = currentNode;

		if (previousNode == NULL)
        {
			listData = node;
		}
		else
		{
			previousNode->nextNode = node;
		}
	}

	length++;
}

template <class Type>
void SortedLList<Type>::remove(Type dataItem)
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

			break;
		}
		else
        {
			previousNode = currentNode;
			currentNode = currentNode->nextNode;
		}
	}

	length--;
}

template <class Type>
void SortedLList<Type>::clear()
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
void SortedLList<Type>::reset()
{
    currentPosition = NULL;
}

template <class Type>
Type * SortedLList<Type>::getItem(Type item){
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
bool SortedLList<Type>::hasNext()
{
    if (currentPosition == NULL)
    {
        return listData != NULL;
    }

    return currentPosition->nextNode != NULL;
}

template <class Type>
Type * SortedLList<Type>::nextElement()
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
void SortedLList<Type>::print()
{
    Node* currentNode = listData;

    while (currentNode != NULL)
    {
        cout << (*(currentNode->dataItem)).getPhoneNumber() << ", ";

        currentNode = currentNode->nextNode;
    }
}
