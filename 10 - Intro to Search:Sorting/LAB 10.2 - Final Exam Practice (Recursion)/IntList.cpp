#include "IntList.h"

/*
You are tasked with implementing a recursive function void distanceFrom(int key) on the IntList class (provided). 
The function will first search through the list for the provided key, and then, recursively, change all previous values 
in the list to instead be their distance from the node containing the key value. Do not update the node containing the 
key value or any nodes after it. If the key does not exist in the list, each node should contain its distance from the 
end of the list.

Example 1
list: 5->7->3->2->1->4
list.distanceFrom(2);
list: 3->2->1->2->1->4

Example 2
list: 5->7->3->2->1->4
list.distanceFrom(6);
list: 6->5->4->3->2->1

The function must be recursive, you are not allowed to use any kind of loop. You also may NOT use global or static variables.
*/


 /* Update all nodes previous to the node containing the passed in integer to be the distance from that node 
      (1 for the node directly preceding it)
      No return value. Works by calling a recursive function (defined below).
   */
void IntList::distanceFrom(int key) {
   //updates head by calling search and modify recurisve function
   head->data = searchAndModify(head, key);
}


/* Recursive helper functions that will (1) find the key passed in and then 
      (2) recursively update the nodes preceding it to contain their distance from the node containing the key.
      If the key is not found, update with the distance from the end, with the last node having the value of 1.
   */
int IntList::searchAndModify(IntNode *curr, int key) {
   if(curr == nullptr) {
      return 0;
   } 
   
   if (curr->data == key) {
      return 0;
   }

   return curr->data = (1 + searchAndModify(curr->next, key));


   
   // if (key == curr->data) {
   //    return 0;
   // }

   // if (curr == nullptr) {
   //    return 0;
   // } 
   
   // if (curr != nullptr) {
   //    if (key != curr->data) {
   //       curr->data = searchAndModify(curr->next, key) + 1;
   //       return curr->data;
   //    }
   // }

   // if (key == head->data) {
   //    return curr->data;
   // }

   // return 0;
}
