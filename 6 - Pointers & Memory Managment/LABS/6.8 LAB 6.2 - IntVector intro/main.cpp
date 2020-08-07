#include <iostream>
#include <cstdlib>

#include "IntVector.h"

using namespace std;

int main() {
    IntVector test; // tests first constructor
    IntVector test2 (10, 6); // test second contructor by inputting parameters for size and value

    // testing the size() function for test and test2
    cout << "test size: " << test.size();
    cout << endl;
    cout << "test2 size: " << test2.size();
    cout << endl;

    // testing the capacity() function for test and test2
    cout << endl;
    cout << "test capacity: " << test.capacity();
    cout << endl;
    cout << "test2 capacity: " << test2.capacity();
    cout << endl;

    // testing empty() function for test and test2
    // 1 = true
    // 0 = false
    cout << endl;
    cout << "test empty: " << test.empty();
    cout << endl;
    cout << "test2 empty: " << test2.empty();
    cout << endl;

    // testing front()  function for test and test2
    cout << endl;
    cout << "test front: " << test.front();
    cout << endl;
    cout << "test2 front: " << test2.front();
    cout << endl;

    // testing back()
    cout << endl;
    cout << "test back: " << test.back();
    cout << endl;
    cout << "test2 back: " << test2.back();
    cout << endl;

    // testing at() function for test and test2
    cout <<  endl;
    cout << "test2 at: " << test2.at(5);
    cout <<  endl;
    cout << "test at: " << test.at(5);
    cout << endl;





    return 0;
}