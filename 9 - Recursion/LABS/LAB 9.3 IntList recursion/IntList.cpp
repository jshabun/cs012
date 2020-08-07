#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(0) {}

//This week you convert the operator<< function to use a recursive solution and add a recursive exists 
//function that determines whether a particular integer value exists within the IntList.


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}


 /* Outputs to a single line all of the int values stored in the list, each separated by a space. 
      This function does NOT output a newline or space at the end.
   */
   ostream &operator<<(ostream &out, const IntList &rhs) {
      // if (rhs.head != nullptr) {
      //    out << rhs.head;
      // } else {
      //    out << rhs.head << " ";
      //    out << rhs.head->next;
      // }

      if (rhs.head != nullptr) {
         operator<<(out, rhs.head);
         return out;
      }

      return out;
   }

   /* Returns true if the integer passed in is contained within the IntList.
      Otherwise returns false.
   */
   bool IntList::exists(int val) const {
      if (head == nullptr) {
         return false;
      }

      if (head->data == val) {
         return true;
      }

      return exists(head->next, val);
   }

    /* Helper function that returns true if the integer passed in is contained within
      the IntNodes starting from the IntNode whose address is passed in.
      Otherwise returns false.
   */
   bool IntList::exists(IntNode * curr, int val) const {
      if (curr == nullptr) {
         return false;
      }

      if (curr->data == val) {
         return true;
      }

      return exists(curr->next, val);
      
      // if (val == (curr->data)) {
      //    return true;
      // }

      // if ((curr->next) != nullptr) {
      //    exists(curr->next, val);
      // }

      // return 0;
   }


   /* Helper function that passes in the address of a IntNode within an IntList and outputs
   all of integers within the IntList starting from this IntNode.
*/
ostream & operator<<(ostream &out, IntNode * curr) {
   if (curr != nullptr) {
     
     if (curr->next != nullptr) {
        out << curr->data << " ";
     } else {
        out << curr->data;
     }

     out << curr->next;
   }

   return out;
}
