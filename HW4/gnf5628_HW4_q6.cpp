//
// Created by Gray Forrester on 1/27/24.
//
#include <iostream>
using namespace std;

int main() {

    int length;
    int counter = 1;

    cout << "Please enter a positive integer: ";

    cin >> length;

    while (counter <= length) {
        int temp = counter;
        int even_count = 0;
        int odd_count = 0;

        while (temp > 0) {
            if ((temp % 10) % 2 == 0) {
                even_count++;
            }
            else {
                odd_count++;
            }
            temp = temp / 10;
        }

        if (even_count > odd_count) {
            cout << counter << endl;
        }
        counter++;
    }
}