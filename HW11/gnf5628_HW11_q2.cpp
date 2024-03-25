#include <iostream>

using namespace std;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);



int main() {

    int arr1[] = {1,-1,5,-3,8,9};
    int arr1size = 6;

    cout << "arr1 is: ";
    for (int x = 0; x < arr1size; x++) {
        cout << arr1[x] << " ";
    }

    if(isSorted(arr1, arr1size)) {
        cout << endl << "arr1 is sorted" << endl;
    }
    else {
        cout << endl <<  "arr1 is not sorted" << endl;
    }


    int arr2[] = {1,3,4,6,8,9};
    int arr2size = 6;

    cout << "arr2 is: ";
    for (int x = 0; x < arr2size; x++) {
        cout << arr2[x] << " ";
    }

    if(isSorted(arr2, arr2size)) {
        cout << endl << "arr2 is sorted" << endl;
    }
    else {
        cout << endl <<  "arr2 is not sorted" << endl;
    }




    return 0;

}



// complete
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
        if (arr[arrSize-2] > arr[arrSize-1]) {
            cout << endl << "Index: " << arrSize - 2 << " is " <<  arr[arrSize-2]
            << " which is greater than index " << arrSize - 1 << " which is " << arr[arrSize-1] << endl;
            return false;
        }
        if(isSorted(arr, arrSize-1)) {
            return true;
        }
        else {
            return false;
        }
    }


}
