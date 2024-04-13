#include <iostream>
#include <vector>

using namespace std;

class Money {
public:
    friend Money operator+(const Money &amount1, const Money &amount2) {
        Money temp;
        temp.all_cents = amount1.all_cents + amount2.all_cents;
        return temp;
    }

    friend Money operator-(const Money &amount1, const Money &amount2) {
        Money temp;
        temp.all_cents = amount1.all_cents - amount2.all_cents;
        return temp;
    }

    friend Money operator-(const Money &amount) {
        Money temp;
        temp.all_cents = -amount.all_cents;
        return temp;
    }

    friend bool operator==(const Money &amount1, const Money &amount2) {
        return (amount1.all_cents == amount2.all_cents);
    }

    friend bool operator<(const Money &amount1, const Money &amount2) {
        return false;
    }

    static int digit_to_int(char c) {
        return (static_cast<int>(c) - static_cast<int>('0'));
    }

    Money(long dollars, int cents) {

        if (
                dollars * cents <
                0) {
            cout << "Illegal values for dollars and cents.\n";
            exit(1);
        }
        all_cents = dollars * 100 + cents; //If one is negative and one is positive
    }

    Money(long dollars) : all_cents(dollars * 100) {}

    Money() : all_cents(0) {}

    double get_value() const {
        return (all_cents * 0.01);
    }

    friend istream &operator>>(istream &ins, Money &amount) {
        char one_char, decimal_point,
                digit1, digit2; //digits for the amount of cents
        long dollars;
        int cents;
        bool negative;//set to true if input is negative.

        ins >> one_char;
        if (one_char == '-') {
            negative = true;
            ins >> one_char; //read '$'
        } else
            negative = false;
        //if input is legal, then one_char == '$'

        ins >> dollars >> decimal_point >> digit1 >> digit2;

        if (one_char != '$' || decimal_point != '.'
            || !isdigit(digit1) || !isdigit(digit2)) {
            cout << "Error illegal form for money input\n";
            exit(1);
        }

        cents = digit_to_int(digit1) * 10 + digit_to_int(digit2);

        amount.all_cents = dollars * 100 + cents;
        if (negative)
            amount.all_cents = -amount.all_cents;

        return ins;
    }

    friend ostream &operator<<(ostream &outs, const Money &amount) {
        long positive_cents, dollars, cents;
        positive_cents = labs(amount.all_cents);
        dollars = positive_cents / 100;
        cents = positive_cents % 100;

        if (amount.all_cents < 0)
            outs << "-$" << dollars << '.';
        else
            outs << "$" << dollars << '.';

        if (cents < 10)
            outs << '0';
        outs << cents;

        return outs;
    }

private:
    long all_cents;

};

class Check {

public:
    Check(int number, Money amount, bool status) {
        checkNumber = number;
        checkAmount = amount;
        checkStatus = status;
    }

    Check() {
        checkNumber = 0;
        checkAmount = 0;
        checkStatus = 0;
    }

    int get_checkNumber() {
        return checkNumber;
    }

    Money get_checkAmount() {
        return checkAmount;
    }

    bool get_checkStatus() {
        return checkStatus;
    }

    void set_checkNumber(int number) {
        checkNumber = number;
    }

    void set_checkAmount(Money amount) {
        checkAmount = amount;
    }

    void set_checkStatus(bool status) {
        checkStatus = status;
    }

    int checkNumber;
    Money checkAmount;
    bool checkStatus;

};


int main() {

    int checkNumber, checkbookSize = 0, depositsSize = 0, totalCashedChecks = 0
            , totalUnCashedChecks = 0;

    Money checkAmount, cashedSumAmount, priorBalance, unCashedSumAmount, depositAmount
    , depositSum = 0, currentBalance, actualBalance;

    bool checkStatus;

    Check *checkbook = new Check[checkbookSize];
    Check *uncashedBook = new Check[checkbookSize];
    Check *cashedBook = new Check[checkbookSize];

    Money *deposits = new Money[depositsSize];

    cout << "Please enter a check number, amount on the check [Include the dollar sign], and whether or not the " <<
         "check has been cashed, indicated by a 1(Yes) or 0(No). Enter a 0 for all three when done inputting checks"
         << endl;

    // Getting checks and putting it in the check book
    while (true) {
        cin >> checkNumber >> checkAmount >> checkStatus;

        if (checkNumber == 0 && checkStatus == 0 && checkNumber == 0) {
            break;
        }
        checkbookSize++;

        Check *newCheckbook = new Check[checkbookSize];

        for (int x = 0; x < checkbookSize - 1; x++) {
            newCheckbook[x] = checkbook[x];
        }


        newCheckbook[checkbookSize - 1].checkNumber = checkNumber;
        newCheckbook[checkbookSize - 1].checkAmount = checkAmount;
        newCheckbook[checkbookSize - 1].checkStatus = checkStatus;

        delete[] checkbook;
        checkbook = newCheckbook;

    }


    //summing up the **cashed checks** and reporting it out
    cout << "The sum of the cashed checks is: " << endl;
    for (int i = 0; i < checkbookSize; i++) {
        if (checkbook[i].checkStatus == 1) {
            cashedSumAmount = cashedSumAmount + checkbook[i].checkAmount;
            totalCashedChecks++;
        }
    }
    cout << cashedSumAmount << endl;

    //copying over the cashed checks
    int tempIndex = 0;
    Check* tempCashedChecks = new Check[totalCashedChecks];
    for (int i = 0; i < checkbookSize; i++) {
        if(checkbook[i].checkStatus == 1) {
            tempCashedChecks[tempIndex] = checkbook[i];
            tempIndex++;
        }

    }
    delete [] cashedBook;
    cashedBook = tempCashedChecks;


    //Summing up the **Uncashed Checks** and reporting out the sum
    cout << "The sum of the uncashed checks is: " << endl;
    for (int i = 0; i < checkbookSize; i++) {
        if (checkbook[i].checkStatus == 0) {
            unCashedSumAmount = unCashedSumAmount + checkbook[i].checkAmount;
            totalUnCashedChecks++;
        }
    }
    cout << unCashedSumAmount << endl;

    //Copying over the **uncashed checks**
    tempIndex = 0;
    Check* tempUnCashed = new Check[totalUnCashedChecks];
    for (int i = 0; i < checkbookSize; i++) {
        if(checkbook[i].checkStatus == 0){
            tempUnCashed[tempIndex] = checkbook[i];
            tempIndex++;
        }
    }
    delete [] uncashedBook;
    uncashedBook = tempUnCashed;



    cout << "Please enter your deposits (end by entering 0): " << endl;

    while (true) {
        cin >> depositAmount;

        if (depositAmount == 0) {
            break;
        }
        depositsSize++;

        Money *newDeposits = new Money[depositsSize];

        for (int x = 0; x < depositsSize - 1; x++) {
            newDeposits[x] = deposits[x];
        }

        newDeposits[depositsSize - 1] = depositAmount;
        newDeposits[depositsSize - 1] = depositAmount;
        newDeposits[depositsSize - 1] = depositAmount;

        delete[] deposits;
        deposits = newDeposits;

    }

    cout << "The sum of the deposits is: " << endl;

    for (int i = 0; i < depositsSize; i++) {
        depositSum = depositSum + deposits[i];
    }

    cout << depositSum << endl;

    cout << "Please enter the prior balance amount (Format: $#.##): " << endl;

    cin >> priorBalance;

    cout << "Please enter the current balance amount (Format: $#.##): " << endl;

    cin >> currentBalance;

    actualBalance = priorBalance + depositSum - cashedSumAmount;

    cout << "The actual account balance is: " << endl;
    cout << actualBalance << endl;

    cout << "This is " << actualBalance - currentBalance << " different than the current balance." << endl;

    cout << "The Cashed Checks are: " << endl;
    for (int i = 0; i < totalCashedChecks; i++) {
        cout << "Check Number: " << cashedBook[i].checkNumber <<" with amount: "
        << cashedBook[i].checkAmount << endl;
    }

    cout << "The Uncashed Checks are: " << endl;
    for (int i = 0; i < totalUnCashedChecks; i++) {
        cout << "Check Number: " << uncashedBook[i].checkNumber <<" with amount: "
        << uncashedBook[i].checkAmount << endl;
    }



    return 0;
}

