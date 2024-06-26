//
// Created by Gray Forrester on 3/24/24.
//
#include <iostream>

using namespace std;

int lowestCost(int arr[], int arrSize);

int main(){
    int board1[] = {0,3,80,6,57,10};

    cout << "Board1 lowest price: " << lowestCost(board1,6) << endl;

    int board2[] = {0,81,80,6,57,10};

    cout << "Board2 lowest price: " << lowestCost(board2,6) << endl;

    int board3[] = {0,1,2,3,4,5,6,7};

    cout << "Board3 lowest price: " << lowestCost(board3,8) << endl;

    int board4[] = {0,89};

    cout << "Board4 lowest price: " << lowestCost(board4,2) << endl;

    int board5[] = {0};

    cout << "Board5 lowest price: " << lowestCost(board5,1) << endl;

    int board6[] = {0,10,45,40,30,10};

    cout << "Board6 lowest price: " << lowestCost(board6,6) << endl;

    int board7[] = {0,3,80,6,1,10};
    cout << "INCORRECT: Board 7 lowest price: " << lowestCost(board7,6) << endl;

    int board8[] = {0,10,45,40,30,10};
    cout << "Board 8 lowest price: " << lowestCost(board8,6) << endl;
}

// complete
int lowestCost(int arr[], int arrSize) {

    if (arrSize == 1) {
        return 0;

    }

    else if (arrSize == 2) {
        return arr[1];
    }

    else {
        int first = *(arr+1);
        int second = *(arr+2);
        if((first * 2 - 1) < second) {
//            cout << endl <<  "the first number is: " << first << " which is less than " << second << endl;

            int temp = *(arr+1) + lowestCost(arr+1, arrSize - 1);

//            cout << "We will add " << temp << " to the total.";

            return temp;
        }
        else {

//            cout << endl<< "the first number is: " << first << " which is more than << " << second << endl;

            int temp = *(arr+2) + lowestCost(arr+2, arrSize - 2);

//            cout << "We will add " << temp << " to the total.";

            return temp;
        }

    }

}