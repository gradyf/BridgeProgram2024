

#include <iostream>

using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);
void fillArray(int arr[], int n);

int main() {

    cout << "----------TEST 1-----------" << endl;

    int arr1Size = 6, resArr1Size = 0;

    int arr1[] = {3, 1, 3, 0, 6, 4};

    int* missNums1 = findMissing(arr1, arr1Size, resArr1Size);

    cout << "Array:" << endl;
    for (int x = 0; x < arr1Size; x++) {
        cout << arr1[x] << " ";
    }

    cout << endl<< "Missing Numbers:" << endl;
    for (int x = 0; x < resArr1Size; x++) {
        cout << missNums1[x] << " ";
    }

    cout << endl << "resArr1Size= " << resArr1Size;

    //delete the created array from findMissing
    delete [] missNums1;

    cout << endl<< "----------TEST 2-----------" << endl;

    int arr2Size = 10, resArr2Size = 0;

    int arr2[] = {0, 9, 9, 1, 0, 9,0, 0, 0, 0};

    int* missNums2 = findMissing(arr2, arr2Size, resArr2Size);

    cout << "Array:" << endl;
    for (int x = 0; x < arr2Size; x++) {
        cout << arr2[x] << " ";
    }

    cout << endl << "Missing Numbers:" << endl;
    for (int x = 0; x < resArr2Size; x++) {
        cout << missNums2[x] << " ";
    }

    cout << endl << "resArr2Size= " << resArr2Size;

    //delete the created array from findMissing
    delete [] missNums2;

    cout << endl<< "----------TEST 3-----------" << endl;

    int arr3Size = 10, resArr3Size = 0;

    int arr3[] = {0, 1, 2, 3, 4, 5,6, 7, 8, 9};

    int* missNums3 = findMissing(arr3, arr3Size, resArr3Size);

    cout << "Array:" << endl;
    for (int x = 0; x < arr3Size; x++) {
        cout << arr3[x] << " ";
    }

    cout << endl << "Missing Numbers:" << endl;
    for (int x = 0; x < resArr3Size; x++) {
        cout << missNums3[x] << " ";
    }

    cout << endl << "resArr3Size= " << resArr3Size;

    //delete the created array from findMissing
    delete [] missNums3;

    cout << endl<< "----------TEST 4-----------" << endl;

    int arr4Size = 5, resArr4Size = 0;

    int arr4[] = {0, 0, 0, 0, 0};

    int* missNums4 = findMissing(arr4, arr4Size, resArr4Size);

    cout << "Array:" << endl;
    for (int x = 0; x < arr4Size; x++) {
        cout << arr4[x] << " ";
    }

    cout << endl << "Missing Numbers:" << endl;
    for (int x = 0; x < resArr4Size; x++) {
        cout << missNums4[x] << " ";
    }

    cout << endl << "resArr4Size= " << resArr4Size;

    //delete the created array from findMissing
    delete [] missNums4;

    cout << endl<< "----------TEST 5-----------" << endl;

    int arr5Size = 5, resArr5Size = 0;

    int arr5[] = {5, 5, 5, 5, 5};

    int* missNums5 = findMissing(arr5, arr5Size, resArr5Size);

    cout << "Array:" << endl;
    for (int x = 0; x < arr5Size; x++) {
        cout << arr5[x] << " ";
    }

    cout << endl << "Missing Numbers:" << endl;
    for (int x = 0; x < resArr5Size; x++) {
        cout << missNums5[x] << " ";
    }

    cout << endl << "resArr5Size= " << resArr5Size;

    //delete the created array from findMissing
    delete [] missNums5;


}

void fillArray(int arr[], int n) {
    for (int x = 0; x < n; x++) {
        arr[x] = 0;
    }
}

int* findMissing(int arr[], int n, int& resArrSize) {

    // create a blank array to track the zeros with
    int* trackingNums = new int[n+1];

    //Fill the array with Zeros to start tracking
    fillArray(trackingNums, n+1);

    //Start marking the values that are in the original array
    for (int x = 0; x < n; x++) {
        trackingNums[arr[x]]++;
    }

    //Determine the new size of the ResArrSize by counting the number of zeros in teh tracking array
    for (int x = 0; x < n+1; x++) {
        if(trackingNums[x]==0) {
            resArrSize++;
        }
    }

    //create the array that we will return
    int* retArray = new int[resArrSize];

    //Create a tracking index for filling the return array
    int index = 0;

    for (int x = 0; x < n+1; x++) {
        if(trackingNums[x]==0) {
            retArray[index] = x;
            index++;
        }
    }

    // delete the tracking array
    delete [] trackingNums;


    //return the return array
    return retArray;


}