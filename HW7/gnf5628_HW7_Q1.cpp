//
// Created by Gray Forrester on 2/24/24.
//

#include <iostream>

using namespace std;

int printMonthCalendar(int numOfDays, int startingDay);
bool leapYear(int year);
void printYearCalendar(int year, int startingDay);

int main() {

    int year;
    int startingDay;

    cout << "Please enter a year: ";
    cin >> year;

    cout << "Please enter a starting day for 1/1: ";
    cin >> startingDay;

    printYearCalendar(year,startingDay);


    return 0;
}

int printMonthCalendar(int numOfDays, int startingDay) {

    int day = 1;
    int endOfWeek = 7;
    int lastDay;

    cout << "Mon" << "\t"
        << "Tue" << "\t"
        << "Wed" << "\t"
        << "Thr" <<"\t"
        << "Fri" <<"\t"
        << "Sat" <<"\t"
        << "Sun" << endl;

    //weeks
    for (int c = 0; c < 7; c++) {

        if(c == 0 && startingDay < 8) {
            for(int x = 1; x < startingDay; x++) {
                cout<< "\t";

            }
            endOfWeek = endOfWeek - startingDay + 1;
        }

        //columns - days of the week
        for(int r = 0; r < endOfWeek; r++) {
            if (day > numOfDays) {
                break;
            }

            cout << day << "\t";
            day++;
            lastDay = r+1;

        }
        if (day > numOfDays) {
            break;
        }
        cout << endl;
        endOfWeek = 7;
    }

    return lastDay;
}

bool leapYear(int year) {
    if (year % 400 == 0) {
        return true;
    }
    else if((year % 4 == 0) && (year % 100 == 0)) {
        return false;
    }
    else if(year % 4 == 0) {
        return true;
    }
    else {
        return false;
    }
}

void printYearCalendar(int year, int startingDay) {

    int numberOfDays;

    for(int month = 1; month <=12; month++) {

        switch (month) {
            case (1):
                cout<< "January " << year << endl;
                numberOfDays = 31;
                break;
            case(2):
                cout << "February " << year << endl;
                if(leapYear(year)) {
                    numberOfDays = 29;
                }
                else {
                    numberOfDays = 28;
                }
                break;
            case(3):
                cout << "March " << year << endl;
                numberOfDays = 31;
                break;
            case(4):
                cout << "April " << year << endl;
                numberOfDays = 30;
                break;
            case(5):
                cout << "May " << year << endl;
                numberOfDays = 31;
                break;
            case(6):
                cout << "June " << year << endl;
                numberOfDays = 30;
                break;
            case(7):
                cout<< "July " << year << endl;
                numberOfDays = 31;
                break;
            case(8):
                cout << "August " << year << endl;
                numberOfDays = 31;
                break;
            case(9):
                cout << "September " << year << endl;
                numberOfDays = 30;
                break;
            case(10) :
                cout << "October " << year << endl;
                numberOfDays = 31;
                break;
            case(11):
                cout << "November " << year << endl;
                numberOfDays = 30;
                break;
            case(12):
                cout << "December " << year << endl;
                numberOfDays = 31;
                break;
        }

        startingDay = printMonthCalendar(numberOfDays, startingDay) + 1;
        cout<< endl << endl;
    }
}
