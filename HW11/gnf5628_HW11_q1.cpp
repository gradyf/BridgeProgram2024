//
// Created by Gray Forrester on 3/22/24.
//
#include <iostream>

using namespace std;

void printTriangle(int n);
void printOppositeTriangles(int n);


int main() {

    printTriangle(4);

    cout << endl;

    printTriangle(10);
}

void printTriangle(int n ) {


    if (n == 1 ) {
        cout << "*";
    }
    else {

        for (int x = 0; x < n; x++) {
            cout << "*";
        }
        cout << endl;

        printTriangle(n - 1);
    }

}

void printOppositeTriangles(int n) {

    if (n > 0 ) {
        for (int x = 0; x < n; x++) {
            cout << "*";
        }
        cout << endl;

        printTriangle(n - 1);
    }

}