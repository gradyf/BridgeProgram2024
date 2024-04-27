//
// Created by Gray Forrester on 4/27/24.
//
#include <iostream>
#include <string>
using namespace std;

class People {
    double paid;
    double owed;
    string name;
public:
    People(double amountPaid, string overallName, double amountOwed = 0.00)
    : paid(amountPaid), name(overallName), owed(amountOwed) {}

    People();

    void set_owed(double owed) {
        this->owed = owed;
    }
};

class Node {
    People person;
    vector<People>* next;

public:
    Node(People newPerson = People(), vector<People>* newNext = nullptr) : person(newPerson), next(newNext) {}

};


int main() {
    cout << "TEST";
}