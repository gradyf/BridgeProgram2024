#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

void printArray (string str, int arr[]);
string intToString (int num);

const string PIN_NUMBER = "00001";

int main() {

    string guess, correct_PIN = "";
//    string str_PIN = intToString(PIN_NUMBER);

    srand(time(0));

    int num[] = {rand()%5+1,rand()%5+1,rand()%5+1,
                 rand()%5+1,rand()%5+1,rand()%5+1
                 ,rand()%5+1,rand()%5+1,rand()%5+1,rand()%5+1};

    int pin[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    printArray("PIN", pin);

    cout << endl;

    printArray("NUM", num);

    cout << endl;
    cin >> guess;

    for (int x = 0; x < 5; x++) {
        int temp =  PIN_NUMBER[x] - '0';

        int temp2 = num[temp];

        correct_PIN += to_string(temp2);
    }

    if (correct_PIN == guess) {
        cout << "Your PIN is correct" << endl;
        cout << "The correct pin is: " << correct_PIN << " and your entered: " << guess;
    }
    else {
        cout << "Your PIN is not correct"<< endl;
        cout << "The correct pin is: " << correct_PIN << " and your entered: " << guess;
    }

    return 0;
}

void printArray (string str, int arr[]) {

    cout << str << ": ";
    for (int x = 0; x < 10; x++) {
        cout << arr[x] << " ";
    }

}

string intToString (int num) {

    if (num == 00000) {
        return "00000";
    }

    int temp_num = num;

    string str_num = "", temp_str = "";

    while(temp_num > 0) {
        temp_str += to_string(temp_num % 10);
        temp_num /= 10;
    }

    for (int x = temp_str.length() - 1; x >= 0; x--) {
        str_num += temp_str[x];
    }

    return str_num;

}


