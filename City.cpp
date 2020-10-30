#include  <iostream>
#include "City.h"

using namespace std;

//default constructor
City::City() {}

// get name of city
string City::getName() const {
    return name;
}

// set the city name to the name variable
void City::setName(string cityName) {
    name = cityName;
}

void City::setCityDateAQI(string &key, int &element) {
    dateAQI.insert({key, element});
    // cout << dateAQI.at(key) << endl;
}

int City::getMapSize() {
    return dateAQI.size();
}

// get date by passing in an int parameter
int City::getAQIFromDate(string date) const {
    return dateAQI.at(date);
}

void City::printInfo() {
    cout << "City: " << getName() << " " << getMapSize() << endl;

    for(auto itr = dateAQI.cbegin(); itr != dateAQI.cend(); itr++) 
        cout << "City: " << getName() << " Date: " << itr->first << " AQI: " << itr->second << endl;
}

void City::lookUpByName(string name) {
    
}

void City::changeIntoString(const int& day, const int& month, string& tempDate){
    //switching from int back to string
    //replacing month
    string monthString = to_string(month);
    tempDate.at(0) = monthString.at(0);

    //deleting day
    tempDate.erase(2, 1); //1/12/20
    if(tempDate.at(2) != '/'){
        tempDate.erase(2,1);
    }//end if

    //inserting correct day
    tempDate.insert(2, to_string(day));
}//end changeIntoString

double City::getAverage(string dateFrom, string dateTo) {
    //note: map organizes dates properly
    //checking whether the dates lie in between our ranges.

    //getting first date
    string checkFrom = dateAQI.cbegin()->first;
    //getting last date
    string checkTo = (--dateAQI.end())->first;

    //using a while statement to check if dates are valid
    while ((checkFrom >= dateFrom) || (checkTo <= dateTo)) {
        cout << "ERROR: Please enter dates between(and including)" <<
             checkFrom << " and " << checkTo << endl;
        cout << "Enter date from: ";
        cin >> dateFrom;
        cout << "Enter date to: \\ ";
        cin >> dateTo;
    }//end while statement

    //initializing counter and total
    int counter = 0;
    int total = 0;
    string tempDate = dateFrom;

    //initializing current day
    string monthC = "", dayC = "";
    monthC = monthC + dateFrom.at(0);
    dayC = dayC + dateFrom.at(2);
    if (dateFrom.at(3) != '/') {
        dayC = dayC + dateFrom.at(3);
    }

    //initializing date to
    string monthTo = "", dayTo = "";
    monthTo = monthTo + dateTo.at(0);
    dayTo = dayTo + dateTo.at(2);
    if (dateTo.at(3) != '/') {
        dayTo = dayTo + dateTo.at(3);
    }


    //Converting string to int (Date & Month)
    int dateFromInt = stoi(dayC); //start
    int dateToInt = stoi(dayTo);  //end
    int monthFromInt = stoi(monthC); //start
    int monthToInt = stoi(monthTo); //end

    while (monthFromInt <= monthToInt) {
            switch (monthFromInt) {
                case 1:
                    for (int i = dateFromInt; i <= 31; i++) {
                        changeIntoString(i, monthFromInt, tempDate);

                        //adding to the total
                        total = total + dateAQI.at(tempDate);
                        counter++;

                        //getting out of while statement if reaches to date
                        if (monthFromInt == monthToInt && i == dateToInt) {
                            monthFromInt = 99;
                            goto correctDate;
                        }//end if
                    }//end for
                    dateToInt = 1;
                    monthFromInt++;
                    break;
                case 2:
                    for (int i = dateFromInt; i <= 28; i++) {
                        changeIntoString(i, monthFromInt, tempDate);

                        //adding to the total
                        total = total + dateAQI.at(tempDate);
                        counter++;

                        //getting out of while statement if reaches to date
                        if (monthFromInt == monthToInt && i == dateToInt) {
                            monthFromInt = 99; //For getting out the loop
                            goto correctDate;
                        }//end if
                    }//end for
                    dateToInt = 1;
                    monthFromInt++;
                    break;
                case 3:
                    for (int i = dateFromInt; i <= 31; i++) {
                        changeIntoString(i, monthFromInt, tempDate);

                        //adding to the total
                        total = total + dateAQI.at(tempDate);
                        counter++;

                        //getting out of while statement if reaches to date
                        if (monthFromInt == monthToInt && i == dateToInt) {
                            monthFromInt = 99; //For getting out the loop
                            goto correctDate;
                        }//end if
                    }//end for
                    dateToInt = 1;
                    monthFromInt++;
                    break;
                case 4:
                    for (int i = dateFromInt; i <= 30; i++) {
                        changeIntoString(i, monthFromInt, tempDate);

                        //adding to the total
                        total = total + dateAQI.at(tempDate);
                        counter++;

                        //getting out of while statement if reaches to date
                        if (monthFromInt == monthToInt && i == dateToInt) {
                            monthFromInt = 99; //For getting out the loop
                            goto correctDate;
                        }//end if
                    }//end for
                    dateToInt = 1;
                    monthFromInt++;
                    break;
                case 5:
                    for (int i = dateFromInt; i <= 31; i++) {
                        changeIntoString(i, monthFromInt, tempDate);

                        //adding to the total
                        total = total + dateAQI.at(tempDate);
                        counter++;

                        //getting out of while statement if reaches to date
                        if (monthFromInt == monthToInt && i == dateToInt) {
                            monthFromInt = 99; //For getting out the loop
                            goto correctDate;
                        }//end if
                    }//end for

                    dateToInt = 1;
                    monthFromInt++;
                    break;
                case 6:
                    for (int i = dateFromInt; i <= 30; i++) {
                        changeIntoString(i, monthFromInt, tempDate);

                        //adding to the total
                        total = total + dateAQI.at(tempDate);
                        counter++;

                        //getting out of while statement if reaches to date
                        if (monthFromInt == monthToInt && i == dateToInt) {
                            monthFromInt = 99; //For getting out the loop
                            goto correctDate;
                        }//end if
                    }//end for
                    dateToInt = 1;
                    monthFromInt++;
                    break;
                case 7:
                    for (int i = dateFromInt; i <= 31; i++) {
                        changeIntoString(i, monthFromInt, tempDate);

                        //adding to the total
                        total = total + dateAQI.at(tempDate);
                        counter++;

                        //getting out of while statement if reaches to date
                        if (monthFromInt == monthToInt && i == dateToInt) {
                            monthFromInt = 99; //For getting out the loop
                            goto correctDate;
                        }//end if
                    }//end for
                    // dateToInt = 1;
                    monthFromInt++;
                    break;
                case 8:
                    for (int i = dateFromInt; i <= 30; i++) {
                        changeIntoString(i, monthFromInt, tempDate);

                        //adding to the total
                        total = total + dateAQI.at(tempDate);
                        counter++;

                        //getting out of while statement if reaches to date
                        if (monthFromInt == monthToInt && i == dateToInt) {
                            monthFromInt = 99; //For getting out the loop
                            goto correctDate;
                        }//end if
                    }//end for
                    dateToInt = 1;
                    monthFromInt++;
                    break;
                case 9:
                    for (int i = dateFromInt; i <= 31; i++) {
                        changeIntoString(i, monthFromInt, tempDate);

                        //adding to the total
                        total = total + dateAQI.at(tempDate);
                        counter++;
                            //getting out of while statement if reaches to date
                            if (monthFromInt == monthToInt && i == dateToInt) {
                                monthFromInt = 99; //For getting out the loop
                                goto correctDate;
                            }//end if
                        }//end for
                        dateToInt = 1;
                        monthFromInt++;
                        break;
            }//end switch
            //to escape switch once reaching the correct date

    }//end while
    correctDate:
    return ((double) total / (double) counter);
}//end getAverage
