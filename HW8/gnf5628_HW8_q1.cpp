//
// Created by Gray Forrester on 3/2/24.
//

#include <iostream>
using namespace std;

int minInArray(int arr[], int arrSize);
void fillArray(int arr[], int arraySize);
void printIndices(int arr[], int arraySize, int target);

int main() {

    const int arraySize = 20;

    int input[arraySize];

    fillArray(input,arraySize);

    int minimum = minInArray(input, arraySize);


    cout << "The minimum value is " << minimum
    << ", and it is located at the following indices: ";

    printIndices(input,arraySize, minimum);



}

int minInArray(int arr[], int arraySize) {

    int min = arr[0];

    for (int x = 0; x < arraySize; x++) {
        if(arr[x] < min) {
            min = arr[x];
        }
    }

    return min;

}

void fillArray(int arr[], int arraySize){
    cout << "Please enter " << arraySize << " integers seperated by a space: " << endl;
    for (int x = 0; x < arraySize; x+= 1) {
        cin >> arr[x];
    }

}

void printIndices(int arr[], int arraySize, int target){
    for (int x = 0; x < arraySize; x++){
        if (arr[x] == target) {
            cout << x << " ";
        }

    }
}