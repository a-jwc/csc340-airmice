#include <iostream>
#include <string>
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

void City::changeIntoInt(string date, int& month, int& day, int& year)
{
    //initializing tempMonth, tempDay and tempYear to get numbers after 9
    string tempMonth = "", tempDay = "", tempYear = "";

    tempMonth = tempMonth + date.at(0);
    date.erase(0, 1); //erasing what has been read
    if(date.at(0) != '/') {
        tempMonth = tempMonth + date.at(0);
        date.erase(0, 1);
    }
    date.erase(0, 1);

    month = stoi(tempMonth);


    // */*/**  */**/**
    tempDay = tempDay + date.at(0);
    date.erase(0, 1);
    if(date.at(0) != '/') {
        tempDay = tempDay + date.at(0);
        date.erase(0, 1);
    }
    date.erase(0, 1);

    //working on day, changing string to int using stoi
    day = stoi(tempDay);

    //working on year
    tempYear = tempYear + date.at(0);
    tempYear = tempYear + date.at(1);
    //using stoi again
    year = stoi(tempYear);
}//end changeIntoInt

int City::dateToDays(string date){
    //day counter
    int days = 0, dayFromDate, monthFromDate, YearFromDate;
    changeIntoInt(date, monthFromDate, dayFromDate, YearFromDate);

    switch (monthFromDate) {
        case 1:
            days = days + dayFromDate;
            break;
        case 2:
            //number of days in January
            days = days + 31;
            //adding the number of days in February
            days = days + dayFromDate;
            break;
        case 3:
            days = days + 31 + 29;
            days = days + dayFromDate;
            break;
        case 4:
            days = days + 31 + 29 + 31;
            days = days + dayFromDate;
            break;
        case 5:
            days = days + 31 + 29 + 31 + 30;
            days = days + dayFromDate;
            break;
        case 6:
            days = days + 31 + 29 + 31 + 30 + 31;
            days = days + dayFromDate;
            break;
        case 7:
            days = days + 31 + 29 + 31 + 30 + 31 + 30;
            days = days + dayFromDate;
            break;
        case 8:
            days = days + 31 + 29 + 31 + 30 + 31 + 30 + 31;
            days = days + dayFromDate;
            break;
        case 9:
            days = days + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31;
            days = days + dayFromDate;
            break;
        case 10:
            days = days + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
            days = days + dayFromDate;
            break;
        case 11:
            days = days + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
            days = days + dayFromDate;
            break;
        case 12:
            days = days + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
            days = days + dayFromDate;
            break;
    }//end switch
    return days;
}// end DatetoDays

double City::getAverage(string dateFrom, string dateTo) {
    //note: map organizes dates properly
    //checking whether the dates lie in between our ranges.

    //getting first date
    string checkFrom = dateAQI.cbegin()->first;
    //getting last date
    string checkTo = (--dateAQI.end())->first;

    //checking input
    while ( (dateToDays(checkFrom) > dateToDays(dateFrom) ) || (dateToDays(checkTo) < dateToDays(dateTo)) || (dateToDays(dateFrom)) > dateToDays(dateTo)) {
        cout << "ERROR: Please enter dates between(and including)" <<
             checkFrom << " and " << checkTo << endl;
        cout << "Enter date from: ";
        cin >> dateFrom;
        cout << "Enter date to: ";
        cin >> dateTo;
    }//end while statement

    //initializing counter and total
    int counter = 0;
    int total = 0;
    string tempDate = dateFrom;


    //Converting string to int (Date & Month)
    int dateFromInt, monthFromInt, yearFromInt; //start
    int dateToInt, monthToInt, yearToInt;  //end

    changeIntoInt(tempDate,monthFromInt, dateFromInt, yearFromInt); //date from
    changeIntoInt(dateTo, monthToInt, dateToInt, yearToInt); //date to

    while (monthFromInt <= monthToInt) {
            switch (monthFromInt) {
                case 1:
                    for (int i = dateFromInt; i <= 31; i++) {
                        changeIntoString(i, monthFromInt, tempDate);

                        //adding to the total
                        if(hasDate(tempDate)) {
                            total = total + dateAQI.at(tempDate);
                            counter++;
                        }
                        
                        //getting out of while statement if reaches to date
                        if (monthFromInt == monthToInt && i == dateToInt) {
                            goto correctDate;
                        }//end if
                    }//end for
                    dateToInt = 1;
                    monthFromInt++;
                    break;
                case 2:
                    for (int i = dateFromInt; i <= 29; i++) {
                        changeIntoString(i, monthFromInt, tempDate);

                        if(hasDate(tempDate)) {
                            total = total + dateAQI.at(tempDate);
                            counter++;
                        }

                        //getting out of while statement if reaches to date
                        if (monthFromInt == monthToInt && i == dateToInt) {
                            goto correctDate;
                        }//end if
                    }//end for
                    dateToInt = 1;
                    monthFromInt++;
                    break;
                case 3:
                    for (int i = dateFromInt; i <= 31; i++) {
                        changeIntoString(i, monthFromInt, tempDate);

                        if(hasDate(tempDate)) {
                            total = total + dateAQI.at(tempDate);
                            counter++;
                        }

                        //getting out of while statement if reaches to date
                        if (monthFromInt == monthToInt && i == dateToInt) {
                            goto correctDate;
                        }//end if
                    }//end for
                    dateToInt = 1;
                    monthFromInt++;
                    break;
                case 4:
                    for (int i = dateFromInt; i <= 30; i++) {
                        changeIntoString(i, monthFromInt, tempDate);

                        if(hasDate(tempDate)) {
                            total = total + dateAQI.at(tempDate);
                            counter++;
                        }

                        //getting out of while statement if reaches to date
                        if (monthFromInt == monthToInt && i == dateToInt) {
                            goto correctDate;
                        }//end if
                    }//end for
                    dateToInt = 1;
                    monthFromInt++;
                    break;
                case 5:
                    for (int i = dateFromInt; i <= 31; i++) {
                        changeIntoString(i, monthFromInt, tempDate);

                        if(hasDate(tempDate)) {
                            total = total + dateAQI.at(tempDate);
                            counter++;
                        }

                        //getting out of while statement if reaches to date
                        if (monthFromInt == monthToInt && i == dateToInt) {
                            goto correctDate;
                        }//end if
                    }//end for

                    dateToInt = 1;
                    monthFromInt++;
                    break;
                case 6:
                    for (int i = dateFromInt; i <= 30; i++) {
                        changeIntoString(i, monthFromInt, tempDate);

                        if(hasDate(tempDate)) {
                            total = total + dateAQI.at(tempDate);
                            counter++;
                        }

                        //getting out of while statement if reaches to date
                        if (monthFromInt == monthToInt && i == dateToInt) {
                            goto correctDate;
                        }//end if
                    }//end for
                    dateToInt = 1;
                    monthFromInt++;
                    break;
                case 7:
                    for (int i = dateFromInt; i <= 31; i++) {
                        changeIntoString(i, monthFromInt, tempDate);

                        if(hasDate(tempDate)) {
                            total = total + dateAQI.at(tempDate);
                            counter++;
                        }

                        //getting out of while statement if reaches to date
                        if (monthFromInt == monthToInt && i == dateToInt) {
                            goto correctDate;
                        }//end if
                    }//end for
                    // dateToInt = 1;
                    monthFromInt++;
                    break;
                case 8:
                    for (int i = dateFromInt; i <= 30; i++) {
                        changeIntoString(i, monthFromInt, tempDate);

                        if(hasDate(tempDate)) {
                            total = total + dateAQI.at(tempDate);
                            counter++;
                        }

                        //getting out of while statement if reaches to date
                        if (monthFromInt == monthToInt && i == dateToInt) {
                            goto correctDate;
                        }//end if
                    }//end for
                    dateToInt = 1;
                    monthFromInt++;
                    break;
                case 9:
                    for (int i = dateFromInt; i <= 31; i++) {
                        changeIntoString(i, monthFromInt, tempDate);
                        
                        if(hasDate(tempDate)) {
                            total = total + dateAQI.at(tempDate);
                            counter++;
                        }
                        
                            //getting out of while statement if reaches to date
                            if (monthFromInt == monthToInt && i == dateToInt) {
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

bool City::hasDate(string date) {
    auto it = dateAQI.find(date);
    if(it != dateAQI.end()) {
        return true;
    } else
    {
        return false;
    }
}
