#include <iostream>

using namespace std;

class Money {
public:
    friend Money operator+(const Money &amount1, const Money &amount2);
    //Returns the sum of the values of amount1 and amount2.

    friend Money operator-(const Money &amount1, const Money &amount2);
    //Returns amount 1 minus amount2.

    friend Money operator-(const Money &amount);
    //Returns the negative of the value of amount.

    friend bool operator==(const Money &amount1, const Money &amount2);
    //Returns true if amount1 and amount2 have the same value; false otherwise.

    friend bool operator<(const Money &amount1, const Money &amount2);
    //Returns true if amount1 is less than amount2; false otherwise.

    Money(long dollars, int cents);
    //Initializes the object so its value represents an amount with
    //the dollars and cents given by the arguments. If the amount
    //is negative, then both dollars and cents should be negative.

    Money(long dollars);
    //Initializes the object so its value represents $dollars.00.

    Money();
    //Initializes the object so its value represents $0.00.

    double get_value() const;
    //Returns the amount of money recorded in the data portion of the calling
    //object.

    friend istream &operator>>(istream &ins, Money &amount);
    //Overloads the >> operator so it can be used to input values of type
    //Money. Notation for inputting negative amounts is as in -$100.00.
    //Precondition: If ins is a file input stream, then ins has already been
    //connected to a file.


    friend ostream &operator<<(ostream &outs, const Money &amount);
    //Overloads the << operator so it can be used to output values of type
    //Money. Precedes each output value of type Money with a dollar sign.
    //Precondition: If outs is a file output stream, then outs has already been
    //connected to a file.
private:
    long all_cents;
};
    class Checkbook {

public:
    Checkbook(int checkNumber, double checkAmount, bool checkStatus);
    Checkbook(int checkNumber, double checkAmount);
    Checkbook(int checkNumber);
    Checkbook();

    int get_checkNumber();
    Money get_checkAmount();
    bool get_checkStatus();

    void set_checkNumber(int number);
    void set_checkAmount(Money amount);
    void set_checkStatus(bool status);

private:

    int checkNumber;
    Money checkAmount;
    bool checkStatus;

};

// Money Class declaration here:



int main(){
    cout << endl << "-----------------------CB1-----------------------" << endl;
    Checkbook cb1(1234, 105.43, true);

    cout << "Amount Before: " << cb1.get_checkAmount() << endl;
    cb1.set_checkAmount(123.44);
    cout << "Amount After: " << cb1.get_checkAmount() << endl;
    cout << "Number Before: " << cb1.get_checkNumber() << endl;
    cb1.set_checkNumber(67128);
    cout << "Number After: " << cb1.get_checkNumber() << endl;
    cout << "Status Before: " << cb1.get_checkStatus() << endl;
    cb1.set_checkStatus(false);
    cout << "Status After: " << cb1.get_checkStatus() << endl;

    cout << endl << "-----------------------CB2-----------------------" << endl;

    Checkbook cb2(9876, 204.12);

    cout << "Amount: " << cb2.get_checkAmount() << endl;
    cout << "Number: " << cb2.get_checkNumber() << endl;
    cout << "Status: " << cb2.get_checkStatus() << endl;



    cout << endl << "-----------------------CB3-----------------------" << endl;

    Checkbook cb3(57493 );

    cout << "Amount: " << cb3.get_checkAmount() << endl;
    cout << "Number: " << cb3.get_checkNumber() << endl;
    cout << "Status: " << cb3.get_checkStatus() << endl;

    cout << endl << "-----------------------CB4-----------------------" << endl;

    Checkbook cb4;

    cout << "Amount: " << cb4.get_checkAmount() << endl;
    cout << "Number: " << cb4.get_checkNumber() << endl;
    cout << "Status: " << cb4.get_checkStatus() << endl;
}

// Three input contructor
Checkbook::Checkbook(int number, double amount, bool status) {
    checkNumber = number;
    checkAmount = amount;
    checkStatus = status;
}

// Two input contructor
Checkbook::Checkbook(int number, double amount) {
    checkNumber = number;
    checkAmount = amount;
    checkStatus = false;

}

// One input Constructor
Checkbook::Checkbook(int number) {
    checkNumber = number;
    checkAmount = 0;
    checkStatus = false;
}

//Default Constructor
Checkbook::Checkbook() {
    checkNumber = NULL;
    checkAmount = 0;
    checkStatus = false;
}


int Checkbook::get_checkNumber() {
    return checkNumber;
}

bool Checkbook::get_checkStatus() {
    return checkStatus;
}

double Checkbook::get_checkAmount() {
    return checkAmount;
}

void Checkbook::set_checkNumber(int number) {
    checkNumber = number;
}

void Checkbook::set_checkStatus(bool status) {
    checkStatus = status;
}

void Checkbook::set_checkAmount(double amount) {
   checkAmount = amount;
}

