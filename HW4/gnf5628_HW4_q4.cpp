//
// Created by Gray Forrester on 1/24/24.
//
#include <iostream>
#include <cmath>
using namespace std;

int main() {

    cout << "section a" << endl;


    int temp_total = 0;

    double total, length, power;

    cout << "Please enter the length of the sequence: ";
    cin >> length;

    cout << "Please enter the sequence: " << endl;

    for (int i = 0; i < length; i++) {
        int temp = 0;
        cin >> temp;

        temp_total += temp;
    }

    power = (1/length);

    total = pow(temp_total,power);

    cout << "The geometric mean is: " << total;


}