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

    void set_owed(double newOwed) {
        this->owed = newOwed;
    }
};

class Node {
public:
    People person;
    Node* next;
    Node(People newPerson = People(), vector<People>* newNext = nullptr) : person(newPerson), next(newNext) {}

};

class LList {
    Node* head;
public:
    LList() : head(nullptr) {}
    ~LList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }

};


int main() {
    cout << "TEST";
}