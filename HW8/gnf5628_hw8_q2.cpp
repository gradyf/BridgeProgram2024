//
// Created by Gray Forrester on 3/2/24.
//

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str);

int main() {

    string input;

    cout << "Please enter a word: ";
    cin >> input;

    if(isPalindrome(input)) {
        cout << input << " is a palindrome";
    }
    else {
        cout << input << " not is a palindrome";
    }

}

bool isPalindrome(string str) {
    string str2 = "";
    for (int i = str.length() - 1; i >= 0 ; i--) {
        str2 += str[i];
    }

    if (str2 == str) {
        return true;
    }
    else{
        return false;
    }
}