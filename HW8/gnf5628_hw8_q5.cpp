//
// Created by Gray Forrester on 3/3/24.
//
#include <iostream>

using namespace std;

int main() {
    string first, middle, last;

    cout << "Please enter a first name, middle name, and last name seperated by a space: " << endl;

    cin >> first >> middle >> last;

    cout << last <<  ", " << first << " " << middle[0] << ".";
}