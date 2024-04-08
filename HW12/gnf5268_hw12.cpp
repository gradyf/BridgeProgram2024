//
// Created by Gray Forrester on 4/8/24.
//
#include <iostream>

using namespace std;

class Checkbook {
public:
    int checkNumber;
    double checkAmount;
    bool checkStatus;

    int get_checkNumber();
};

int main(){
    cout << "TEST";
}


int Checkbook::get_checkNumber() {
    return checkNumber;
}