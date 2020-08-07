#include "IntList.h"

// You are tasked with writing a function void removeOdds(). This function will remove all nodes that 
// contain an odd value (any value not evenly divisible by 2). Make sure that you aren't leaking memory 
// or leaving any dangling pointers!

/*
Example 1
list : 71 2 4 3 0 8 -3
list.removeOdds();
list : 2 4 0 8

Example 2
list : 581 -3 43 11 4 59 1 -81 -3
list.removeOdds()
list : 4
*/

void IntList::removeOdds() {
    while (head && head->data % 2 != 0) {
       IntNode * temp = head;
       head = head->next;
       delete temp;
   }

   IntNode * curr = head;

   while (curr != nullptr && curr->next != nullptr) {
       if (curr->next->data % 2 != 0) {
           IntNode * x = curr->next;
           curr->next = curr->next->next;
           delete x;

       } else {
           curr = curr->next;
       }
   }


//    while (head != nullptr) {
//        if (head->data != 0) {
//             IntNode * temp = head;
//             head = head->next;
//             delete temp;
//        }
//    }
}

