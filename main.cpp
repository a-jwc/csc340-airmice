#include <iostream>
#include <fstream>
#include "City.h"
#include "Cities.h"

using namespace std;

int main() {
    // testing class instantiation
    Cities ct;
    City c;  

    // file handling
    ifstream in;

    // string variable for testing
    string date;
    int i = 0;

    // print opening file
    cout << "opening file" << endl;

    // opening file
    in.open("./data/California_airquality.csv", ios::in);

    // check if file is opened
    if(!in.is_open()) {
        cout << "could not open" << endl;
        return 1;
    }

    // testing getName and getDate functions
    cout << c.getName() << endl;
    cout << c.getDate(i) << endl;

    return 0;
}