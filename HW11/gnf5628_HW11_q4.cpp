//
// Created by Gray Forrester on 3/24/24.
//
#include <iostream>

using namespace std;

int lowestCost(int arr[], int arrSize);

int main(){
    int board1[] = {0,3,80,6,57,10};

    cout << lowestCost(board1,6 );

}

int lowestCost(int arr[], int arrSize) {

    if (arrSize == 1) {
        return 0;
    }
    else if (arrSize == 2) {
        return arr[1];
    }
    else {
        if(lowestCost(arr, arrSize-1) < lowestCost(arr+1, arrSize-1)) {

            int temp = lowestCost(arr, arrSize-1);
            return temp + (arr[arrSize-1]);

        }
        else {

            int temp = lowestCost(arr+1, arrSize-1);
            return temp + (arr+1)[arrSize-1];

        }


    }


}