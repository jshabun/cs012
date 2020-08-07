#include <iostream>
#include <cstdlib>
#include <stdexcept>

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


    // This function does exactly the same thing the accessor (const) version of at does.
    int & IntVector::at(unsigned index) {
        if (index >= sz) {
            throw out_of_range("IntVector::at_range_check");
        } else {
            return data[index];
        }
    }


    /*
    This function inserts data at position index. To do this, all values currently at position index and greater are shifted to the 
    right by 1 (to the element right after its current position).

    Size will be increased by 1. However, If size will become larger than capacity, this function needs to first double the capacity. 
    In other words, if capacity and size are both 20 when this function is called, this function must first increase the capacity to 
    40 and then it will be able to increase the size to 21.

    Since other functions will also potentially need to expand (double) the capacity, call the private helper function named expand (see 
    above) to do this for you.

    This function should throw an out_of_range exception, passing it the string "IntVector::insert_range_check" if the index is too large. 
    See bottom of specifications for more details on how to throw an exception and how to test that it works properly.
    */
    void IntVector::insert(unsigned index, int value) {
        if (index > sz) {
            throw out_of_range("IntVector::insert_range_check");
        }

        if (sz == cap) {
            expand();
        }

        ++sz;

        for (unsigned int i  = sz - 1; i > index; --i) {
            data[i] = data[i - 1];
        }

        data[index] = value;
    }


    /*
    This function removes the value at position index and shifts all of the values at positions greater than index to the left by one (to 
    the element right before its current position).

    Size is decreased by 1.

    This function should throw an out_of_range exception, passing it the string "IntVector::erase_range_check" if the index is too large. 
    See bottom of specifications for more details on how to throw an exception and how to test that it works properly.
    */
    void IntVector::erase(unsigned index) {
        //int * tempVal = data;
        //--sz;

        if (index >= sz) {
            throw out_of_range("IntVector::erase_range_check");
        }

        --sz;

        for (unsigned int i = index; i < sz; ++i) {
            data[i] = data[i + 1];
        }
    }


    // This function will return the value stored in the first element.
    const int & IntVector::front() const {
        return data[0];
    }


    // This function does exactly the same thing the accessor (const) version of front does.
    int & IntVector::front() {
        return data[0];
    }


    // This function will return the value stored in the last element.
    const int & IntVector::back() const {
        return data[sz - 1];
    }
    

    // This function does exactly the same thing the accessor (const) version of back does.
    int & IntVector::back() {
        return data[sz - 1];
    }


    /*
    Assigns new content to the vector object, dropping all the elements contained in the vector before the call and replacing them by those 
    specified by the parameters. The new value of size will be n and all values stored in the vector will have the value of the 2nd parameter.

    If the new value of size will be larger than capacity, then this function must first expand capacity by either double (expand()) or by 
    increasing the capacity by a specific amount (expand(n - cap)), whichever results in the largest capacity.
    */
    void IntVector::assign(unsigned n, int value) {
        //clear();
        //sz = n;

        if (n > cap) {
           if (n < (2 * cap)) {
               expand ();
           } else {
               expand(n - cap);
           }
        }

        sz = n;
        for (unsigned int i = 0; i < sz; ++i) {
            data[i] = 0;
        }
    }


    /*
    This function inserts a value at the back end of the array.

    Size will be increased by 1. However, If size will become larger than capacity, this function needs to first increase the capacity. 
    In other words, if capacity and size are both 20 when this function is called, capacity must first be increased to 40 and then size 
    can be increased to 21.

    Since other functions will also potentially need to expand (double) the capacity, call the private helper function named expand (see 
    above) to do this for you.
    */
    void IntVector::push_back(int value) {
        if (sz >= cap) {
            expand();
        }

        ++sz;
        data[sz - 1] = value;
    }


    // This function just needs to decrease size by 1.
    // This function will never thrown an exception. Calling pop_back on an empty vector will cause undefined behavior.
    void IntVector::pop_back() {
        --sz;
    }


    // This function reduces the size of the vector to 0.
    void IntVector::clear() {
        sz = 0;
    }


    /*
    This function resizes the vector to contain size elements.
    
    If size is smaller than the current size(sz), this function just reduces the value of sz to size.

    If size is greater than the current size(sz), then the appropriate number of elements are inserted at the end of the vector, giving 
    all of the new elements the value passed in through the 2nd parameter (value).

    If the new value of size will be larger than capacity, then the capacity must first be expanded by either doubling (expand()) or by 
    increasing the capacity by a specific amount (expand(size - cap)), whichever results in the largest capacity. Then, this function can 
    then increase the size appropriately.
    */
    void IntVector::resize(unsigned size, int value) {
        int tempVal = 0;

        if (size > cap) {
            expand();
            
            if (size > cap) {
                expand(size - cap);
            }
        }

        if (size < sz) {
            sz = size;
        } else if (size > sz) {
            tempVal = sz;
            sz = size;

            for (unsigned int i = tempVal; i < sz; ++i) {
                data[i] = value;
            }
        }
    }


    /*
    This function requests that the capacity (the size of the dynamically allocated array) be set to n at minimum. This informs the vector 
    of a planned increase in size.

    This function should NOT ever reduce the size of the vector. If n is larger than the current capacity then the capacity should be 
    expanded to n.

    A call to this function never affects the elements contained in the vector, nor the vector's size.
    */
    void IntVector::reserve(unsigned n) {
        if (n > cap) {
           if ((2 * cap) > n) {
               expand ();
           } else {
               expand(n - cap);
           }
           cap = n;
        }

    }


    /*
    This function will double the capacity of the vector. This function should reallocate memory for the dynamically allocated array 
    and update the value of capacity. Make sure your expand() function properly handles the case when capacity is 0 before calling expand(). 
    This will be a special case within the expand() function.

    Make sure you don't create a memory leak here.
    */
    void IntVector::expand() {
        cap *= 2;
        int * tempVar = data;

        if (cap == 0) {
            ++cap;
            data = new int[cap];
        } else {
            data = new int [cap];
            for (unsigned int i = 0; i < sz; ++i) {
                data[i] = tempVar[i];
            }
        }
    }


    /*
    This function will expand the capacity of the vector by the amount passed in. This function should reallocate memory for the dynamically 
    allocated array and update the value of capacity. 

    Make sure you don't create a memory leak here.
    */
    void IntVector::expand(unsigned amount) {
        cap = cap + amount;
        int * tempVar = data;

        data = new int[cap];
        for (unsigned int i = 0; i < sz; ++i) {
            data[i] = tempVar[i];
        }
    }

