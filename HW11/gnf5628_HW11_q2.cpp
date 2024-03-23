#include <iostream>


using namespace std;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);

int main() {

    cout << endl << " --------- isSorted Test ---------" << endl;

    int arr1[] = {1,3};
    int arr1size = 2;

    cout << "Arr1[] is: ";
    for (int x = 0; x < arr1size; x++) {
        cout << arr1[x] << " ";
    }

    if (isSorted(arr1,arr1size)) {
        cout << endl <<  "Arr1 is sorted!" << endl << endl;
    }
    else {
        cout << endl << "Arr1 is not sorted!" << endl << endl;
    }

    int arr2[] = {3,2,1};
    int arr2size = 3;
    cout << "Arr2[] is: ";
    for (int x = 0; x < arr2size; x++) {
        cout << arr2[x] << " ";
    }

    if (isSorted(arr2,arr2size)) {
        cout << endl<< "Arr2 is sorted!" << endl << endl;
    }
    else {
        cout << endl << "Arr2 is not sorted!" << endl << endl;
    }

    int arr3[] = {2};
    int arr3size = 1;
    cout << "Arr3[] is: ";
    for (int x = 0; x < arr3size; x++) {
        cout << arr3[x] << " ";
    }

    if (isSorted(arr3,arr3size)) {
        cout << endl << "Arr3 is sorted!" << endl << endl;
    }
    else {
        cout << endl <<  "Arr3 is not sorted!" << endl << endl;
    }

    int arr4[] = {-1};
    int arr4size = 1;
    cout << "Arr4[] is: ";
    for (int x = 0; x < arr4size; x++) {
        cout << arr4[x] << " ";
    }

    if (isSorted(arr4,arr4size)) {
        cout << endl << "Arr4 is sorted!" << endl << endl;
    }
    else {
        cout << endl <<  "Arr4 is not sorted!" << endl << endl;
    }

    int arr5[] = {-1, 1, 1, 5, 7, 8, 10, 11};
    int arr5size = 8;
    cout << "Arr5[] is: ";
    for (int x = 0; x < arr5size; x++) {
        cout << arr5[x] << " ";
    }

    if (isSorted(arr5,arr5size)) {
        cout << endl << "Arr5 is sorted!" << endl << endl;
    }
    else {
        cout << endl <<  "Arr5 is not sorted!" << endl << endl;
    }

    int arr6[] = {-1, 5, 5,  -1, 3, 7, 10, 11};
    int arr6size = 7;
    cout << "Arr6[] is: ";
    for (int x = 0; x < arr6size; x++) {
        cout << arr6[x] << " ";
    }

    if (isSorted(arr6,arr6size)) {
        cout << endl << "Arr6 is sorted!" << endl << endl;
    }
    else {
        cout << endl <<  "Arr6 is not sorted!" << endl << endl;
    }


    int arr7[] = {1, 2, 3, 4, 5};
    int arr8[] = {5, 4, 3, 2, 1};
    int arr9[] = {1, 2, 2, 3, 4};
    int arr10[] = {1, 3, 2, 4, 5};

    std::cout << "isSorted(arr1): " << (isSorted(arr7, 5) ? "true" : "false")
              << " | Expected: true" << std::endl;
    std::cout << "isSorted(arr2): " << (isSorted(arr8, 5) ? "true" : "false")
              << " | Expected: false" << std::endl;
    std::cout << "isSorted(arr3): " << (isSorted(arr9, 5) ? "true" : "false")
              << " | Expected: true" << std::endl;
    std::cout << "isSorted(arr4): " << (isSorted(arr10, 5) ? "true" : "false")
              << " | Expected: false" << std::endl;
    return 0;







}




int sumOfSquares(int arr[], int arrSize) {
    if(arrSize == 1) {
        return arr[0] * arr[0];
    }
    else {
        int temp = sumOfSquares(arr, arrSize-1);
        return (temp + arr[arrSize-1]*arr[arrSize-1]);
    }
}

bool isSorted(int arr[], int arrSize) {

    if (arrSize == 1) {
        return true;
    }
    else {
        for (int x = 0; x < arrSize; x++) {
            if(arr[x] > arr[arrSize-1]) {
                return false;
            }
        }
        isSorted(arr, arrSize-1);
        return true;

    }

}