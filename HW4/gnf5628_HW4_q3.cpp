//
// Created by Gray Forrester on 1/24/24.
//
#include <iostream>
#include <cmath>
using namespace std;

int main () {

    int input, remainder = 0, total, base_two;

    double tracker = 0;


    cout << "Enter a decimal number: ";
    cin >> input;

    while (input > 0 ) {
        double base_two = 2;
        remainder = input % 2;

        base_two = pow(2,tracker);

        total = base_two * remainder;

        input = input / 2;
        tracker++;

    }

    cout << total;
}