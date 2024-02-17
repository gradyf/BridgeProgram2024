//
// Created by Gray Forrester on 2/16/24.
//
#include <iostream>
#include <cmath>
using namespace std;

void printDivisors(int num);

int main() {

    double input;

    cout << "Please enter a positive integer >= 2: ";
    cin >> input;

    printDivisors(input);

}

void printDivisors(int num) {

    for(int x = 1; x <= num; x++){
        if (num % x == 0) {
            cout << x << " ";
        }
    }

}