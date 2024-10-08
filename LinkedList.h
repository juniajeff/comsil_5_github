#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

// LinkedList Node
template <typename T>
class Node {
public:
    T data;
    Node* link;

    Node(T element) {
        data = element;
        link = NULL;  // Replaced nullptr with NULL
    }
};

// LinkedList Class
template <typename T>
class LinkedList {
protected:
    Node<T>* first;  // Pointer to the first node
    int current_size;  // Number of nodes

public:
    LinkedList() {
        first = NULL;  // Replaced nullptr with NULL
        current_size = 0;
    }

    int GetSize() {
        return current_size;
    }

    void Insert(T element);
    virtual bool Delete(T &element);
    void Print();
};

// Insert function for LinkedList
template <typename T>
void LinkedList<T>::Insert(T element) {
    Node<T>* newnode = new Node<T>(element);
    newnode->link = first;
    first = newnode;
    current_size++;
}

// Delete function for LinkedList (removes from the end)
template <typename T>
bool LinkedList<T>::Delete(T &element) {
    if (first == NULL)  // Replaced nullptr with NULL
        return false;

    Node<T>* current = first;
    Node<T>* previous = NULL;  // Replaced nullptr with NULL

    while (current->link != NULL) {  // Replaced nullptr with NULL
        previous = current;
        current = current->link;
    }

    if (previous)
        previous->link = NULL;
    else
        first = NULL;

    element = current->data;
    delete current;
    current_size--;

    return true;
}

// Print function for LinkedList (template implementation)
template <typename T>
void LinkedList<T>::Print() {
    Node<T>* temp = this->first;
    int index = 1;

    while (temp != NULL) {
        std::cout << "[" << index << "|" << temp->data << "]";
        if (temp->link != NULL)
            std::cout << " -> ";
        
        temp = temp->link;
        index++;
    }
    
    std::cout << std::endl;
}

#endif

