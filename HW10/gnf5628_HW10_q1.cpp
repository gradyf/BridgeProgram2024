//
// Created by Gray Forrester on 3/16/24.
//
#include <iostream>
#include <string>
using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);
bool isLetter(char character);

int main() {
    int outWordsArrSize = 0;

    string sentence;

    cout << "Please enter a line of text: ";

    getline(cin, sentence);

    string* strArr = createWordsArray(sentence, outWordsArrSize);

    cout << "outWordsArrSize: " << outWordsArrSize << endl;

    cout << "Sentence: " << sentence << endl;

    cout << "Sentence Array: " << endl;

    cout << "[";
    for (int x = 0; x < outWordsArrSize; x++) {
        if (x == outWordsArrSize - 1) {
            cout << "\"" << strArr[x] << "\"";
        }
        else {
            cout << "\"" << strArr[x] << "\",";
        }
    }
    cout << "]";

    delete[] strArr;


}

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

string* createWordsArray(string sentence, int& outWordsArrSize) {

    // counting the number of words
    for (int x = 1; x < sentence.length(); x++) {

        if ((x == sentence.length()-1) && (isLetter(sentence[x]))) {
            outWordsArrSize++;
        }

        else if((!isLetter(sentence[x]) && (isLetter(sentence[x-1])))){

            outWordsArrSize++;
        }

    }

    //creating an array for the strings
    string* strarr = new string[outWordsArrSize];

    int index = 0;

    int beg_ind_tracker = 0;
    int end_ind_tracker;

    while (beg_ind_tracker < sentence.length()-1) {

        end_ind_tracker = sentence.find(" ",beg_ind_tracker);

        int length = end_ind_tracker - beg_ind_tracker;

        string subString = sentence.substr(beg_ind_tracker,length);

        strarr[index] = subString;

        if (end_ind_tracker == -1) {
            break;
        }

        beg_ind_tracker = end_ind_tracker + 1;
        index++;

    }

    return strarr;
}