#include <iostream>
using namespace std;
// Created by Gray Forrester on 1/10/24.
//

/*
Question 4:
Write a program that reads from the user two positive integers, and prints the result of when we add, subtract multiply, divide, div and mod them.
Your program should interact with the user exactly as it shows in the following example:

 Please enter two positive integers, separated by a space:
14 4

14+4=18
14–4=10
 4*4=56
 14/4=3.5
 14div4=3
 14mod4=2
 */

int main() {
    int x, y;

    cout << "Please enter two positive integers, separated by a space:" << endl;

    cin >> x;
    cin >> y;

    cout << x << " + " << y << " = " << (x + y) << endl;
    cout << x << " - " << y << " = " << (x - y) << endl;
    cout << x << " * " << y << " = " << (x * y) << endl;
    cout << x << " / " << y << " = " << ((double) x / (double) y) << endl;
    cout << x << " div " << y << " = " << (x / y) << endl;
    cout << x << " mod " << y << " = " << ( x % y) << endl;

}
