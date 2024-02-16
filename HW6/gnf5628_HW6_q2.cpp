//
// Created by Gray Forrester on 2/13/24.
//

void printShiftedTriangle(int n, int m, char symbol);

void printPineTree(int n, char symbol);

#include <iostream>
using namespace std;
int main() {

    int size, offset;
    char symbol;
    cout << "Please enter a size, offset, and symbol seperated by a enter: " << endl;

    cin >> size
        >> offset
        >> symbol;

    printShiftedTriangle(size, offset, symbol);

    cout << "Please enter a size and symbol seperated by a enter: " << endl;

    cin >> size
        >> symbol;

    printPineTree(size, symbol);

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

    int temp_tree_size = 2, temp_tree_offset = n-1;

    //outer loop that sets the number of "levels" of the tree
    for (int level = 0; level < n; level++){
        printShiftedTriangle(temp_tree_size,temp_tree_offset, symbol);
        temp_tree_size++;
        temp_tree_offset--;
    }

}