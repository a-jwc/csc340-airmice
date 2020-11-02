#include <iostream>
#include <algorithm>
#include "Cities.h"
#include "rapidcsv.h"

using namespace std;

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

void Cities::setDateAQI(string &date, int &aqi, City &city) {
    city.setCityDateAQI(date,aqi);
}

// returns the city name by going to the index i of cityList
string Cities::getCityNameByIndex(int i) const {
    return cityList.at(i).getName();
}

void Cities::printList() {
    for(auto i : cityList) {
        cout << i.getName() << endl;
    }
}

void Cities::printCityMapSize(City city) {
    cout << city.getMapSize() << endl;
}

void Cities::lookUpCityAndPrint(string name) {
    for(auto i : cityList) {
        if(i.getName() == name) {
            cout << "Found city!" << endl;
            i.printInfo();
            break;
        }
    }
}

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

void Cities::getAvgFromRange(string dateFrom, string dateTo, string cityName) {
    City city = getCity(cityName);
    city.getAverage(dateFrom, dateTo);
}

City Cities::getCity(string cityName) {
    City city;
    searchCity(cityName, city);
    return city;
}

void Cities::searchCity(string cityName, City &city) {
    for(auto i : cityList) {
        if(i.getName() == cityName) {
            city = i;
        }
    }
}