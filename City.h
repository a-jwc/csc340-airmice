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

        void setCityDateAQI(string&, int&);

        // get the AQI by passing in the date
        int getAQIFromDate(string date) const;

        int getMapSize();

        void printInfo();

        void lookUpByName(string);

        // get the average AQI between a particular date range
        double getAverage(string dateFrom, string dateTo);
        
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
