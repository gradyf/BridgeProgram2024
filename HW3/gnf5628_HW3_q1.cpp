
#include <iostream>

using namespace std;

const double HALF_PRICE = 0.5;
const double MEMBER_DISCOUNT = 0.9;

int main() {

    double base_price, item_one_price, item_two_price, total_price, discount, price_after_discount, tax_rate;

    char has_card;

    cout << "Enter price of first item: ";
    cin >> item_one_price;

    cout << "Enter price of second item: ";
    cin >> item_two_price;

    cout << "Does customer have a club card? (Y/N): ";
    cin >> has_card;

    cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    cin >> tax_rate;

    if (item_one_price <= item_two_price ) {
        if (has_card == 'Y' || has_card == 'y') {
            base_price = item_one_price + item_two_price;
            price_after_discount = ((HALF_PRICE * item_one_price) + item_two_price)*MEMBER_DISCOUNT;
            total_price = ((price_after_discount))*(1+ tax_rate/100);
        }
        else {
            base_price = item_one_price + item_two_price;
            price_after_discount = (HALF_PRICE * item_one_price) + item_two_price;
            total_price = (price_after_discount)*(1+ tax_rate/100);
        }
    }
    else {
        if (has_card == 'Y' || has_card == 'y') {
            base_price = item_one_price + item_two_price;
            price_after_discount = ((HALF_PRICE * item_two_price) + item_one_price)*MEMBER_DISCOUNT;
            total_price = ((price_after_discount))*(1+ tax_rate/100);
        }
        else {
            base_price = item_one_price + item_two_price;
            price_after_discount = (HALF_PRICE * item_two_price) + item_one_price;
            total_price = ((price_after_discount)*MEMBER_DISCOUNT)*(1+ tax_rate/100);
        }
    }

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
    cout << "Base price: " << base_price << endl;
    cout << "Price after discounts: " << price_after_discount << endl;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(5);
    cout << "Total Price: " << total_price << endl;


}