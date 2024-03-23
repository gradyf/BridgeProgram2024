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

    printTriangle(4);
}

void printTriangle(int n) {

    if (n == 1 ) {

        cout << "*" << endl;
        return;
    }

    else {
        printTriangle(n-1);
        for (int x = 0; x < n; x++) {
            cout << "*";
        }
        cout<< endl;
    }


}

void printOppositeTriangles(int n) {

    if (n == 1 ) {
        cout << "*";
        return;
    }
    else {

        for (int x = 0; x < n; x++) {
            cout << "*";
        }
        cout << endl;

        printTriangle(n - 1);
    }


    else {
        printTriangle(n-1);
        for (int x = 0; x < n; x++) {
            cout << "*";
        }
        cout<< endl;
    }



}