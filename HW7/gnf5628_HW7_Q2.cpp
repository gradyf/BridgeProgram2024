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
int main() {

    int outCountDivs = 0;
    int outSumDivs = 0;

    cout << "Count of Divisors: " << outCountDivs << endl;
    cout << "Sum of Divisors: " << outSumDivs << endl;

    analyzeDividors(16,outCountDivs,outSumDivs);

    cout << "Count of Divisors: " << outCountDivs << endl;
    cout << "Sum of Divisors: " << outSumDivs << endl;
}


void analyzeDividors(int num, int& outCountDivs, int& outSumDivs) {

    // Cycle through the divisors of
    for (int x = 1; x < sqrt((double) num); x++) {
        if (num % x == 0) {

        }

    }

}