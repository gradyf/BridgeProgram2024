// Write a program that:
//•     Asks the user for their name.
//•     Asks the user to input their graduation year.
//•     Asks the user to input the current year.

//Assume the student is in a four-year undergraduate program. Display the current status the student is in.
// Possible status include: not in college yet, freshman, sophomore, junior, senior, graduated.

//Note: If graduation year equals to current year, status is ‘Graduated’;
// if graduation year is four years after current year, status is ‘Freshman’, etc.

//Your program should interact with the user exactly as it shows in the following example:
// Please enter your name: Jessica
//Please enter your graduation year: 2019
//Please enter current year: 2015
//Jessica, you are a Freshman
//

#include <iostream>
#include <string>

using namespace std;

int main() {

    string name;

    int grad_year, current_year;

    cout << "Please enter your name: ";
    cin >> name;

    cout << "Please enter your graduation year: ";
    cin >> grad_year;

    cout << "Please enter current year: ";
    cin >> current_year;

    switch (grad_year - current_year) {

        case (1):
            cout << name << ", you are a Senior";
            break;
        case (2):
            cout << name << ", you are a Junior";
            break;
        case (3):
            cout << name << ", you are a Sophomore";
            break;
        case (4):
            cout << name << ", you are a Freshman";
            break;
        default:
            if ((grad_year - current_year) <= 0) {
                cout << name << ", you have graduated";
            }
            else if ((grad_year - current_year) >= 5) {
                cout << name << ", you are not in college yet";
            }
            else {
                cout << name << "You entered something illogical";
            }
    }
}

