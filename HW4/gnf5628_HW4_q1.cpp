#include <iostream>
using namespace std;
// Created by Gray Forrester on 1/22/24.
//
int main() {

    cout << "section a" << endl;

    int counter_a= 1, tracker_a = 0, total_a;

    cout << "Please enter a positive integer: ";
    cin >> total_a;

    while (tracker_a < total_a) {
        if (counter_a % 2 == 0) {
            cout << counter_a << endl;
            tracker_a++;
        }
        counter_a++;
    }

    cout << "section b" << endl;

    int tracker_b = 0, total_b;

    cout << "Please enter a positive integer: ";
    cin >> total_b;

    for (int counter_b = 1; tracker_b < total_b; counter_b++) {
        if (counter_b % 2 == 0) {
            cout << counter_b << endl;
            tracker_b++;
        }
    }



}