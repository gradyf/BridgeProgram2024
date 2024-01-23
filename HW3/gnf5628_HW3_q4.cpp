\

#include <iostream>

using namespace std;

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

int main() {

    double base_number, decimal_number;
    int choice, new_number;

    cout << "Please enter a Real number: " <<endl;
    cin >> base_number;

    cout << "Please choose your rounding method: " <<endl << "1. Floor Round" << endl << "2. Ceiling Round"
         << endl << "3. Round to the nearest whole number" <<endl;

    cin >> choice;

    switch (choice) {

        case (FLOOR_ROUND):
            if (base_number >=0) {
                new_number = (int) base_number;
                cout << new_number;
            }
            else {
                new_number = (int) base_number - 1;
                cout << new_number;
            }
            break;
        case (CEILING_ROUND):
            if (base_number >= 0) {
                new_number = (int) base_number + 1;
                cout << new_number;
            }
            else {
                new_number = (int) base_number ;
                cout << new_number;
            }
            break;
        case (ROUND):
            decimal_number = base_number - (int) base_number;

            if (decimal_number >= 0.5) {
                new_number = (int) base_number + 1;
            }
            else if (decimal_number <= 0.5 && decimal_number >= 0){
                new_number = (int) base_number;
            }
            else if (decimal_number < -0.5) {
                new_number = (int) base_number-1;
            }
            else {
                new_number = (int) base_number ;
            }

            cout << new_number;
            break;
        default:
            cout << "That was not a choice";
    }


}