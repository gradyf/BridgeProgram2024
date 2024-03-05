//
// Created by Gray Forrester on 3/3/24.
//

#include <iostream>

using namespace std;

bool isLetter(char chr);

int main() {

    string input;

    cout << "Please enter a line of text: ";

    getline(cin, input);

    int beg_ind_tracker = 0;
    int end_ind_tracker;

    while (beg_ind_tracker < input.length()-1) {

        end_ind_tracker = input.find(" ",beg_ind_tracker);

        int length = end_ind_tracker - beg_ind_tracker;

        string subString = input.substr(beg_ind_tracker,length);

        bool skip = false;
        for (int x = 0; x < subString.length(); x++) {
            if(isLetter(subString[x])) {
                skip = true;
                break;
            }
        }
        if(!skip) {
            for (int y = 0; y < subString.length(); y++) {
                subString[y] = 'x';
            }

        }


        cout << subString << " ";


        if (end_ind_tracker == -1) {
            break;
        }

        beg_ind_tracker = end_ind_tracker + 1;

    }


}


bool isLetter(char chr) {
    if (chr != '1' && chr != '2' && chr != '3' && chr != '4' && chr != '5'
    && chr != '6' && chr != '7' &&  chr != '8' && chr != '9' && chr != '0') {
        return true;
    }
    else {
        return false;
    }
}