#include <iostream>
#include <cassert>


using namespace std;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);
void testIsSorted();


int main() {

//    testIsSorted();

    int arr1[] = {1,-1,5,-3,8,9};
    int arr1size = 6;

    cout << "arr1 is: ";
    for (int x = 0; x < arr1size; x++) {
        cout << arr1[x] << " ";
    }

    isSorted(arr1, arr1size) == true
    ? cout << endl << "arr1 is sorted" << endl
    : cout << endl << "arr1 is not sorted" << endl;



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
        for (int x = 0; x < arrSize; x++) {
            if(arr[x] > arr[arrSize-1]) {
                return false;
            }
        }
        isSorted(arr, arrSize-1);
        return true;

    }

}

void testIsSorted() {
    // Test case 1: General case, sorted array
    int arr1[] = {1, 2, 3, 4};
    assert(isSorted(arr1, 4) == true);

    // Test case 2: General case, not sorted array
    int arr2[] = {4, 1, 3, 2};
    assert(isSorted(arr2, 4) == false);

    // Test case 3: Array with all identical elements
    int arr3[] = {5, 5, 5};
    assert(isSorted(arr3, 3) == true);

    // Test case 4: Array with one element
    int arr4[] = {1};
    assert(isSorted(arr4, 1) == true);

    // Test case 5: Empty array
    int arr5[] = {};
    assert(isSorted(arr5, 0) == true);

    // Test case 6: Array with negative numbers, sorted
    int arr6[] = {-3, -2, -1, 0};
    assert(isSorted(arr6, 4) == true);

    // Test case 7: Array with negative numbers, not sorted
    int arr7[] = {-1, -3, -2, 0};
    assert(isSorted(arr7, 4) == false);

    std::cout << "All test cases for isSorted passed!" << std::endl;
}

// You would then call testIsSorted() in your main function
