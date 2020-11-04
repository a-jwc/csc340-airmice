#ifndef CITY_H
#define CITY_H

#include <map>

using namespace std;

class City {
    public:
        // default constructor
        City();

        // get name prototype
        string getName() const;

        // set name prototype
        void setName(string name);

        // calls the map insert function to add the date-AQI pair to our map container
        void setCityDateAQI(string&, int&);

        // get the AQI by passing in the date
        int getAQIFromDate(string date) const;

        // return map size
        int getMapSize();

        // prints the info for a city
        void printInfo();

        // get the average AQI between a particular date range
        double getAverage(string dateFrom, string dateTo);

        // returns true if a city has a particular date
        bool hasDate(string);

        // returns the AQI for a city on a particular date
        int getAQI(const string& date);
        
    private:
        // city name
        string name;
        // map holding date and aqi respectively
        map<string, int> dateAQI;
    
        //extra function for getAverage
        void changeIntoString(const int&, const int&, string&);
        void changeIntoInt(string, int&, int&, int&);
        int dateToDays(string);
};

#endif
