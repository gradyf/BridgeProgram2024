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

    int output = 1;

    for (int x = 0; x < n; x++) {
        output += output;
    }
    return output;
}