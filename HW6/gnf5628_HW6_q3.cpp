//
// Created by Gray Forrester on 2/16/24.
//

#include <iostream>
using namespace std;

double eApprox(int n);

int main () {

    cout.precision(30);

    for (int n = 1; n <= 15; n++) {
        cout << "n = " << n << '\t' << eApprox(n) << endl;
    }
    return 0;
}

//This Function returns e calculated at the n+1 addends
double eApprox(int n) {
    double sum = 1; // e stars with 1

    //builds the outer addend loop
    for (int addened = 0; addened < n; addened++){
        int temp_denom = 0;
        //builds the factoral for the denominator
        for (int den = 1; den <= addened; den++) {
            temp_denom += den;
        }
        sum += 1.0/temp_denom;
    }

    return sum;
}
