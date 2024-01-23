
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

