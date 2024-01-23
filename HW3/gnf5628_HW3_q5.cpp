#include <iostream>
#include <string>
using namespace std;

const double LB_TO_KG = 0.453592;
const double IN_TO_M = 0.0254;

int main() {

    double weight_pounds = 0, height_inches = 0, weight_kilogram = 0, height_meters = 0, bmi = 0;

    string status;

    cout << "Please enter weight (in pounds): ";
    cin >> weight_pounds;

    weight_kilogram = weight_pounds * LB_TO_KG;

    cout << "Please enter height (in inches): ";
    cin >> height_inches;

    height_meters = height_inches * IN_TO_M;

    bmi = (weight_kilogram) / (height_meters * height_meters);

    if (bmi >= 30) {
        status = "Obese";
    }
    else if (bmi >= 25 && bmi < 30) {
        status = "Overweight";
    }
    else if (bmi >= 18.5 && bmi < 25) {
        status = "Normal";
    }
    else {
        status = "Underweight";
    }

    cout << "The weight status is: " << status << endl;

    return 0;
}