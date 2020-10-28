#include <iostream>
#include "City.h"
#include "Cities.h"

using namespace std;

int main() {
    // testing class instantiation
    Cities ct;
    City c;  

    // string variable for testing
    int date = 0;

    // testing getName and getDate functions
    cout << c.getName() << endl;
    cout << c.getDate(date) << endl;

    return 0;
}