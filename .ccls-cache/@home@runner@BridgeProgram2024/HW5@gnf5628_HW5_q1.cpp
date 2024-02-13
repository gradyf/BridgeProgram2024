
#include <iostream>
using namespace std;


// Updated from replit


int main() {

    int input;

    cout << "Please enter a positive integer: ";
    cin >> input;

    for (int row = 1; row <= input; row++) {
        for (int col =1; col <= input; col++) {
            cout << row * col << "\t";
        }

        cout << endl;
    }

}