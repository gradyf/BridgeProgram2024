//
// Created by Gray Forrester on 2/22/24.
//
#include <iostream>
using namespace std;

int pal(int x);

int main() {
    int number;

    cout << "Enter a positive number: " << endl;
    cin >> number;

    int result = pal(number);

    if (result == 1) {
        cout << pal(number);
    }
    else {
        cout << pal(number);
    }

}

int pal(int x) {

    int reverse = 0, temp_x = x;

    //inverted number
   while (temp_x > 0) {
       int temp = temp_x % 10;

       reverse = reverse * 10 + temp;

       temp_x = temp_x / 10;
   }

   if (x == reverse) {
       return 1;
   }
   else{
       return 0;;
   }

}