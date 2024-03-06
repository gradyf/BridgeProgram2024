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

    cout << endl << "-----SAMPLE ARRAYS------"  << endl;

    cout << endl << "Reversing =, Array 4: " << endl;
    int arr4[10] = {9, 2, 14, 12, -3, 8};
    int arr4Size = 6;

    printArray(arr4, arr4Size);
    reverseArray(arr4, arr4Size);
    printArray(arr4, arr4Size);

    cout << endl << "reversing, Array 5: " << endl;
    int arr5[10] = {9, 2, 14, 12, -3, 8,56};
    int arr5Size = 7;

    printArray(arr5, arr5Size);
    reverseArray(arr5, arr5Size);
    printArray(arr5, arr5Size);

    cout << endl << "removing: Array 6: " << endl;
    int arr6[10] = {9, 2, 14, 12, -3, 8,56};
    int arr6Size = 7;

    printArray(arr6, arr6Size);
    removeOdd(arr6, arr6Size);
    printArray(arr6, arr6Size);


    cout << endl << "removing: Array 7: " << endl;
    int arr7[10] = {9, 2, 7, 6, -3, 8,57};
    int arr7Size = 7;

    printArray(arr7, arr7Size);
    removeOdd(arr7, arr7Size);
    printArray(arr7, arr7Size);

    cout << endl << "removing: Array 8: " << endl;
    int arr8[10] = {2, 9, 9, 9, -9, 8,57};
    int arr8Size = 7;

    printArray(arr8, arr8Size);
    removeOdd(arr8, arr8Size);
    printArray(arr8, arr8Size);


    cout << endl << "Split: Array 8: " << endl;
    int arr9[10] = {6, 9, 4, 13, -10, 1,57};
    int arr9Size = 7;

    printArray(arr9, arr9Size);
    splitParity(arr9, arr9Size);
    printArray(arr9, arr9Size);



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


