/*
 *
 * Implement the function:
void oddsKeepEvensFlip(int arr[], int arrSize)
This function gets an array of integers arr and its logical size arrSize. When called, it should reorder the elements of arr so that:
1. All the odd numbers come before all the even numbers
2. The odd numbers will keep their original relative order
3. The even numbers will be placed in a reversed order (relative to their original order).
For example, if arr = [5, 2, 11, 7, 6, 4],
after calling oddsKeepEvensFlip(arr, 6), arr will be: [5, 11, 7, 4, 6, 2]
Implementation requirements:
1. Your function should run in linear time. That is, if there are n items in arr, calling
oddsKeepEvensFlip(arr, n) will run in 𝜃(𝑛).
2. Write a main() program that tests this function.
 */

#include <iostream>

using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);

int main() {

    cout << "---------Array 1: ----------" << endl;

    int arr1Size = 6;

    int arr1[] = {5, 2, 11, 7, 6, 4};

    cout << "Array1: ";
    for (int x = 0; x < arr1Size; x++) {
        cout << arr1[x] << " ";
    }

    cout << endl;

    oddsKeepEvensFlip(arr1, arr1Size);

    cout << "New Array1: ";
    for (int x = 0; x < arr1Size; x++) {
        cout << arr1[x] << " ";
    }

    cout << endl <<  "---------Array 2: ----------" << endl;

    int arr2Size = 10;

    int arr2[] = {-7, 10, 0, -20, 5, 2, 11, 7, 6, 4};

    cout << "Array2: ";
    for (int x = 0; x < arr2Size; x++) {
        cout << arr2[x] << " ";
    }

    cout << endl;

    oddsKeepEvensFlip(arr2, arr2Size);

    cout << "New Array2: ";
    for (int x = 0; x < arr2Size; x++) {
        cout << arr2[x] << " ";
    }
    
    return 0;
}

void oddsKeepEvensFlip(int arr[], int arrSize) {
    int num_odds = 0, num_evens = 0;

    //count all the total num_odds and num_evens
    for (int x = 0; x < arrSize; x++) {
        if (arr[x] % 2 == 0) {
            num_evens++;
        }
        else {
            num_odds++;
        }
    }

    int even_arr[num_evens];
    int odd_arr[num_odds];

    int odd_index = 0;

    for (int x = 0; x < arrSize; x++) {
        if (arr[x] % 2 !=0 ){
            odd_arr[odd_index] = arr[x];
            odd_index++;
        }
    }

    int even_index = num_evens-1;

    for (int x = 0; x < arrSize; x++) {
        if (arr[x] % 2 ==0 ){
            even_arr[even_index] = arr[x];
            even_index--;
        }
    }

    //creating the new array

    int new_array_index = 0;

    for (int x = 0; x < num_odds; x++) {
        arr[x] = odd_arr[x];
    }
    for (int x = num_odds; x < arrSize; x++) {
        arr[x] = even_arr[new_array_index];
        new_array_index++;
    }

}