#include <iostream>
#include <string>

using namespace std;

class Date {
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   // creates the date January 1st, 2000.
   Date();


   /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
   Date(unsigned m, unsigned d, unsigned y);


   /* parameterized constructor: month name, day, year
      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).
 
       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */
   Date(const string &mn, unsigned d, unsigned y);


   /* Outputs to the console (cout) a Date exactly in the format "3/15/2012". 
      Does not output a newline at the end.
   */
   void printNumeric() const;


   /* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
   void printAlpha() const;

 private:

   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned y) const;


   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const;

   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
   string name(unsigned m) const;

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const string &mn) const;
};


// Implement the Date member functions here
Date::Date () {
   day = 1; // sets to day
   month = 1; // sets to int value of month
   monthName = "January"; // sets to string name of month
   year = 2000; // sets to year
}

/* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
       */
Date::Date (unsigned m, unsigned d, unsigned y) {
   month  = m;
   day = d;
   year = y;

   if (month > 12 || month < 1 || day > daysPerMonth(month, year) || day < 1) {
      if (month > 12 || month < 1) {
         if (month > 12) {
            month  = 12;
         } else if (month < 1) {
            month = 1;
         }
      }

      if (day < 1) {
         day = 1;
      } else if (day > daysPerMonth(month, year)) {
         day = daysPerMonth(month, year);
      }

      cout <<  "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
   }
}


   /*
   if (m > 12 || m < 1 || d > 31 || d < 1) {
      //checks values for month
      if (m > 12) {
         month = 12;
      } else if (m < 1) {
         month = 1;
      } else {
         month = m;
      }

      //checks values for day
      if (d > 31) {
         day = 31;
      } else if (d < 1) {
         day = 1;
      } else {
         day = d;
      }
      
      year = y;

      cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;

   }

   year = y;
   */


/* parameterized constructor: month name, day, year
      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).
 
       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */ 
Date::Date(const string &mn, unsigned d, unsigned y) {
   //bool valid;
   
   monthName = mn;
   year = y;

   monthName.at(0) = toupper(monthName.at(0));

   if (monthName == "January" || monthName == "February" || monthName == "March" || monthName == "April" ||
       monthName == "May" || monthName == "June" || monthName == "July" || monthName == "August" ||
       monthName == "September" || monthName == "October" || monthName == "November" || monthName == "December") {
          month = number(monthName);
          
          if (d > daysPerMonth(month, year)) {
             day = daysPerMonth(month, year);
             cout <<  "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
          } else {
             day = d;
          }

          //cout << monthName << " " << day << ", " << year << endl;

   } else {
      monthName = "January";
      month = 1;
      day = 1;
      year = 2000;

      cout << "Invalid month name: the Date was set to 1/1/2000." << endl;
   }



   /*
   if (mn == "January" || mn == "january") {
      monthName = "January";
      valid = true;
   } else if (mn == "February" || mn == "february") {
      monthName = "February";
      valid = true;
   } else if (mn == "March" || mn == "march") {
      monthName = "March";
      valid = true;
   } else if (mn == "April" || mn == "april") {
      monthName = "April";
      valid = true;
   } else if (mn == "May" || mn == "may") {
      monthName = "May";
      valid = true;
   } else if (mn == "June" || mn == "june") {
      monthName = "June";
      valid = true;
   } else if (mn == "July" || mn == "july") {
      monthName = "July";
      valid = true;
   } else if (mn == "August" || mn == "august") {
      monthName = "August";
      valid = true;
   } else if (mn == "September" || mn == "september") {
      monthName = "September";
      valid = true;
   } else if (mn == "October" || mn == "october") {
      monthName = "October";
      valid = true;
   } else if (mn == "November" || mn == "november") {
      monthName = "November";
      valid = true;
   } else if (mn == "December" || mn == "december") {
      monthName = "December";
      valid = true;
   } else {
      valid = false;

      month = 1;
      monthName = "January";
      day = 1;
      year = 2000;

      cout << "Invalid month name: the Date was set to 1/1/2000." << endl;
   }

   if ((valid == true) && ((daysPerMonth(d, y)) < d)) {
      // valid = false;

      month = 1;
      monthName = "January";
      day = 1;
      year = 2000;

      cout << "Invalid month name: the Date was set to 1/1/2000." << endl;
   }

   if ((valid == true) && ((daysPerMonth(d, y) >= d))) {
      monthName = mn;
      day = d;
      year = y;

      cout << monthName << " " << day << ", " << year << endl;
   }
   */
}

void Date::printNumeric() const {
   cout << month << "/" << day << "/" << year;
}

/* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
void Date::printAlpha() const {
  
  cout << name(month) << " " << day << ", " << year;
   // try checking is string is  isUpper and if not run toUpper to captialize first letter. 
   // if not full month name 
   /*
   if (monthName == "jan" || monthName == "january" || monthName == "Jan") {
      monthName = "January";

   } else if (monthName == "feb" || monthName == "february" || monthName == "Feb") {
       monthName = "February";

   } else if (monthName == "mar" || monthName == "march" || monthName == "Mar") {
       monthName = "March";

   } else if (monthName == "apr" || monthName =="april" || monthName =="Apr") {
       monthName = "April";

   } else if (monthName == "may") {
       monthName = "May";

   } else if (monthName == "jun" || monthName == "june" || monthName == "Jun") {
       monthName = "June";

   } else if (monthName == "jul" || monthName == "july" || monthName == "Jul") {
       monthName = "July";

   } else if (monthName == "aug" || monthName == "august" || monthName == "Aug") {
       monthName = "August";

   } else if (monthName == "sep" || monthName == "september" || monthName == "Sep") {
       monthName = "September";

   } else if (monthName == "oct" || monthName == "october" || monthName == "Oct") {
       monthName = "October";

   } else if (monthName == "nov" || monthName == "november" || monthName == "Nov") {
       monthName = "November";

   } else if (monthName == "dec" || monthName == "december" || monthName == "Dec") {
       monthName = "December";
   }
   */
}

bool Date::isLeap (unsigned y) const {
   if (y % 4 == 0) {
      return true;
   } else if (y % 400 == 0) {
      return true;
   } else if (y % 100 == 0) {
      return false;
   } else {
      return false;
   }
}

unsigned Date::daysPerMonth(unsigned m, unsigned y) const {
   if (isLeap(y) == true && m == 2) {
      return 29;
   } else if (isLeap(y) == false && m == 2) {
      return 28;
   } else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
      return 31;
   } else if (m == 4 || m == 6 || m == 9 || m == 11) {
      return 30;
   }
   return 0;
}

string Date::name(unsigned m) const {
   if (m <= 1) {
      return "January";
   } else if (m == 2) {
      return "February";
   } else if (m == 3) {
      return "March";
   } else if (m==4) {
      return "April";
   } else if (m == 5) {
      return "May";
   } else if (m == 6) {
      return "June";
   } else if (m == 7) {
      return "July";
   } else if (m == 8) {
      return "August";
   } else if (m == 9) {
      return "September";
   } else if (m == 10) {
      return "October";
   } else if (m == 11) {
      return "November";
   } else if (m >= 12) {
      return "December";
   }
   return "Error";
}

unsigned Date::number(const string &mn) const {
   if (mn == "January") {
      return 1;
   } else if (mn == "February") {
      return 2;
   } else if (mn == "March") {
      return 3;
   } else if (mn == "April") {
      return 4;
   } else if (mn == "May") {
      return 5;
   } else if (mn == "June") {
      return 6;
   } else if (mn == "July") {
      return 7;
   } else if (mn == "August") {
      return 8;
   } else if (mn == "September") {
      return 9;
   } else if (mn == "October") {
      return 10;
   } else if (mn == "November") {
      return 11;
   } else if (mn == "December") {
     return 12;
   }
   return 0;
}


// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tets in submit mode.

Date getDate();

int main() {
   
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}
