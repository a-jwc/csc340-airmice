#ifndef CITY_H
#define CITY_H

#include <map>

using namespace std;

class City {
    public:
        string GetName();
        
    private:
        string name;
        map<int, int> dateAQI;
};

#endif