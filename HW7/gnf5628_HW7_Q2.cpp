//
// Created by Gray Forrester on 2/25/24.
//

#include <iostream>
#include <cmath>
using namespace std;

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);

/*
The function takes as an input a positive integer num (≥ 2),
 and updates two output parameters with the number of num's proper
 divisors and their sum.

For example, if this function is called with num=12,
 since 1, 2, 3, 4 and 6 are 12s proper divisors,
 the function would update the output parameters with the numbers 5 and 16.
*/

bool isPerfect(int num);
/*
This functions is given positive integer num (≥ 2),
 and determines if it is perfect number or not.
*/

void testingFunction (int num);


int main() {
//    testingFunction (28);

    int input;

    cout << "Please enter an input: ";

    cin >> input;

    for (int x = 2; x <= input; x++) {

        if(isPerfect(x)) {
            cout << x << endl;
        }

    }

    for (int x = 2; x <= input; x++) {
        int tempSumDivisors = 0;
        int tempCountDivisors = 0;

        int tempSumDivisors_pair = 0;
        int tempCountDivisors_pair = 0;

        analyzeDividors(x, tempCountDivisors, tempSumDivisors);
        analyzeDividors(tempSumDivisors, tempCountDivisors_pair, tempSumDivisors_pair);

        if (!isPerfect(x) &&(tempSumDivisors_pair == x )) {
            cout << x << endl;
        }
    }
}

void testingFunction (int num) {
    int outCountDivs = 0;
    int outSumDivs = 0;

    cout << "We are looking at the number: " << num << endl;

    analyzeDividors(num,outCountDivs,outSumDivs);

    cout << "Count of Divisors: " << outCountDivs << endl;
    cout << "Sum of Divisors: " << outSumDivs << endl;

    if (isPerfect(num)) {
        cout << "The number " << num << " is perfect";
    }
    else {
        cout << "The number " << num << " is not perfect";
    }

}

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs) {

    // Cycle through the divisors of
    for(int x = 1; x <= sqrt((double) num); x++){
        if (num % x == 0) {
            outCountDivs += 1;
            outSumDivs += x;

        }
    }
    for(int x = sqrt((double) num); x >= 1; x--){
        if (num % x == 0) {
            outCountDivs += 1;
            outSumDivs += num / x;
        }
    }

    // back out the last divisor since it's the num, and not a proper divisor
    outCountDivs -= 1;
    outSumDivs -= num;

    //check to see if the sqrt(num) is an integer and thus double counted
    if(sqrt((double) num) == int (sqrt((double) num))) {
        outSumDivs -= sqrt((double) num);
        outCountDivs -= 1;
    }

}

bool isPerfect(int num) {
     int tempSumDivs = 0;
     int tempCountDivs = 0;
     analyzeDividors(num,tempCountDivs,tempSumDivs);
     if (num == tempSumDivs) {
         return true;
     }
     else {
         return false;
     }

 }


