//
// Created by Gray Forrester on 1/24/24.
//
#include <iostream>
#include <cmath>
using namespace std;

int main() {

    cout << "section a" << endl;


    int temp_total_a= 0;

    double total_a, length_a, power_a;

    cout << "Please enter the length of the sequence: ";
    cin >> length_a;

    cout << "Please enter the sequence: " << endl;

    for (int i = 0; i < length_a; i++) {
        int temp = 0;
        cin >> temp;

        temp_total_a += temp;
    }

    power_a = (1 / length_a);

    total_a = pow(temp_total_a, power_a);

    cout << "The geometric mean is: " << total_a << endl;


    cout << "section b" << endl;



    cout << "Please enter a non-empty sequence of positive integers, each one in a separate line. End your\n"
            "sequence by typing -1:" << endl;

    int trigger_b = 0;

    int temp_total_b = 0;

    double total_b = 0, length_b = 0, power_b = 0;


    while (trigger_b != -1) {
        int temp_b;

        cin >> temp_b;

        if ( temp_b == -1) {
            length_b--;
            trigger_b = -1;
        }
        else {
            temp_total_b += temp_b;
        }

        length_b++;
    }
    cout << temp_total_b;

    power_b = (1 / length_b);

    total_b = pow(temp_total_b, power_b);

    cout << "The geometric mean is: " << total_b << endl;


}