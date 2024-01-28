//
// Created by Gray Forrester on 1/24/24.
//
#include <iostream>

using namespace std;

const int POWER2_0 =  1;

int main () {

    int input;

    int input_Temp_1;
    int input_Temp_2;

    int tracker = 0;

    cout << "Enter a decimal number: ";
    cin >> input;

    input_Temp_1 = input;
    input_Temp_2 = input;


    while (input_Temp_1 > 0 ) {

        input_Temp_1 = input_Temp_1 / 2;
        tracker++;

    }

    int counter = tracker-1;

    for (int x = tracker; x > 0; x--) {
        int temp = 1;

        for (int y = 0; y < counter; y++) {
            temp = temp * 2;
        }

        if (input_Temp_2 - temp >= 0) {
            cout << "1";
            input_Temp_2 -= temp;
        }
        else {
            cout << "0";
        }
        counter--;

    }
}

//The binary representation of 76 is 1001100
//                                   0011001