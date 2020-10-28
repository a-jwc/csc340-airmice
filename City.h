#ifndef CITY_H
#define CITY_H

#include <map>

using namespace std;

class City {
    public:
        City();
        string getName() const;
        string setName() const;
        int getAQI(int date) const;
        double getAverage(int dateFrom, int dateTo);
        
    private:
        // city name
        string name;
        // map holding date and aqi
        map<int, int> dateAQI;
};

#endif