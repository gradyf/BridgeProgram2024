//
// Created by Gray Forrester on 2/13/24.
//
#include <iostream>
using namespace std;

int fib(int n);
//function declaration of inputing a number and returning the n-th sequence
// of the fibanci sequence

int main() {

    int input;

    cout << "Please enter a positive integer: ";
    cin >> input;

    cout << fib(input);

    return 0;
}

int fib(int n) {

    int output = 0;
    int back_one = 0;
    int back_two = 0;

    for (int x = 0; x < n; x++) {

        if (x == 0) {
           output = 1;
        }
        else if (x == 1) {
            output = 1;
            back_one = 1;
        }
        else {
            back_two = back_one;
            back_one = output;
            output = back_one + back_two;

        }

    }
    return output;
}