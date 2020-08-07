#include <iostream>

using namespace std;

// #include "IntList.h"
#include "SortedSet.h"

int main() {
    // Declaring test variables
    cout << endl << "declaring test varibles:" << endl 
         << "test1" << endl << "test2" << endl
         << "test3" << endl;
    SortedSet test1 = SortedSet();
    SortedSet test2 = SortedSet();
    SortedSet test3 = SortedSet();
    cout << endl;

    // push back numbers to list
    // test1 push_back
    cout << endl << "testing push_back to test1" << endl;
    test1.push_back(5);
    test1.push_back(2);
    test1.push_back(10);
    test1.push_back(1);
    test1.push_back(25);
    cout << test1 << endl;

    // testing add function
    //test2 push_back
    cout << endl << "testing add function to test2" << endl;
    test2.add(7);
    test2.add(22);
    test2.add(3);
    test2.add(53);
    test2.add(1);
    cout << test2 << endl;

    //testing push_front
    //test3 push_front
    cout << endl << "testing push_front to test3" << endl;
    test3.push_front(91);
    test3.push_front(8);
    test3.push_front(65);
    test3.push_front(2);
    test3.push_front(9);
    cout << test3 <<  endl;
    cout << endl;

    // testing in function
    cout << endl << "testing in function:" << endl;
    int testVar1 = 1;
    int testVar2 = 65;

    cout << "test1 with num " << testVar1 << ": " << test1.in(testVar1) << endl;
    cout << "test1 with num " << testVar2 << ": " << test1.in(testVar2) << endl;
    cout << endl;
    cout << "test2 with num " << testVar1 << ": " << test2.in(testVar1) << endl;
    cout << "test2 with num " << testVar2 << ": " << test2.in(testVar2) << endl;
    cout << endl;
    cout << "test3 with num " << testVar1 << ": " << test3.in(testVar1) << endl;
    cout << "test3 with num " << testVar2 << ": " << test3.in(testVar2) << endl;
    cout << endl << endl;

    // testing operators
    cout << "testing operators:" << endl;
    // testing |
    cout << "| test" << endl;
    cout << "test1 | test2: " << (test1 | test2) << endl;
    cout << "test1 | test3: " << (test1 | test3) << endl;
    cout << "test2 | test3: " << (test2 | test3) << endl;
    cout << endl;

    //testing &
    cout << "& test" << endl;
    cout << "test1 & test2: " << (test1 & test2) << endl;
    cout << "test1 & test3: " << (test1 & test3) << endl;
    cout << "test2 & test3: " << (test2 & test3) << endl;

}