
// Program not finished yet
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
    IntNode* temp = rhs.head;

    while (temp != nullptr) {
        if (temp != rhs.tail) {
            out << temp->data << ' ';
        } else {
            out << temp->data;
        }
        temp = temp->next;
    }

    return out;
   
    // if (rhs.head != nullptr) {
    //     for (IntNode* temp = rhs.head; temp != nullptr; temp = temp->next) {
    //         if (temp != rhs.tail) {
    //             out << temp->data << ' ';
    //         }
    //     }
    //     out << rhs.tail->data;
    // }
    // return out;
}

// Program Constructors

// // the copy constructor. Make sure this performs deep copy.
IntList::IntList(const IntList &cpy) {
    head = nullptr;
    tail = nullptr;
    
    IntNode* temp = cpy.head;
    while (temp != nullptr) {
        push_back(temp->data);
        temp = temp->next;
    }
}


// the overloaded assingment operator. Make sure this performs deep copy.
IntList & IntList::operator=(const IntList &rhs) {
    //error: operator= did not work when assigning an empty IntList to a non-empty IntList.
    // create an if statement to check if list is empty and to return correct data to fix error.

    // if statement to check whether this (data member) is equal to &rhs or not
    if (this != &rhs) {
        // calls the clear function which deallocates all nodes
        clear();
        // sets temp data to the the data to the right hand side of the = operator. 
        IntNode* temp = rhs.head;
        // while loop that works while temp is not equal to nullptr
        while (temp != nullptr) {
            // uses the push_back function to move the data of temp to the back of the list (temp->data)
            push_back(temp->data);
            // increments temp to the next node
            temp = temp->next;
        }

        // returns the data member
        return *this;
    // returns as is if this is equal to &rhs
    } else {
        return *this;
    }
}


// Inserts a data value (within a new node) at the back end of the list.
void IntList::push_back(int value) {
    //
    IntNode* temp = new IntNode(value);

    //add and if statement here to check whether head = nullptr
    // if it does set head and tail = nullptr;
    if (head != nullptr) {
        tail->next = temp;
        tail = temp;
    } else {
        head = temp;
        tail = temp;
    }
}


// Removes (deallocates) all IntNodes in the IntList. Don't forget to set bothy head and tail to appropriate values for an empty list.
void IntList::clear() {
    //IntNode* temp = head;
    while (head != nullptr) {
            //pop_front();
            
            // try moving temp declaration outside the while loop
            IntNode* temp = head;
            head = head->next;
            delete temp;
        }

    head = nullptr;
    tail = nullptr;
}


// Sorts the integers in the list into ascending order. Do NOT move the nodes, just the integers.
void IntList::selection_sort() {
    // uses a nested for loop to sort the list by comparing and swapping
    // first for loop initializes temp to head and runs as long as temp/head is not equal to nullptr
    // then increments by one node each time
    // this loop will repeat for the amount of times needed to compare and sort
    for (IntNode* temp = head; temp != nullptr; temp = temp->next) {
        // creates an int variable myVal which is initialized to the first data value of temp node.
        // this variable will be used for comparison and swapping by storing data values.
        int myVal = temp->data;

        // the second(nested) for loop which will compare the current node to the next node. 
        for (IntNode* i = temp->next; i != nullptr; i = i->next) {
            // if statement checks whether the data at the currrent node of i is less than the data value that 
            // myVal is currently set to.
            if ((i->data) < myVal) {
                // if it is true, then myVal will be set to the lowest value (data value of current node i)
                myVal = i->data;
                // i will then be set to the temp data value that was in myVal before (essentially a swap)
                i->data = temp->data;
                // and finally the value of temp will be set to whatever myVal is holding. 
                // myVal is essentially a temp variable used to hold data values used in swapping to order the data values in ascending order
                temp->data = myVal;
            }
        }
    }
}


/*
Inserts a data value (within a new node) in an ordered list. Assumes the list is already sorted in ascending order
(i.i., Do not sort the list first, assume the list is already sorted.) This function loops through the list until if
finds the correct position for the new data value and then inserts the new IntNode in that location. This function may
NOT ever sort the list. 
*/
void IntList::insert_ordered(int value) {
   if (head == nullptr) {
       push_front(value);
   } else if (value <= head->data) {
       push_front(value);
   } else if (value >= tail->data) {
       push_back(value);
   } else {
       IntNode * node = head;
       IntNode * curr = head->next;
       IntNode * temp = new IntNode(value);

       while (curr != nullptr) {
           if (value < curr->data) {
               node->next = temp;
               temp->next = curr;
               return;
           }

           node = node->next;
           curr = curr->next;
       }
   }
   
    // IntNode* temp = new IntNode(value);

    // if (temp->data <= head->data) {
    //     push_front(value);
    //     return;
    // } else if (temp->data >= tail->data) {
    //     push_back(value);
    //     return;
    // } else if (head == nullptr) {
    //     push_front(value);
    //     return;
    // } else {
    //     IntNode* prev = head;
    //     IntNode* curr = head->next;
    //     for (IntNode* i = prev->next; i != nullptr; i = i->next) {
    //         if ((value <= i->data) && (value >= prev->data)) {
    //             prev = prev->next;
    //         }
    //     }

    //     prev->next = curr->next;
    //     curr->next = prev;

    //     IntNode* temp2 = head;
    //     while ((temp2->next->data <= temp->data) && (temp2->next != nullptr)) {
    //         if (temp2 == tail)
    //             temp2 = temp2->next;
    //     }

    //     temp->next = temp2 ->next;
    //     temp2->next = temp;
    // }
}


// Removes all duplicate data values (actually removes the nodes that contain the values) within the list. Always remove
// just the later value within the list when a duplicate is found. This function may NOT ever sort the list. 
void IntList::remove_duplicates() {
    // call temp and set to head to initialize list

    // a nested for loop is needed in this situation to scan for duplicates. 
    // the first for loop will check the current node/value while the second (nested)
    // for loop will check the next node/value and compare it to the value of the other
    // one and see if they are duplicates. if so, the duplicate node will be removed.
    IntNode* temp;

    //passes in first for loop. This allows the list to be incremented to be checked against itself. 
	for(IntNode* i = head; i != nullptr; i = i -> next) {
        // declaration here
        IntNode *temp2;
        // second for loop (nested) allows the list to be checked against itself using the first for-loop.
        // first, temp is initialized to equal i, for comparison, and temp2 is initialized to the next node of temp 
        // in order to compare the 2 values. 
        for(temp = i, temp2 = temp -> next; temp2 != nullptr; temp2 = temp -> next) {
            // if statement that checks whether the data vlaue of the node of temp2 is the same as the data value for i
            if(temp2 -> data == i -> data) {
                // if so, it checks whether the next nodes match the tail which means the end of the list. 
                // if so, the tail is set to the last node of temp, while temp2 is deleted since it's the duplicate. 
                temp -> next = temp2 -> next;
                if(temp2 == tail) {
                    tail = temp;
                }
                delete temp2;
            
            // if the data values of temp2 and i are not equal, it moves on to the next nodes to check those values.     
            } else {
                temp = temp -> next;
                
            }
        }
    }

        //create a while loop that runs as long as the next item is not nulltpr
        // in other words while temp->next is not nullptr
    //     while (temp->next != nullptr) {

    //     }
}