//
// Created by Gray Forrester on 3/3/24.
//

#include <iostream>

using namespace std;

int findNumber(string str);

int main() {

    string input;

    cout << "Please enter a line of text: ";

    getline(cin, input);

    while (findNumber(input) != -1) {
        input[findNumber(input)] = 'x';
    }

    cout << input;

}

int findNumber(string str) {
    if (str.find("1") != -1) {
        return str.find("1");
    }
    else if (str.find("2") != -1) {
        return str.find("2");
    }
    else if (str.find("3") != -1) {
        return str.find("3");
    }
    else if (str.find("4") != -1) {
        return str.find("4");
    }
    else if (str.find("5") != -1) {
        return str.find("5");
    }
    else if (str.find("6") != -1) {
        return str.find("6");
    }
    else if (str.find("7") != -1) {
        return str.find("7");
    }
    else if (str.find("8") != -1) {
        return str.find("8");
    }
    else if (str.find("9") != -1) {
        return str.find("9");
    }
    else if (str.find("10") != -1) {
        return str.find("10");
    }
    else {
        return -1;
    }
}

bool partOfWord (string str) {
    for (int x = 0; x < str.length(); x++) {
        if (x)

    }

}