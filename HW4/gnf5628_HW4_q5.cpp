//
// Created by Gray Forrester on 1/27/24.
//


#include <iostream>
using namespace std;

int main() {



    int top_spaces_lines = 0;
    int top_stars_lines;

    int bottom_spaces_lines;
    int bottom_stars_length =0;

    int length;

    cout << "Please enter a length: ";

    cin >> length;

    top_stars_lines = 2*length - 1;

    bottom_spaces_lines = length-1;



    // top half of diamond
    for (int x = 0; x < length; x++){

        // left spaces
        for (int i = 0; i < top_spaces_lines; i++) {
            cout << " ";
        }

        // stars
        for (int i = top_stars_lines; i > 0; i--) {
            cout << "*";
        }

        // Right spaces
        for (int i = 0; i < top_spaces_lines; i++) {
            cout << " ";
        }

        // end of line transition
        cout << endl;
        top_spaces_lines++;
        top_stars_lines -= 2;
    }

    // bottom half of diamond

    for (int x = 0; x < length; x++){

        // Left Spaces
        for (int i = bottom_spaces_lines; i > 0; i--) {
            cout << " ";
        }

        // Stars
        for (int i = 0; i <= bottom_stars_length; i++) {
            cout << "*";
        }

        // right spaces
        for (int i = bottom_spaces_lines; i > 0; i--) {
            cout << " ";
        }

        // end of line transition
        cout << endl;
        bottom_spaces_lines--;
        bottom_stars_length += 2;
    }

}