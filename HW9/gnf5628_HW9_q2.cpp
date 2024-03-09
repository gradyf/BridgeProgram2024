//
// Created by Gray Forrester on 3/8/24.
//

#include <iostream>

using namespace std;

bool isLetter(char character);

int letterToIndice(char letter);

int main() {

   return 0;
}

// Takes a character and compares it against the
// ASCII values to determine if it is a letter or not
// Inputs: a character
// outputs: a boolean True / false if it's in a out
bool isLetter(char character) {

    //if statement checking if the character is between upper case ASCII values
    if((int) character >= 65 && character <= 90){
        return true;
    }
    // else if statement checking if the character is between lowercase ASCII values
    else if ((int) character >= 97 && character <= 122) {
        return true;
    }
    // if it's not any of the above, return False
    else {
        return false;
    }
}

int letterToIndice(char letter) {

    // returns how far away from 'A' the letter is which will be used as the indice in the array
    if((int) letter >= 65 && letter <= 90){
        return int (letter) - 65;
    }

    // returns how far away from 'a' the letter is which will be used as the indice in the array
    else {
        return int (letter) - 97;
    }

}