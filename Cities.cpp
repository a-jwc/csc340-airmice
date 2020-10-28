#include <iostream>
#include "Cities.h"
#include "rapidcsv.h"

using namespace std;

bool Cities::readFile() {
    
    City c;
    
    // file handling
    ifstream inf;

    // print opening file
    cout << "opening file" << endl;

    // opening file
    inf.open("./data/California_airquality.csv", ios::in);

    // check if file is opened
    if(!inf.is_open()) {
        cout << "could not open" << endl;
        return false;
    } else {
        return true;
    }

    // while(!inf.eof()) {
    //     int num = 0;
    // }

}

void Cities::testRead() {
    // create instance of Document
    rapidcsv::Document doc("data/California_airquality.csv");

    // create vectors to hold various data types
    // let's talk about a way to get these into our other data types
    vector<int> aqi = doc.GetColumn<int>("DAILY_AQI_VALUE");
    vector<string> names = doc.GetColumn<string>("CBSA_NAME");
    vector<string> dates = doc.GetColumn<string>("Date");

    // print the amount of data read
    cout << "Read " << aqi.size() << " values for AQI." << endl; 
    cout << "Read " << names.size() << " values for city names." << endl; 
    cout << "Read " << dates.size() << " values for dates." << endl; 

    // prints out the first 6 entries
    for(auto i = 0; i < 6; i++) {
        cout << "Date: " << dates.at(i) << " | City Name: " << names.at(i) << " | AQI: " << aqi.at(i) << endl;
    }

}