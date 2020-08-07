#include <iostream>
#include <cstdlib>
#include <cmath>
#include "Distance.h"

using namespace std;

/* Constructs a default Distance of 0 (0 feet and 0.0 inches)
   */
   Distance::Distance () {
     feet = 0;
     inches = 0.0;
}


   /* Constructs a distance of ft feet and in inches,
        unless in >= 12, in which case the values of feet and inches
        are adjusted accordingly. A Distance will always be positive.
        Just convert negative inches to positive. Don't subtract from feet.
   */
   Distance::Distance(unsigned ft, double in) {
       feet = ft;
       inches = fabs(in);
       init();
       
       /* 
       while (inches >= 12) {
           inches -= 12;
           ++feet;
       }
       */
   }


   /* Constructs a distance of 0 ft and in inches, 
        unless in >= 12, in which case the values of feet and inches
        are adjusted accordingly. A Distance will always be positive.
        Just convert negative inches to positive. Don't subtract from feet.
   */
   Distance::Distance(double in) {
       feet = 0;
       inches = fabs(in);
       init();

       /*
       while (inches >= 12) {
           inches -= 12;
           ++feet;
       }
       */
   }


   /* Returns just the feet portion of the Distance
   */
    unsigned Distance::getFeet() const {
        return feet;
    }


   /* Returns just the inches portion of the Distance
   */
   double Distance::getInches() const {
       return inches;
   }


   /* Returns the entire distance as the equivalent amount of inches.
        (e.g., 4 feet 3.5 inches would be returned as 51.5 inches)
   */
   double Distance::distanceInInches() const {
       return (inches + (feet * 12));
   }


   /* Returns the entire distance as the equivalent amount of feet.
        (e.g., 3 feet 6 inches would be returned as 3.5 feet)
   */
   double Distance::distanceInFeet() const {
       return ((inches / 12.0) + feet);
   }


   /* Returns the entire distance as the equivalent amount of meters.
        1 inch equals 0.0254 meters.
        (e.g., 2 feet 8.12 inches would be returned as 0.815848 meters)
   */
   double Distance::distanceInMeters() const {
       return (distanceInInches() * 0.0254);
   }


   /* Returns the sum of 2 Distances.
   */
   Distance Distance::operator+(const Distance &rhs) const {
       return (distanceInInches()+rhs.distanceInInches());
   }


   /* Returns the difference between 2 Distances.
   */
   Distance Distance::operator-(const Distance &rhs) const {
       return (distanceInInches()-rhs.distanceInInches());
   }


   /* Outputs to the stream out the Distance in the format: 
        feet' inches'' (i.e. 3' 3.41'')
   */
   ostream & operator<<(ostream &out, const Distance &rhs) {
       out << rhs.feet << "' " << rhs.inches << '"';
       
       return out;
   }


   /* Used by the 2 parameterized constructors to convert any negative values to positive and
        inches >= 12 to the appropriate number of feet and inches.
   */
   void Distance::init() {
       while (inches >= 12) {
           inches -= 12;
           ++feet;
       }
   }