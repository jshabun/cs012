#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
   
   string inputFile;
   string outputFile;
   vector<int> input;
   int currVal = 0;
   int sum = 0;
   double avg = 0.0;
   
   if (argc < 3) {
      cout << "usage " << argv[0] << " inputFile outputFile" << endl;
      exit(1);
   }

   // Assign to inputFile value of 2nd command line argument
   // Assign to outputFile value of 3rd command line argument
   inputFile = argv[1];
   outputFile = argv[2];
   
   // Create input stream and open input csv file.
   ifstream inFS;
   inFS.open(inputFile);

   // Verify file opened correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if (!inFS.is_open()) {
      cout << "Error opening" << inputFile << endl;
      exit(1);
   }

   // Read in integers from input file to vector.   
   while (inFS >> currVal) {
      input.push_back(currVal);
      inFS.ignore();
   }

   // Close input stream.
   inFS.close();

   // Get integer average of all values read in.
   for (unsigned int i = 0; i < input.size(); ++i) {
      sum += input.at(i);
   }

   avg = sum / input.size();

   // Convert each value within vector to be the difference between the original value and the average.
   

   // Create output stream and open/create output csv file.
   ofstream outFS;
   outFS.open(outputFile);

   // Verify file opened or was created correctly.


   // Output error message and return 1 if file stream did not open correctly.
   if (!outFS.is_open()) {
      cout << "Error opening" << endl;
      exit(1);
   }

   // Write converted values into ouptut csv file, each integer separated by a comma.
   for (unsigned int i = 0; i < input.size(); ++i) {
      outFS << input.at(i) - avg;
      if (i != input.size() - 1) {
         outFS << ",";
      }
   }


   // Close output stream.
   outFS.close();

   return 0;
}