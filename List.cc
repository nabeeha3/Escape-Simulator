#include <iostream>
using namespace std;

#include "List.h"

template<class T>
List<T>::List() : head(nullptr) { }

template<class T>
List<T>::~List()
{
    Node* currNode = head;
    Node* nextNode;

    while (currNode != nullptr) 
    {
        nextNode = currNode->next;
        delete currNode->data;
        delete currNode;
        currNode = nextNode;
    }
}

template<class T>
List<T>& List<T>::operator+=(T temp)
{
    Node* newNode = new Node;
    newNode->data = temp;
    newNode->next = nullptr;

    if (head == nullptr) 
    {
        head = newNode;
    }
    else 
    {
        Node* curNode = head;
        
        while (curNode->next != nullptr) 
        {
        curNode = curNode->next;
        }
        curNode->next = newNode;
    }

    return *this;   
}

template<class T>
void List<T>::convertToArray(T* arr, int& size)
{
    size = 0;
    Node* curNode = head;

    while (curNode != nullptr) 
    {
        arr[size] = *(curNode->data);
        curNode = curNode->next;
        size++;
    }
}


