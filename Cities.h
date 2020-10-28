#ifndef CITIES_H
#define CITIES_H

#include <vector>
#include <fstream>
#include "City.h"

using namespace std;

class Cities {
    public:
        // old method
        bool readFile();

        // use rapidcsv.h to read and parse data
        void testRead();
    private:
        // holds list of cities
        vector<City> cityList;
};

#endif