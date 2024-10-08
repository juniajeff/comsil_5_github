#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

// Stack class inherits from LinkedList
template <typename T>
class Stack : public LinkedList<T> {
public:
    // Override the Delete function to follow stack behavior (LIFO)
    bool Delete(T &element) {
        if (this->first == NULL)  // Replaced nullptr with NULL
            return false;
        
        // Get the first element and delete it (LIFO)
        Node<T>* temp = this->first;
        element = temp->data;
        this->first = this->first->link;
        delete temp;
        
        this->current_size--;
        return true;
    }
};

#endif

