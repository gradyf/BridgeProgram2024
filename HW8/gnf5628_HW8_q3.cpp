//
// Created by Gray Forrester on 3/2/24.
//

#include <iostream>

void reverseArray(int arr[], int arrSize);
void printArray(int arr[], int arrSize);
void removeOdd(int arr[], int& arrSize);
void splitParity(int arr[], int arrSize);

using namespace std;
int main() {

    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;
    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;
    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;

    cout << "Reversing Array 1: "  << endl;
    printArray(arr1, arr1Size);
    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);


    cout << endl << "Removing odds, Array 2: "  << endl;
    printArray(arr2, arr2Size);
    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);

    cout << endl << "Split Parity, Array 3: "  << endl;
    printArray(arr3, arr3Size);
    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);


    return 0;
}

void printArray(int arr[], int arrSize){
    int i;
    for (i = 0; i < arrSize; i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

void reverseArray(int arr[], int arrSize) {

    int swap = arrSize - 1;

    for (int x = 0; x <= (arrSize / 2 - 1); x++) {
        int temp1 = arr[x];
        int temp2 = arr[swap];

        arr[x] = temp2;
        arr[swap] = temp1;
        swap--;
    }

}

void removeOdd(int arr[], int& arrSize) {
    int ind = 0;
    for(int x = 0; x < arrSize; x++) {
        if (arr[x] % 2 == 0) {
            arr[ind] = arr[x];
            ind++;
        }
    }
    arrSize = ind;
}

void splitParity(int arr[], int arrSize) {
    int left = 0;
    int right = arrSize - 1;
    int temp;

    while(left < right) {
        if (arr[left] % 2 != 0) {
            left++;
        }
        else if (arr[right] % 2 == 0) {
            right--;
        }

        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
    }

}


