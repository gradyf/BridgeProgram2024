//
// Created by Gray Forrester on 1/24/24.
//
#include <iostream>
using namespace std;

int main () {

    int input, tracker = 0, remainder = 0, total, base_two;

    cout << "Enter a decimal number: ";
    cin >> input;

    while (input > 0 ) {
        base_two = 2;
        remainder = input % 2;

        for (int i = 0; i <= tracker; i++) {
            base_two = base_two*i;
        }

        total = base_two * remainder;

        input = input / 2;
        tracker++;

    }

    cout << total;
}