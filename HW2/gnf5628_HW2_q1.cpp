#include <iostream>
using namespace std;
/*
 * Write a program that asks the user to enter a number of quarters,
 * dimes, nickels and pennies and then outputs the monetary value of
 * the coins in the format of dollars and remaining cents.

 Your program should interact with the user exactly as it shows in the following example:

 Please enter number of coins:
 # of quarters:13
 # of dimes: 4
 # of nickels: 1
 # of pennies: 17
 The total is 4dollars and 37 cents
 *
 */

const double QUARTER = 0.25;
const double DIME = 0.10;
const double NICKEL = 0.05;
const double PENNY = 0.01;

int main() {

    int numQuarters;
    int numDimes;
    int numNickels;
    int numPennies;

    double total;

    int totalDollars;
    double totalCents;



    std::cout << "Please enter number of coins:" << std::endl;

    std::cout << "# of quarters: " ;
    std::cin >> numQuarters;

    std::cout << "# of dimes: " ;
    std::cin >> numDimes;

    std::cout << "# of nickels: " ;
    std::cin >> numNickels;

    std::cout << "# of pennies: " ;
    std::cin >> numPennies;

    total = QUARTER * numQuarters + DIME * numDimes + NICKEL * numNickels + PENNY * numPennies;

    totalDollars = int (total);
    totalCents = total - totalDollars;


    std::cout << "The total is " << totalDollars << " dollars and  " << totalCents << " cents.";




    return 0;
}
