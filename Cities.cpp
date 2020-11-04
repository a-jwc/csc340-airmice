#include <iostream>
#include <algorithm>
#include "Cities.h"
#include "rapidcsv.h"

using namespace std;

// reads in data (city names, dates, AQI) into individual vectors 
void Cities::fileRead() {
    // create instance of Document
    rapidcsv::Document doc("data/California_airquality.csv");

    // create vectors to hold various data types
    names = doc.GetColumn<string>("Site Name");
    dates = doc.GetColumn<string>("Date");
    aqi = doc.GetColumn<int>("DAILY_AQI_VALUE");

    // print the amount of data read
    // cout << "Read " << aqi.size() << " values for AQI." << endl; 
    // cout << "Read " << names.size() << " values for city names." << endl; 
    // cout << "Read " << dates.size() << " values for dates." << endl; 

}

// moves the data from the vectors into the proper datatypes
void Cities::addData() {
    City tempCity;
    int count = 2;
    tempCity = setInitialCityName(names.at(0));
    //tempCity.setCityDateAQI(dates.at(0),aqi.at(0));
    setDateAQI(dates.at(0), aqi.at(0), tempCity);
    // cout << "City 1: " << tempCity.getName() << endl;

    for(int i = 1; i < dates.size(); i++) {
        if(names.at(i) == tempCity.getName()) {
            setDateAQI(dates.at(i), aqi.at(i), tempCity);
        } else if (names.at(i) != tempCity.getName()) {
            cityList.push_back(tempCity);
            tempCity = setInitialCityName(names.at(i));
            setDateAQI(dates.at(i), aqi.at(i), tempCity);
            // cout << "City " << count << ": " << tempCity.getName() << endl;
            count++;
        }
    }

}

// set the city name by calling City's member function setName() and push that city object into cityList vector
City Cities::setInitialCityName(string name) {
    City city;
    city.setName(name);
    return city;
}

// calls City function setCityDateAQI to set the date and AQI pair in the map container
void Cities::setDateAQI(string &date, int &aqi, City &city) {
    city.setCityDateAQI(date,aqi);
}

// returns the city name by going to the index i of cityList
string Cities::getCityNameByIndex(int i) const {
    return cityList.at(i).getName();
}

// prints a list of the names of the cities in cityList
void Cities::printList() {
    for(auto i : cityList) {
        cout << i.getName() << endl;
    }
}

// prints the size of the map container for a particular city
void Cities::printCityMapSize(City city) {
    cout << city.getMapSize() << endl;
}

// looks up a city by name and prints the associated data
void Cities::lookUpCityAndPrint(string name) {
    for(auto i : cityList) {
        if(i.getName() == name) {
            cout << "Found city!" << endl;
            i.printInfo();
            break;
        }
    }
}

// prints the city name and AQI for a particular date
void Cities::printCityAndAQIByDate(string date) {
    int count = 0;
    cout << "AQIs on " << date << ": " << endl;
    for(auto i : cityList) {
        if(i.hasDate(date)) {
            count++;
            cout << "City Name: "<< i.getName() << " | AQI: " << i.getAQIFromDate(date) << endl;
        }
    }
    cout << "There were " << count << " cities with this date." << endl;
}

// calls the City function getAverage and prints the average AQI
void Cities::getAvgFromRange(string dateFrom, string dateTo, string cityName) {
    City city = getCity(cityName);
    cout << "Average AQI: " << city.getAverage(dateFrom, dateTo) << endl;
    
}

// calls the searchCity function and returns a city by name
City Cities::getCity(string cityName) {
    City city;
    searchCity(cityName, city);
    return city;
}

// iterates through the cityList to find a city by name
void Cities::searchCity(string cityName, City &city) {
    for(auto i : cityList) {
        if(i.getName() == cityName) {
            city = i;
        }
    }
}

// Return AQI of a city with a specified date.
int Cities::getAqi(const string& name, const string& date){
    int AQI;
    City foundCity;

    foundCity = getCity(name);

    if(foundCity.hasDate(date)){
        cout << "The AQI for " << date << " is " << foundCity.getAQI(date);
    }
    else{
        cout << "Date not Found." << endl;
    }

    return foundCity.getAQI(date);
}//end getAqi
