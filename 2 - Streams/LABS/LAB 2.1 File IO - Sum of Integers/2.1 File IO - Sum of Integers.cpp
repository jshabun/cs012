// 2.10 LAB 2.1: File I/O - Sum of Integers

#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

// Place fileSum prototype (declaration) here
int fileSum (string filename);

int main() {

   string filename;
   int sum = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   
   sum = fileSum(filename);

   cout << "Sum: " << sum << endl;
   
   return 0;
}

// Place fileSum implementation here
int fileSum (string filename) {
    ifstream fileSum;
    int sum = 0;
    int temp;

    fileSum.open(filename);

    if (!fileSum.is_open()) {
        cout << "Error opening " << filename << endl;
        exit(1);
    }

    while (fileSum >> temp) {
        //fileSum >> temp;
        sum += temp;
    }

    fileSum.close();

    return sum;
}