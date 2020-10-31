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

        void setDateAQI(string&, int&, City&);

        void lookUpCityAndPrint(string);

        int getDate() const;

        void printCityMapSize(City);

        // print city names prototype
        void printList();

        void printCityAndAQIByDate(string);
    private:
        // holds list of cities
        vector<City> cityList;
        // City city;

        vector<string> names;
        vector<string> dates;
        vector<int> aqi;
};

#endif