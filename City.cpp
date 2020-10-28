#include  <iostream>
#include "City.h"

using namespace std;

//default constructor
City::City() {
    name = "none";
    dateAQI[0] = 0.0;
}

// get name of city
string City::getName() {
    return name;
}

// get date by passing in an int parameter
int City::getDate(int i) {
    return dateAQI[i];
}