//
// Created by Gray Forrester on 1/20/24.
//
#include <iostream>
#include <string>
using namespace std;

const double WEEKEND_RATE = 0.15;
const double WEEKDAY_PEAK = 0.40;
const double WEEKDAY_OFF = 0.25;

int main() {

    int hour, minute;

    double length, total;

    string day;

    char colon;

    cout << "Please enter a date, time, and length:" << endl;

    cin >> day;
    cin >> hour >> colon >> minute;
    cin >> length;

    if (day == "Sa" || day == "Su") {
        total = length * WEEKEND_RATE;
        cout << total;
    }
    else if (hour <= 7 || (hour >= 18 && minute > 0)) {
        total = length * WEEKDAY_OFF;
        cout << total;
    }
    else {
        total = length * WEEKDAY_PEAK;
        cout << total;
    }







}