//
// Created by Gray Forrester on 3/22/24.
//
#include <iostream>

using namespace std;

void printTriangle(int n);
void printOppositeTriangles(int n);
void printRuler (int n);


int main() {

    printTriangle(4);

    cout << endl;

    printOppositeTriangles(4);

    cout << endl;

    printTriangle(5);

    cout << endl;

    printOppositeTriangles(5);

    cout << endl;

    printRuler(4);
    cout << endl;

    printRuler(3);

}

// complete
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
// complete
void printOppositeTriangles(int n) {
    if (n == 1 ) {
        cout << "*" << endl << "*" << endl;
    }

    else {


        for (int x = 0; x < n; x++) {
            cout << "*";
        }
        cout << endl;

        printOppositeTriangles(n - 1);

        for (int x = 0; x < n; x++) {
            cout << "*";
        }
        cout << endl;
    }



}
//complete
void printRuler (int n) {
    if( n == 1) {
        cout << "-";
        cout << endl;
    }
    else {
        printRuler (n - 1);
        for (int x = 0; x < n; x++) {
            cout << "-";
        }
        cout << endl;
        printRuler (n - 1);

    }



}