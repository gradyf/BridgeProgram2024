//
// Created by Gray Forrester on 3/23/24.
//
#include <iostream>

using namespace std;

int minInArray1(int arr[], int arrSize);
int minInArray2(int arr[], int low, int high);

int main() {
    int arr[10] = {9, -2, 14, 12, 3, 6, 2, 1, -9, 15}; int res1, res2, res3, res4;
    res1 = minInArray1(arr, 10);
    res2 = minInArray2(arr, 0, 9);
    cout<<res1<< " " << res2 << endl; //should both be -9
    res3 = minInArray2(arr, 2, 5);
    res4 = minInArray1(arr+2, 4); //arr+2 is equivalent to &(arr[2]) cout<<res3<<” “<<res4<<endl; //should both be 3
    cout<<res3<< " " <<res4<<endl; //should both be 3

    cout << endl;

    int arr2[6] = {0,6,-1,3,-10,-15};
    cout <<  minInArray1(arr2, 7); // -10

    cout << endl;

    int arr3[10] = {-9,8,2,4,3,5, 7, 9, 43, -1};
    cout <<  minInArray2(arr3, 3, 5);



    return 0;
}

// completed
int minInArray1(int arr[], int arrSize) {
    if (arrSize == 1) {
        return arr[0];
    }
    else{
        int temp = minInArray1(arr, arrSize - 1);
        if (temp < arr[arrSize-1]) {
            return temp;
        }
        else {
            return arr[arrSize-1];
        }
    }

}

//Completed
int minInArray2(int arr[], int low, int high) {
    if ((high - low) == 0) {
        return arr[low];
    }
    else{
        int temp = minInArray2(arr,low, high - 1);
        if (temp < arr[high]) {
            return temp;
        }
        else {
            return arr[high];
        }
    }
}
