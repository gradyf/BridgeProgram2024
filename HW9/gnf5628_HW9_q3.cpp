//
// Created by Gray Forrester on 3/9/24.
//

#include <iostream>

using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);

void getPosNums3(int* arr, int arrSize,
                 int*& outPosArr, int& outPosArrSize);

void getPosNums4(int* arr, int arrSize,
                 int** outPosArrPtr, int* outPosArrSizePtr);

int main() {


    cout << "---------------Function1 Test--------------" << endl;
    int outPosArr1Size = 0;
    int arr1InputSize = 10;

    int arr1input[] = {3,-1,-3,0,6,4, 10, 20, -8, 1};

    cout << "Old Array: ";
    for (int x = 0; x < arr1InputSize; x++) {
        cout << arr1input[x] << " ";
    }

    cout << endl;


    int* arr1Test = getPosNums1(arr1input,arr1InputSize,outPosArr1Size);

    cout << "New Array: ";
    for (int x = 0; x < outPosArr1Size; x++) {
        cout << arr1Test[x] << " ";
    }

    delete [] arr1Test;


    cout << endl << "---------------Function2 Test--------------" << endl;

    int outPosArr2Size = 0;
    int arr2InputSize = 10;

    int *outPosArr2SizePtr = &outPosArr2Size;


    int arr2input[] = {-8,-2,15,3,9,-7, 0, 0, 3, 1};


    cout << "Old Array: ";
    for (int x = 0; x < arr2InputSize; x++) {
        cout << arr2input[x] << " ";
    }

    cout << endl;

    int* arr2Test = getPosNums2(arr2input, arr2InputSize, outPosArr2SizePtr);


    cout << "New Array: ";
    for (int x = 0; x < outPosArr2Size; x++) {
        cout << arr2Test[x] << " ";
    }

    delete [] arr2Test;

    cout << endl << "---------------Function3 Test--------------" << endl;

    int outPosArr3Size = 0;
    int arr3InputSize = 15;

    int arr3input[] = {-7,2,67,-19,0,0, 0, 0, 3, 5, 6, 7, 0, 15, -25};

    int arr3Test[] = {10,9,8,7,6};

    int* outPos3Arr = arr3Test;


    cout << endl << "outPosArr3Size: " << outPosArr3Size << endl;

    cout << "Old Array: ";
    for (int x = 0; x < arr3InputSize; x++) {
        cout << arr3input[x] << " ";
    }

    cout << endl;

    getPosNums3(arr3input, arr3InputSize, outPos3Arr, outPosArr3Size);

    arr3Test = *outPos3Arr;

    cout << endl << "outPosArr3Size: " << outPosArr3Size << endl;

    cout << "New Array: ";
    for (int x = 0; x < outPosArr3Size; x++) {
        cout << arr3Test[x] << " ";
    }

//    delete [] arr3Test;

}


/**returns the base address of the array
(containing the positive numbers),
and updates the output parameter
 outPosArrSize with the array’s logical size.

 @param arr
 @param arrSize
 @param outPosArrSizePtr
*/
 int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {

     // determine how large the new size needs to be
     for (int x = 0; x < arrSize; x++) {
         if (arr[x] > 0) {
             outPosArrSize++;
         }
     }

     //define the pointer //create new array based on the new size
     int* arr1 = new int [outPosArrSize];

     //create a index tracker for the new array to be used to fill the new array
     int indTracker = 0;

    //Fills the  new array with the positive values:
    for (int x = 0; x < arrSize; x++) {
        if (arr[x] > 0) {
            arr1[indTracker] = arr[x];
            indTracker++;
        }
    }

    return arr1;
}

/**
 returns the base address of the array
 (containing the positive numbers),
 and uses the pointer outPosArrSizePtr
 to update the array’s logical size

 @param arr
 @param arrSize
 @param outPosArrSizePtr
*/

 int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr) {
    // determine how large the new size needs to be
    int temp = 0;
    for (int x = 0; x < arrSize; x++) {
        if (arr[x] > 0) {
            temp++;
        }
    }


    *outPosArrSizePtr = temp;


    //define the pointer //create new array based on the new size
    int* arr2 = new int [*outPosArrSizePtr];

    //create a index tracker for the new array to be used to fill the new array
    int indTracker = 0;

    //Fills the  new array with the positive values:
    for (int x = 0; x < arrSize; x++) {
        if (arr[x] > 0) {
            arr2[indTracker] = arr[x];
            indTracker++;
        }
    }

    return arr2;

}

/**   updates the output parameter outPosArr
    with the base address of the array
    (containing the positive numbers),
    and the output parameter outPosArrSize
    with the array’s logical size.

    @param arr
    @param arrSize
    @param outPosArr
    @param outPosArrSize
    */
void getPosNums3(int* arr, int arrSize, int* &outPosArr, int &outPosArrSize) {

    // determine how large the new size needs to be
    int temp = 0;
    for (int x = 0; x < arrSize; x++) {
        if (arr[x] > 0) {
            temp++;
        }
    }

    outPosArrSize = temp;

    //define the pointer //create new array based on the new size
    int* arr3 = new int [outPosArrSize];

    //create a index tracker for the new array to be used to fill the new array
    int indTracker = 0;

    //Fills the  new array with the positive values:
    for (int x = 0; x < arrSize; x++) {
        if (arr[x] > 0) {
            arr3[indTracker] = arr[x];
            indTracker++;
        }
    }

    outPosArr = arr3;

}

/**
 *
 * @brief uses the pointer outPosArrPtr to update the
 * base address of the array (containing the positive numbers),
 * and the pointer outPosArrSizePtr to update the array’s logical size.
 *
 * @param arr
 * @param arrSize
 * @param outPosArrPtr
 * @param outPosArrSizePtr
 */

void getPosNums4(int* arr, int arrSize,
                 int** outPosArrPtr, int* outPosArrSizePtr) {


}