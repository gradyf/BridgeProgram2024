//
// Question 1:
//Write a program that computes how much a customer has to pay after purchasing two items. The price is calculated according to the following rules:
//• Buy one get one half off promotion: the lower price item is half price.
//• If the customer is club card member, additional 10% off.
//• Tax is added.
//Inputs to the program include:
//• Two items’ prices
//• Have club card or not (User enters ‘Y’ or ‘y’ for “yes”; ‘N’ or ‘n’ for “no”)
//• Tax rate (User enters the percentage as a number; for example they enter 8.25 if the tax
//rate is 8.25%)
//Program displays:
//• Base price - the price before the discounts and taxes
//• Price after discounts - the price after the buy one get one half off promotion and the
//member’s discount, if applicable
//• Total price – the amount of money the customer has to pay (after tax).
//Your program should interact with the user exactly as it shows in the following example:
// Enter price of first item: 10
//Enter price of second item: 20
//Does customer have a club card? (Y/N): y
// Enter tax rate, e.g. 5.5 for 5.5% tax: 8.25 Base price: 30.0
//Price after discounts: 22.5
//Total price: 24.35625
//

#include <iostream>

using namespace std;

int main() {

    double base_priice, item_one_price, item_two_price, total_price, discount, price_after_discount;

    char club_card;

    double tax_rate;

    cout << "Enter price of first item: ";
    cin >> item_one_price;

    cout << "Enter price of second item: ";
    cin >> item_two_price;

    cout << "Does customer have a club card? (Y/N): ";
    cin >> club_card;

}