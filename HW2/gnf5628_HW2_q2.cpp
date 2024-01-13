#include <iostream>
using namespace std;

/*
 *
 * Question 2:
Write a program that asks the user to enter an amount of money in the format of dollars and
remaining cents. The program should calculate and print the minimum number of coins
(quarters, dimes, nickels and pennies) that are equivalent to the given amount.
Hint: In order to find the minimum number of coins, first find the maximum number of
quarters that fit in the given amount of money, then find the maximum number of dimes
that fit in the remaining amount, and so on.
Your program should interact with the user exactly as it shows in the following example:

 Please enter your amount in the format of dollars and cents separated by a space:
4 37
4 dollars and 37 cents are:
17 quarters, 1 dimes, 0 nickels and 2 pennies


 */


const double QUARTER = 0.25;
const double DIME = 0.10;
const double NICKEL = 0.05;
const double PENNY = 0.01;

int main() {

    int numQuarter = 0, numDime = 0, numNickel = 0, numPenny = 0;

    double totalDollars, totalCents, totalMoney;

    cout << "Please enter your amount in the format of dollars and cents seperated by a space" << endl;

    cin >> totalDollars;
    cin >> totalCents;

    totalMoney = totalDollars + (totalCents / 100);

    numQuarter = totalMoney / QUARTER;

    totalMoney = totalMoney - (numQuarter * QUARTER);

    numDime = totalMoney / DIME;

    totalMoney = totalMoney - (numDime * DIME);

    numNickel = totalMoney / NICKEL;

    totalMoney = totalMoney - (numNickel * NICKEL);

    numPenny = totalMoney / PENNY;

    cout << totalDollars << " dollars and " << totalCents << " cents are: " << endl;
    cout << numQuarter << " quarters, " << numDime << " dimes, " << numNickel << " nickels and "
    << numPenny << " pennies";

}
// Created by Gray Forrester on 1/10/24.
//
