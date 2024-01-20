//
//Write a program that does the following:
//•     Ask user to input three Real numbers a, b and c. They represent the parameters of a
//quadratic equation 𝑎𝑥! + 𝑏𝑥 + 𝑐 = 0

//• Classify to one of the following:
//-     ’Infinite number of solutions’ (for example, 0𝑥! + 0𝑥 + 0 = 0 has infinite number of solutions)
//-     ’No solution’ (for example, 0𝑥! + 0𝑥 + 4 = 0 has no solution)
//-     ’No real solution’ (for example, 𝑥! + 4 = 0 has no real solutions)
//-     ’One real solution’
//-     ’Two real solutions’
//• In cases there are 1 or 2 real solutions, also print the solutions.

//Notes:
//1. If 𝑎 ≠ 0 and there are real solutions to the equation, you can get these solutions using
//        the following formula: ((-b+/- (b*b-4ac)^.5)/2a
//The number of solutions depends on whether (b2 -4ac) is positive, zero, or negative.
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b, c;

    cout << "Please enter a value of a: " << endl;
    cin >> a;

    cout << "Please enter a value of b: " << endl;
    cin >> b;

    cout << "Please enter a value of c: " << endl;
    cin >> c;

    if (a == 0 && b == 0 && c == 0) {
        cout << "This equation has an infinite number of solutions.";
    }
    else if (a == 0 && b == 0 && c != 0) {
        cout << "This equation has no solution";
    }


}