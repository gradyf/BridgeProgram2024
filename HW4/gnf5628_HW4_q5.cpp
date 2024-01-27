//
// Created by Gray Forrester on 1/27/24.
//


#include <iostream>
using namespace std;

int main() {

    int left_A;
    int star;
    int right_B;

    int left_top_lines = 0;

    int length;

    cout << "Please enter a length: ";

    cin >> length;

    // top half of diamond
    for (int x = 0; x < length; x++){

        // left spaces
        for (int i = 0; i < left_top_lines; i++) {
            cout << "A";
        }

        // stars
        for (int i = 0; i < length; i++) {
            cout << "*";
        }

        // Right spaces
        for (int i = 0; i < length; i++) {
            cout << "B";
        }


        cout << endl;
        left_top_lines++;
    }

    // bottom half of diamond

    for (int x = 0; x < length; x++){
        for (int i = 0; i < length; i++) {
            cout << "*";
        }
        cout << endl;
    }

}