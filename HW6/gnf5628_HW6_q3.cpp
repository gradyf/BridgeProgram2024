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

double eApprox(int n) {
    double fraction = 0.0;

    while (n > 1) {
        fraction += 1;
        fraction /= n;
        n--;
    }

    return fraction + 2;
}
