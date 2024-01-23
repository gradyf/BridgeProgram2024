
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c, disc, quad1, quad2;

    cout << "Please enter a value of a: ";
    cin >> a;

    cout << "Please enter a value of b: " ;
    cin >> b;

    cout << "Please enter a value of c: " ;
    cin >> c;


    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    disc = b * b - 4 * a * c;


    if (disc == 0) {
        quad1 = (-b + sqrt(disc))/(2 * a);
    }
    else {
        quad1 = (-b + sqrt(disc))/(2 * a);
        quad2 = (-b - sqrt(disc))/(2 * a);
    }



    if (a == 0 && b == 0 && c == 0) {
        cout << "This equation has an infinite number of solutions.";
    }
    else if (a == 0 && b == 0 && c != 0) {
        cout << "This equation has no solution";
    }
    else if (disc < 0) {
        cout << "This equation has no real solution";
    }
    else if (disc == 0) {
        cout << "This equation has one real solution x = " << quad1;
    }
    else {


        cout << "This equation has two real solutions x = " << quad1 << " and x = " << quad2;
    }



}