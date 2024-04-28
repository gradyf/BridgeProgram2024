//
// Created by Gray Forrester on 4/27/24.
//
#include <iostream>
#include <string>

using namespace std;

class People {
public:
    double paid;
    double owed;
    string name;

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
    Node *next;

    Node(People newPerson = People(), Node *newNext = nullptr) : person(newPerson), next(newNext) {}

};

class LList {
public:
    Node *head;

    LList(Node *firstHead = nullptr) : head(firstHead) {}

    ~LList() {
        Node *current = head;
        while (current != nullptr) {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }

    void printList() {
        Node *n = head;
        while (n != nullptr) {
            cout << n->person.name << " paid " << n->person.paid << endl;
            n = n->next;
        }
    }

    void addNode(Node *n) {
        Node *current = head;
        while (n != nullptr) {
            if (current->next == nullptr) {
                current->next = n;
                n->next == nullptr;
            } else {
                current = current->next;
            }

        }
    }

};


int main() {

    Node *first = new Node(People(50.12, "John Smith"));
    Node *second = new Node(People(20.13, "Jane Smith"));
    Node *third = new Node(People(1.13, "Gray Smith"));

    first->next = second;
    second->next = third;
    third->next = nullptr;

    LList *list = new LList(first);

    list->printList();
    delete list;

}