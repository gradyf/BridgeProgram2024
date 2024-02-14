//
// Created by Gray Forrester on 2/13/24.
//

void printShiftedTriangle(int n, int m, char symbol);

void printPineTree(int n, char symbol);

#include <iostream>
using namespace std;
int main() {
    printShiftedTriangle(3,4,'+');

    printShiftedTriangle(5,3,'#');
}



void printShiftedTriangle(int n, int m, char symbol) {

    int spaces = n-1;
    int symb_count = 1;

    //rows
    for (int rows = 0; rows < n; rows++) {

        for (int indent = 0; indent < m; indent++) {
            cout << " ";
        }

        for (int sp = 0; sp < spaces; sp++) {
            cout << " ";
        }

        for (int sy = 0; sy < symb_count; sy++) {
            cout << symbol;
        }

        cout << endl;
        symb_count += 2;
        spaces--;


    }

    }

void printPineTree(int n, char symbol) {
    return;
}