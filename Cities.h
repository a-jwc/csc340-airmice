#ifndef CITIES_H
#define CITIES_H

#include <vector>
#include <fstream>
#include "City.h"

using namespace std;

class Cities {
    public:
        bool readFile();
    private:
        // holds list of cities
        vector<City> cityList;
};

#endif