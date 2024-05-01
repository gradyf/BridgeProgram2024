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
    double owedAmt;
    double owes;
    string name;
    string owedTo;

    People(double amountPaid, string overallName, double amountOwed = 0.00, double amountOwes = 0.00,
           string owedMoneyTo = "")
            : paid(amountPaid), name(overallName), owedAmt(amountOwed), owes(amountOwes), owedTo(owedMoneyTo) {}

    People();

    void set_owedAmt(double newOwed) {
        this->owedAmt = newOwed;
    }

    void set_owes(double newOwes) {
        this->owes = newOwes;
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
            if (n->person.owes == 0 && n->person.owedAmt == 0) {
                cout << n->person.name << ", you don't need to do anything " << endl;
            } else {
                cout << n->person.name << " paid " << n->person.paid << "; Owes: " << n->person.owes << "; Is Owed: "
                     << n->person.owedAmt << endl;
            }

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

    void updateOwesOrOwed(double avg) {
        Node *current = head;
        while (current != nullptr) {
            if (current->person.paid > avg) {
                current->person.owedAmt = current->person.paid - avg;
            } else if (current->person.paid < avg) {
                current->person.owes = avg - current->person.paid;
            }
            current = current->next;
        }

    }

    bool everyoneEven(double avg) {
        Node *current = head;
        bool even = true;
        while (current != nullptr) {
            if (current->person.paid == avg || current->person.owes == avg || current->person.owedAmt == avg) {
                continue;
            } else {
                even = false;
            }
            current = current->next;
        }
        return even;
    }

};

int main() {

    ifstream in_stream;

    double paid, sum = 0, avg = 0;
    string name, fileName;

    int count = 0;

    LList *list = new LList();

    cout << "Enter the filename: " << endl;
    cin >> fileName;

    in_stream.open(fileName);

    /*

     List3.txt:

     76.8 Jason J. Jones
     89 Natalie Johnson
     11 Dalton Smith
     44.2 Sheryl Carter
     0 John Martin

     */

    if (in_stream.fail()) {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    while (in_stream >> paid) {

        getline(in_stream, name);

        Node *temp = new Node(People(paid, name));
        list->addNode(temp);

        sum = sum + paid;
        count++;

    }

    in_stream.close();

    avg = sum / count;

    list->printList();

    list->updateOwesOrOwed(avg);

    cout << endl;

    list->printList();

}