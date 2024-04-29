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

    double paid;
    string name;

    LList *list = new LList();

    vector<People> peopleList;

    in_stream.open("List1.txt");

    if (in_stream.fail()) {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    while (in_stream >> paid) {
        getline(in_stream, name);
        peopleList.push_back(People(paid, name));

        Node* temp = new Node(People(paid, name));
        list->addNode(temp);

    }
    in_stream.close();


    list->printList();



//    delete list;
//    list->clearList();


}