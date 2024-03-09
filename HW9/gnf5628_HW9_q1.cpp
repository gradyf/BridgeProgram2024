//
// Created by Gray Forrester on 3/8/24.
//

#include <iostream>
#include <string>

using namespace std;

bool isLetter(char character);
int countWords (string str1);
int letterToIndice(char letter);
void fillArrayZeros(int arr[], int arrSize);
void countLetters(string str, int arr[]);

int main() {

    int arrSize = 26;

    int letterArr[arrSize];
    char charArr[] = {'a','b','c','d','e','f','g','h','i'
                     ,'j','k','l','m','n','o','p','q'
                     ,'r','s','t','u','v','w','x','y','z'};

    fillArrayZeros(letterArr,arrSize);

    string input;

    cout << "Please enter a line of text: ";

    getline(cin, input);

    cout << countWords(input) << "\t" << "words";

    countLetters(input, letterArr);

    cout << endl;
    for (int x = 0; x < 26; x++) {

        if(letterArr[x] > 0) {
            cout << letterArr[x] << "\t" << charArr[x] << endl;
        }
    }

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

int countWords(string str1) {
    int words = 0;

    for (int x = 1; x < str1.length(); x++) {

        if ((x == str1.length()-1) && (isLetter(str1[x]))) {
            words++;
        }

        else if((!isLetter(str1[x]) && (isLetter(str1[x-1])))){

            words++;
        }

    }

    return words;
};

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

void fillArrayZeros(int arr[], int arrSize) {
    for (int x = 0; x < arrSize; x++) {
        arr[x] = 0;
    }
}

void countLetters(string str, int arr[]) {

    for (int x = 0; x < str.length(); x++) {
        if (isLetter(str[x])) {
            arr[letterToIndice(str[x])] += 1;
        }
    }
}
