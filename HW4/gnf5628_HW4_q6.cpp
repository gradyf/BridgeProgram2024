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
        cout << counter << endl;
        counter++;
    }


}