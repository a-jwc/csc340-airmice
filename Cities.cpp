#include  <iostream>
#include "Cities.h"

using namespace std;

bool readFile() {
    // file handling
    ifstream in;

    // print opening file
    cout << "opening file" << endl;

    // opening file
    in.open("./data/California_airquality.csv", ios::in);

    // check if file is opened
    if(!in.is_open()) {
        cout << "could not open" << endl;
        return false;
    } else {
        return true;
    }

}