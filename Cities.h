#ifndef CITIES_H
#define CITIES_H

#include <vector>
#include <fstream>
#include "City.h"

using namespace std;

class Cities {
    public:

        // use rapidcsv.h to read and parse data
        void fileRead();

        void addData();

        // set city prototype
        City setInitialCityName(string name);

        // get city name prototype
        string getCityNameByIndex(int i) const;
        
        // calls the searchCity function and returns a city by name
        City getCity(string);

        // iterates through the cityList to find a city by name
        void searchCity(string, City&);

        // calls City function setCityDateAQI to set the date and AQI pair in the map container
        void setDateAQI(string&, int&, City&);

        // looks up a city by name and prints the associated data
        void lookUpCityAndPrint(string);

        // prints the size of the map container for a particular city
        void printCityMapSize(City);

        // print city names prototype
        void printList();

        // prints the city name and AQI for a particular date
        void printCityAndAQIByDate(string);

        // calls the City function getAverage and prints the average AQI
        void getAvgFromRange(string, string, string);
    
        // Return AQI of a city with a specified date.
        int getAqi(const string& name, const string& date);
    private:
        // holds list of cities
        vector<City> cityList;

        // vectors to hold initial data
        vector<string> names;
        vector<string> dates;
        vector<int> aqi;
};

#endif
