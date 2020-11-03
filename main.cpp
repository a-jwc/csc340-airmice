#include <iostream>
#include "City.h"
#include "Cities.h"

using namespace std;

int main() {
    // testing class instantiation
    Cities ct;
    string cityName;
    char userOpt;
    bool mainFlag = false;

    ct.fileRead();
    ct.addData();

    cout << "/t/t/tWelcome to the Air Mice program" << endl;
    cout << endl;
    cout << "Enter name of a city and our program will give you an AQI of that location." << endl;
    cout << "Below is our list of city that our program currently provide for:" << endl;

    ct.printList();
    cout << endl;

    while (!mainFlag) {
        cout << "Here are functionalities that our program can provide for you, Please choose a letter:" << endl;
        cout << "A. Print AQI given city name and date." << endl;
        cout << "B. Print average AQI between dates." << endl;
        cout << "C. Print AQI of all cities by date." << endl;
        cout << "D. Quit" << endl;
        cout << "Option: ";
        cin >> userOpt;

        switch (userOpt) {
            case 'A':
            case 'a': {
                //implement aqi given city name and date
                bool check = false;
                bool flag = false;
                string cityUser, dateUser;
                City city;
                cout << "You have chosen option A." << endl;
                while (!flag) {
                    cout << "City: ";
                    cin >> cityUser;
                    city = ct.getCity(cityUser);

                    if (city.getName() == "")
                        cout << "Could not find city. Please try again." << endl;
                    else
                        cout << "Got city: " << city.getName() << endl;
                    flag = true;
                } //End while statement

                cout << "Please enter a specific date: ";
                cin >> dateUser;
                while (!check) {
                    if (city.hasDate(dateUser)) {
                        cout << "Valid date entry." << endl;
                        check = true;
                    } else {
                        cout << "Invalid date entry. Please try again" << endl;
                        cout << "Please enter the date that you want to start from: " << endl;
                        cin >> dateUser;
                    }
                }//End dateCheck while statement

                ct.getAqi(cityUser, dateUser);
                cout << endl;
                //mainFlag = true;
                break;
            }
            case 'B':
            case 'b': {
                // average AQI between dates
                string dateFrom, dateTo, cityName;
                bool flagCon = false;
                bool dateCheck = true;
                cout << "City: ";
                cin >> cityName;
                City city = ct.getCity(cityName);

                while (flagCon) {
                    if (city.getName() == "") {
                        cout << "Could not find city. Please try again." << endl;
                        cout << "City: ";
                        cin >> cityName;
                        city = ct.getCity(cityName);
                    } else {
                        cout << "Got city: " << city.getName() << endl;
                        flagCon = true;
                    }
                } //End while statement

                cout << "Format (M/DD/YYYY)" << endl;
                cout << "Please enter the date that you want to start from: ";
                cin >> dateFrom;

                while (dateCheck) {
                    //City dateCity;
                    if (city.hasDate(dateFrom)) {
                        cout << "Valid date entry." << endl;
                        dateCheck = false;
                    } else {
                        cout << "Invalid date entry. Please try again" << endl;
                        cout << "Please enter the date that you want to start from: ";
                        cin >> dateFrom;
                    }
                }//End dateCheck while statement

                dateCheck = false; //Restart the condition to check the next DateTo data
                cout << "Please enter your desire end-date: ";
                cin >> dateTo;
                while (dateCheck) {
                    if (city.hasDate(dateTo)) {
                        cout << "Valid date entry." << endl;
                        dateCheck = false;
                    } else {
                        cout << "Invalid date entry. Please try again" << endl;
                        cout << "Please enter your desire end-date: ";
                        cin >> dateTo;
                    }
                }//End dateCheck while statement

                // mainFlag = true;
                ct.getAvgFromRange(dateFrom, dateTo, cityName);
                cout << endl;
                break;
            }
            case 'C':
            case 'c': {
                //AQI of all cities by date
                bool flagCheck;
                string dateAQI;

                cout << "You have chosen Option C. Please enter a date: ";
                cin >> dateAQI;

                // mainFlag = true;
                ct.printCityAndAQIByDate(dateAQI);
                cout << endl;
                break;
            }
            case 'D':
            case 'd': {
                cout << "Quitting" << endl;
                mainFlag = true;
                break;
            }
            default: {
                cout << "Invalid option. Please choose one of the options that we have provided in the list above."
                        << endl;
            }
        }//End switch statement
    }//End mainFlag while statement

    return 0;
}
