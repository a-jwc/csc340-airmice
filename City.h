#include <iostream>
#include <string>
#include <map>
using namespace std;
#ifndef CITY_H
#define CITY_H

class City{
public:
    string GetName() const;
    string SetName();
    int GetAQI(int date) const;
    bool inputData(int Date,double Aqi); //bool to check if input in succesful?
    double GetAverage(int dateFrom, int dateTo);



private:
    string name;
    map<int, double> DateAQI;
};

#endif
