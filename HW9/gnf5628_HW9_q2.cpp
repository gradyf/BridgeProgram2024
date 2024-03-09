//
// Created by Gray Forrester on 3/8/24.
//

#include <iostream>
#include <string>

using namespace std;

bool isLetter(char character);
bool equalArray(int arr1[], int arr2[], int arrSize);
int letterToIndice(char letter);
void fillArrayZeros(int arr[], int arrSize);
void countLetters(string str, int arr[]);

int main() {

    int arrSize = 26;

    int arr1[26];
    int arr2[26];

    fillArrayZeros(arr1,26);
    fillArrayZeros(arr2,26);

    string str1;
    string str2;

    cout << "Please enter the first string: " << endl;
    getline(cin,str1);

    cout << "Please enter the second string: " << endl;
    getline(cin,str2);

    countLetters(str1,arr1);
    countLetters(str2,arr2);

    if(equalArray(arr1, arr2, arrSize)) {
        cout << "These strings are anagrams!";
    }
    else {
        cout << "These strings are NOT anagrams :(";
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

bool equalArray(int arr1[], int arr2[], int arrSize) {
    bool equal = true;

    for (int x = 0; x < arrSize; x++) {
        if (arr1[x] != arr2[x]) {
            equal = false;
            break;
        }
    }

    return equal;
}