// Implement the following global function using a recursive algorithm to find and 
// return the location of the smallest value in an array of integers.

// - You may not use a loop of any kind.
// - You may not use global or static variables.

#include "minFunc.h"

const int * min(const int arr[], int arrSize) {
    if (arrSize == 0) {
        return 0;
    }

    if (arrSize == 1) {
        return arr;
    }

    const int * temp = min(arr, arrSize - 1);

    if (*temp < arr[arrSize - 1]) {
        return temp;
    } else {
        return &arr[arrSize - 1];
    }
}