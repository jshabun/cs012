#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

void readData(const string &, vector<double> &, vector<double> &);
double interpolation(double, const vector<double> &, const vector<double> &);
bool isOrdered(const vector<double> &);
void reorder(vector<double> &, vector<double> &);

int main () {
    string inFS;
    vector<double> angle;
    vector<double> lift;
    double angleInput = 0.0;
    double liftCoef = 0.0;
    bool myBool = true;

    cin >> inFS;

    readData (inFS, angle, lift);

    if (angle.empty()) {
        while (angle.empty() || (angle.size() != lift.size())) {
            cout << "Enter a new filename:" << endl;
            cin >> inFS;
            readData (inFS, angle, lift);
        }
    }

    while (!isOrdered(angle)) {
        reorder (angle, lift);
    }

    while (myBool) {
        cout << "Enter flight path angle:" << endl;
        cin >> angleInput;
        if (angleInput == 0) {
            myBool = false;
        } else if (angleInput < angle.at(0) || angleInput > angle.at(angle.size() - 1)) {
            cin >> angleInput;
        } else {
            liftCoef = interpolation (angleInput, angle, lift);
            cout << "flight path angle " << angleInput << " is " << liftCoef << endl;
        }
    }
    return 1;
}

void readData (const string& inFS, vector<double>& angle, vector<double>& lift) {
    ifstream data;
    double val1 = 0.0;
    double val2 = 0.0;
    
    data.open(inFS); // opens inputted file

    if (!data.is_open()) {
        cout << "Error opening " << inFS << endl; // checks whether inputted file was successfully opened or not
        exit(1); // if not opened outputs message, stops program, and returns 1
    }

    while (data >> val1) {
        angle.push_back (val1); // takes values and inputs 1st digit to 1st vector and 2nd digit to second vector
        data >> val2;
        lift.push_back (val2);
    }

    data.close();
}

double interpolation (double angleInput, const vector<double>& angle, const vector<double>& lift) {
    for (unsigned int i = 0; i < angle.size(); ++i) {
        if (angle.at(i) == angleInput) {
            return lift.at(i);
        }
    }

    for (unsigned int i = 0; i < angle.size(); ++i) {
        if (angle.at(i) < angleInput) {
            return lift.at(i) + ((angleInput - angle.at(i)) / (angle.at(i + 1) - angle.at(i))) * (lift.at(i + 1) - lift.at(i)); // f(b) = f(a) + ((b - a) / (c - a)) (f(c) - f(a))
        }
    }
    return 0;
}

bool isOrdered (const vector<double>& angle) {
    if (!angle.empty()) {
        for (unsigned int i = 0; i + 1 < angle.size(); ++i) {
            if (angle.at(i) > angle.at (i + 1)) {
                return false;
            }
        }
    }
    return true;
}

void reorder (vector<double>& angle, vector<double>& lift) {
    for (unsigned int i = 0; i < angle.size(); ++i) {
		
        unsigned x = i;
		
        for (unsigned int j = i + 1; j < angle.size(); ++j) {
			if (angle.at(j) < angle.at(x)) {
				x = j;
			}
		}
		
        swap(angle.at(i), angle.at(x));
		swap(lift.at(i), lift.at(x));
	}

    /*
    sort (angle.begin(), angle.end());
    sort (lift.begin(), lift.end());
    */
}
