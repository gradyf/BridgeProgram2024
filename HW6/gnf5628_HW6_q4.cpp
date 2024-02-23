//
// Created by Gray Forrester on 2/16/24.
//
#include <iostream>
#include <cmath>
using namespace std;

void printDivisors(int num);

int main() {

    int input;

    cout << "Please enter a positive integer >= 2: ";
    cin >> input;

    printDivisors(input);

}

void printDivisors(int num) {

    for(int x = 1; x <= sqrt((double) num); x++){
        if (num % x == 0) {
            cout << x << " ";
        }
    }
    for(int x = sqrt((double) num) - 1; x >= 1; x--){

        if (num % x == 0) {
            cout << num / x << " ";
        }
    }

}