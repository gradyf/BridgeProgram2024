//
// Created by Gray Forrester on 1/24/24.
//
#include <iostream>

using namespace std;

int main () {

    int input, total=0;

    int tracker = 0;

    cout << "Enter a decimal number: ";
    cin >> input;

    while (input > 0 ) {

        cout << input % 2;

        input = input / 2;
        tracker++;


    }

    cout << "tracker is: " << tracker << endl;


    while (tracker >= 0) {
        int temp_base_2 = 0;

        for (int x = tracker - 1; x >= 0; x-- )
            temp_base_2 = temp_base_2 * 2;

        cout << "Base 2: " << temp_base_2 << endl;
        tracker--;
    }
}

//The binary representation of 76 is 1001100
//                                   0011001