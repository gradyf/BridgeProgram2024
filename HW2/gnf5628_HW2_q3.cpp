#include <iostream>

const int HOURS_IN_DAY = 24;
const int MINUTES_IN_HOUR = 60;

using namespace std;

/*
Question 3:
Hint: Try to adapt the elementary method for addition of numbers to this use.
Your program should interact with the user exactly as it shows in the following example:

 Please enter the number of days John has worked: 2
Please enter the number of hours John has worked: 12
Please enter the number of minutes John has worked: 15
Please enter the number of days Bill has worked: 3
 Please enter the number of hours Bill has worked: 15
 Please enter the number of minutes Bill has worked: 20
The total time both of them worked together is: 6 days, 3 hours and 35 minutes.

Suppose John and Bill worked for some time and we want to calculate the total time both of
them worked. Write a program that reads number of days, hours, minutes each of them
worked, and prints the total time both of them worked together as days, hours, minutes.
 */

int main() {

    int johnDays, johnHours, johnMinutes, billDays, billHours, billMinutes,
        totalDays, totalHours, totalMinutes;

    cout << "Please enter the number of days John has worked: " << endl;
    cin >> johnDays;

    cout << "Please enter the number of hours John has worked: " << endl;
    cin >> johnHours;

    cout << "Please enter the number of minutes John has worked: " << endl;
    cin >> johnMinutes;

    cout << "Please enter the number of days Bill has worked: " << endl;
    cin >> billDays;

    cout << "Please enter the number of hours Bill has worked: " << endl;
    cin >> billHours;

    cout << "Please enter the number of minutes Bill has worked: " << endl;
    cin >> billMinutes;

    totalMinutes = johnMinutes + billMinutes;
    totalHours = johnHours + billHours;
    totalDays = johnDays + billDays;

    totalHours = totalHours + (totalMinutes / MINUTES_IN_HOUR);
    totalDays = totalDays + (totalHours / HOURS_IN_DAY);

    totalMinutes = totalMinutes - ((totalMinutes / MINUTES_IN_HOUR) * MINUTES_IN_HOUR);
    totalHours = totalHours - ((totalHours / HOURS_IN_DAY) * HOURS_IN_DAY);

    cout << "The total time both of them worked together is: " << totalDays << " days, "
            << totalHours << " hours, and " << totalMinutes << " minutes.";
}
