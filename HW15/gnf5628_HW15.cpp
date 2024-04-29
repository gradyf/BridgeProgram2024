//
// Created by Gray Forrester on 4/27/24.
//
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

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
        if (current == nullptr) {
            head = n;

        }
        while (current != nullptr) {
            if (current->next == nullptr) {
                current->next = n;
                break;

            } else {
                current = current->next;
            }
        }

    }

    void clearList() {
        Node *current = head;
        while (current != nullptr) {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }

};


int main() {

    ifstream in_stream;

    double paid, next;
    string name;
    int count = 0;

    vector<People> peopleList;

    in_stream.open("List1.txt");

    if (in_stream.fail()) {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    while (in_stream >> paid) {
        getline(in_stream, name);
        peopleList.push_back(People(paid, name));
    }
    in_stream.close();


    for (int x = 0; x < peopleList.size(); x++) {
        cout << peopleList[x].name << " " << peopleList[x].paid << endl;
    }



//    Node *first = new Node(People(50.12, "John Smith"));
//    Node *second = new Node(People(20.13, "Jane Smith"));
//    Node *third = new Node(People(1.13, "Gray Smith"));
//
//
//    LList *list = new LList();
//
//    list->addNode(first);
//    list->printList();
//
//    list->addNode(second);
//    list->printList();
//
//    list->addNode(third);
//    list->printList();
//
//
//    delete list;
//    list->clearList();


}