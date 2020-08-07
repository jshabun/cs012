#include <iostream>
using namespace std;

#include "IntList.h"

// Initializes an empty list
IntList::IntList() 
    : head(0), tail(0) {

}

// Deallocates all remaining dynamically allocated memory (all remaining IntNode)
IntList::~IntList() {
    while (head != nullptr) {
        //pop_front();
        
        IntNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Inserts a data value (within a new node) at the front end of the list
void IntList::push_front(int value) {
    IntNode* temp = new IntNode(value);

    temp->next = head;

    head = temp;

    if(tail == nullptr) {
        tail = head;
    }
}

// Removes the value (actually removes the node that contains the value) at the front end of the list. Does nothing if the list is already empty
void IntList::pop_front() {
    // if (head == nullptr && tail == nullptr) {
    //     return;
    // } else {
    //     IntNode* temp = head;
    //     head = head->next;
    //     delete temp;
    // }

    if(head != nullptr) {
        IntNode* temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr) {
            tail = head;
        }
    }
}

// Returns true if the list does not store any data values (does not have any nodes), otherwise returns false
bool IntList::empty() const {
    if (head == 0 && tail == 0) {
        return true;
    } else {
        return false;
    }
}


// Returns a reference to the first value in the list. Calling this on an empty list causes undefined behavior. 
const int & IntList::front() const {
    return head->data;
}


// Returns a reference to the last value in the list. Calling this on an empty list causes undefined behavior. 
const int & IntList::back() const {
    return tail->data;
}



ostream & operator<<(ostream & out, const IntList & rhs) {
    if (rhs.head != nullptr) {
        for (IntNode* cur = rhs.head; cur != nullptr; cur = cur->next) {
            if (cur != rhs.tail) {
                out << cur->data << ' ';
            }
        }
        out << rhs.tail->data;
    }
    return out;
}