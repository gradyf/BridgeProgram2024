#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void printArray (string str, int arr[]);

const int PIN_NUMBER = 34512;

int main() {

    string guess, correct_PIN = "";
    int temp_guess;

    srand(time(0));

    int num[] = {rand()%5+1,rand()%5+1,rand()%5+1,
                 rand()%5+1,rand()%5+1,rand()%5+1
                 ,rand()%5+1,rand()%5+1,rand()%5+1,rand()%5+1};

    int pin[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};


    cout << "Please enter your PIN according to the following mapping:" << endl;

    printArray("PIN", pin);

    cout << endl;

    printArray("NUM", num);

    cout << endl;
    cin >> guess;


    for (int x = 1; x <= 5; x++) {
        correct_PIN += to_string(num[pin[x]]);
    }

    if (correct_PIN == guess) {
        cout << "Your PIN is correct";
    }
    else {
        cout << "Your PIN is not correct";
    }

    return 0;
}

void printArray (string str, int arr[]) {

    cout << str << ": ";
    for (int x = 0; x < 10; x++) {
        cout << arr[x] << " ";
    }

}


