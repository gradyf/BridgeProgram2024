//
//Write a program that asks the user to enter a Real number, then it asks the user to enter the method by which they want to round that number (floor, ceiling or to the nearest integer). The program will then print the rounded result.
//Your program should interact with the user exactly as it shows in the following example:
//
// Please enter a Real number:
//4.78
//
// Choose your rounding method:
//1. Floor round
//2. Ceiling round
//3. Round to the nearest whole number:2
//5
//
// Implementation requirements:
//1. Use a switch statement.
//2. You are not allowed to include and use the math library.
//

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