#ifndef CITY_H
#define CITY_H

#include <map>

using namespace std;

class City {
    public:
        City();
        string getName();
        string setName();
        int getDate(int);
        
    private:
        // city name
        string name;
        // map holding date and aqi
        map<int, double> dateAQI;
};

#endif