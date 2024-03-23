//
// Created by Gray Forrester on 3/19/24.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void searchVect(vector<int> &vect, int search);
void expandArray(int** arr, int &arrSize, int input);
void searchArray(int arr[], int arrSize, int search);
void main2();
void main1();

int main(){

    main1();

    cout << endl;

    main2();

    return 0;
}

void searchVect(vector<int> &vect, int search) {
    vector<int> output;
    bool inList = false;

    for (int x = 0; x < vect.size(); x++) {
        if (vect[x] == search) {
            output.push_back(x);
        }
    }

    for (int x = 0; x < vect.size(); x++) {
        if (vect[x] == search) {
            inList = true;
        }
    }

    if (inList) {
        cout << search << " shows in lines ";
        for (int x = 0; x < output.size(); x++) {
            if (x == output.size() - 1) {
                cout << output[x] + 1 << ".";
            } else {
                cout << output[x] + 1 << ", ";
            }
        }
    }
    else{
        cout << search << " is not in the list.";
    }

}

void main1(){
    int input, search;

    vector<int> numVect;

    cout << "Vector Search: Please enter a sequence of positive integers, each in a separate line.";
    cout << endl << "End your input by typing -1." << endl;

    while (true) {
        cin >> input;

        if (input < 0) {
            break;
        }

        numVect.push_back(input);

    }

    cout << "Vector Search: Please enter a number you want to search." << endl;
    cin >> search;

    searchVect(numVect, search);

}

void expandArray(int** arr, int &arrSize, int input) {

    int* arrTemp = new int [arrSize + 1];

    for (int x = 0; x < arrSize; x++) {
        arrTemp[x] = (*arr)[x];
    }

    arrTemp[arrSize] = input;
    arrSize++;

    delete [] *arr;
    *arr = arrTemp;

}

void searchArray(int arr[], int arrSize, int search) {
    int output[arrSize];
    bool inList = false;
    int index = 0;

    for (int x = 0; x < arrSize; x++) {
        if (arr[x] == search) {
            output[index] = x;
            index++;
            inList = true;
        }
    }

    if (inList) {
        cout << search << " shows in lines ";
        for (int x = 0; x < index; x++) {

            if (x == index - 1) {
                cout << output[x] + 1 << ".";
            } else {
                cout << output[x] + 1 << ", ";
            }
        }
    }
    else{
        cout << search << " is not in the list.";
    }


}

void main2() {
    int input, search, arrSize = 0;


    int* numArr = new int[arrSize];

    cout << "Array Search: Please enter a sequence of positive integers, each in a separate line.";
    cout << endl << "End your input by typing -1." << endl;

    while (true) {
        cin >> input;

        if (input < 0) {
            break;
        }

        expandArray(&numArr, arrSize, input);

    }

    cout << "Array Search: Please enter a number you want to search." << endl;
    cin >> search;

    searchArray(numArr, arrSize, search);

}


