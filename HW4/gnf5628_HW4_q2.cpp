//
// Created by Gray Forrester on 1/23/24.
//

#include <iostream>
using namespace std;


int main() {

    int input;

    cout << "Enter decimal number:";

    cin >> input;

    while (input > 0) {

        if (input - 1000 >= 0) {
            cout << "M";
            input -= 1000;
        }
        else if (input - 500 >= 0) {
            cout << "D";
            input -= 500;
        }
        else if (input - 100 >= 0) {
            cout << "C";
            input -= 100;
        }
        else if (input - 50 >= 0) {
            cout << "L";
            input -= 50;
        }
        else if (input - 10 >= 0) {
            cout << "X";
            input -= 10;
        }
        else if (input - 5 >= 0) {
            cout << "V";
            input -= 5;
        }
        else {
            cout << "I";
            input -= 1;
        }
    }


}