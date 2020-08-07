#include <iostream>
#include <cstdlib>

#include "IntVector.h"

using namespace std;

    // This function should set both the size and capacity of the IntVector to 0 and will not allocate any memory to store integers.
    // (Make sure you do not have a dangling pointer.)
    IntVector::IntVector() {
        sz = 0;
        cap = 0;
        data = 0;
    }
    
    // Sets both the size and capacity of the IntVector to the value of the parameter passed in and dynamically allocates an array of 
    // that size as well. This function should initialize all elements of the array to the value of the 2nd parameter.
    IntVector::IntVector(unsigned size, int value) {
        sz = size;
        cap = size;
        data = new int[size];


        for (unsigned int i = 0; i < size; ++i) {
            data[i] = value;
        }
    }
    
    // The destructor is used to clean up (delete) any remaining dynamically-allocated memory. For this class, that will be the array 
    // pointed to by the int pointer called data.
    IntVector::~IntVector() {
        delete[] data;
    }

    // This function returns the current size (not the capacity) of the IntVector object, which is the values stored in the sz data field.
    unsigned IntVector::size() const {
        return sz;
    }

    // This function returns the current capacity (not the size) of the IntVector object, which is the value stored in the cap data field.
    unsigned IntVector::capacity() const {
        return cap;
    }

    // Returns whether the IntVector is empty (the sz field is 0).
    bool IntVector::empty() const {
        if (sz == 0) {
            return true;
        } else {
            return false;
        }
    }

    /* 
    This function will return the value stored in the element at the passed in index position. Your function should throw an outofrange 
    exception if an invalid index is passed in. An invalid index is an index greater than or equal to the size.
    Throwing an exception: You will need to include the standard library stdexcept. Then, when the index is out of range, execute the 
    following statement:
        
        throw out_of_range("IntVector::at_range_check");
    
    To test if this worked, declare an IntVector of size 10 and then call the at function passing it an index argument of 10 or larger. 
    You should see the following output:
        
        terminate called after throwing an instance of 'std::out_of_range'
            what():  IntVector::at_range_check
        Aborted
    */
    const int & IntVector::at(unsigned index) const {
        if (index >= sz) {
            throw out_of_range("IntVector::at_range_check");
        } else {
            return data[index];
        }
    }

    // This function will return the value stored in the first element.
    const int & IntVector::front() const {
        return data[0];
    }

    // This function will return the value stored in the last element.
    const int & IntVector::back() const {
        return data[sz - 1];
    }