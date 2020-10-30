#include  <iostream>
#include "City.h"

using namespace std;

//default constructor
City::City() {}

// get name of city
string City::getName() const {
    return name;
}

// set the city name to the name variable
void City::setName(string cityName) {
    name = cityName;
}

void City::setCityDateAQI(string &key, int &element) {
    dateAQI.insert({key, element});
    // cout << dateAQI.at(key) << endl;
}

int City::getMapSize() {
    return dateAQI.size();
}

// get date by passing in an int parameter
int City::getAQIFromDate(string date) const {
    return dateAQI.at(date);
}

void City::printInfo() {
    cout << "City: " << getName() << " " << getMapSize() << endl;

    for(auto itr = dateAQI.cbegin(); itr != dateAQI.cend(); itr++) 
        cout << "City: " << getName() << " Date: " << itr->first << " AQI: " << itr->second << endl;
}

void City::lookUpByName(string name) {
    
}