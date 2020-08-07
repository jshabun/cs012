#ifndef __INTVECTOR_H__
#define __INTVECTOR_H__

using namespace std;

class IntVector {
    private:
        unsigned sz;
        unsigned cap;
        int *data;

    public:
        // This function should set both the size and capacity of the IntVector to 0 and will not allocate any memory to store integers.
        // (Make sure you do not have a dangling pointer.)
        IntVector();
        
        // Sets both the size and capacity of the IntVector to the value of the parameter passed in and dynamically allocates an array of 
        // that size as well. This function should initialize all elements of the array to the value of the 2nd parameter.
        IntVector(unsigned size, int value = 0);
       
        // The destructor is used to clean up (delete) any remaining dynamically-allocated memory. For this class, that will be the array 
        // pointed to by the int pointer called data.
        ~IntVector();

        // This function returns the current size (not the capacity) of the IntVector object, which is the values stored in the sz data field.
        unsigned size() const;

        // This function returns the current capacity (not the size) of the IntVector object, which is the value stored in the cap data field.
        unsigned capacity() const;

        // Returns whether the IntVector is empty (the sz field is 0).
        bool empty() const;

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
        const int & at(unsigned index) const;

        // This function will return the value tored in the first element.
        const int & front() const;

        // This function will return the value stored in the last element.
        const int & back() const;
};

#endif