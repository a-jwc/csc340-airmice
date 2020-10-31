#include <iostream>
#include "City.h"
#include "Cities.h"

using namespace std;

int main() {
    // testing class instantiation
    Cities ct;

    // variable for testing
    string testCity = "Thousand Oaks";

    // testing getName and getDate functions
    // cout << c.getName() << endl;
    // cout << c.getAQI(date) << endl;

    ct.fileRead();
    ct.addData();
    //ct.printList();
    ct.lookUpCityAndPrint(testCity);
    ct.printCityAndAQIByDate("10/10/2020");
    

    return 0;
}