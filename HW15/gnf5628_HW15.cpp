
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;


class People {
public:
    double amtInitiallyPaid;
    double amtOwedToPerson;
    double amtOwedToOthers;
    double amtPaidToOthers;
    string nameOfPerson;
    string nameOwedTo;

    People(double amountPaid, const string &overallName, double amountOwed = 0.00, double amountOwes = 0.00,
           const string &owedMoneyTo = "")
            : amtInitiallyPaid(amountPaid), nameOfPerson(overallName), amtOwedToPerson(amountOwed),
              amtOwedToOthers(amountOwes), nameOwedTo(owedMoneyTo), amtPaidToOthers() {}

    People();

    bool operator<(const People &ppl) const {
        return (amtOwedToOthers < ppl.amtOwedToOthers);
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

            cout << n->person.nameOfPerson << " paid " << n->person.amtInitiallyPaid << "; Owes: "
                 << n->person.amtOwedToOthers << "; Is Owed: " << n->person.amtOwedToPerson << "; Owes to: " <<
                 n->person.nameOwedTo << endl;

            n = n->next;
        }
        cout << endl;
    }

    void addNodeEnd(Node *n) {
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

    void setInitialAmts(double avg) const {
        Node *current = head;
        while (current != nullptr) {
            if (current->person.amtInitiallyPaid > avg) {
                current->person.amtOwedToPerson = current->person.amtInitiallyPaid - avg;
            } else if (current->person.amtInitiallyPaid < avg) {
                current->person.amtOwedToOthers = avg - current->person.amtInitiallyPaid;
            }
            current = current->next;
        }
    }
};

void printVect(vector<People> vect) {
    for (int x = 0; x < vect.size(); x++) {

        if (vect[x].amtOwedToOthers == 0 && vect[x].amtOwedToPerson == 0) {
            cout << vect[x].nameOfPerson << ", you don't need to do anything " << endl;
        } else if (vect[x].amtPaidToOthers != 0) {
            cout << vect[x].nameOfPerson << ", you give " << vect[x].nameOwedTo << "$" << vect[x].amtPaidToOthers
                 << endl;

        } else {
            cout << vect[x].nameOfPerson << " initially paid " << vect[x].amtInitiallyPaid << "; Owes: "
                 << vect[x].amtOwedToOthers << "; Is Owed: " << vect[x].amtOwedToPerson << "; Owes to: " <<
                 vect[x].nameOwedTo << "; Has repaid: " << vect[x].amtPaidToOthers << endl;
        }
    }
}


void payBack(vector<People> &owes, vector<People> &isOwed) {

    int owesTrack = 0;
    int owedTrack = 0;


    while (owesTrack < owes.size()) {
        sort(owes.begin(), owes.end());
        owedTrack = 0;
        while (owedTrack < isOwed.size()) {

            if (owes[owesTrack].amtOwedToOthers > isOwed[owedTrack].amtOwedToPerson &&
                isOwed[owedTrack].amtOwedToPerson != 0 && owes[owesTrack].amtPaidToOthers != 0) {

                owes[owesTrack].nameOwedTo = isOwed[owedTrack].nameOfPerson;

                People *temp = new People(owes[owesTrack].amtInitiallyPaid, owes[owesTrack].nameOfPerson + "2");
                temp->amtOwedToOthers = owes[owesTrack].amtOwedToOthers - isOwed[owedTrack].amtOwedToPerson;

                owes.push_back(*temp);

                cout << owes[owesTrack].nameOfPerson << " is repaying " << owes[owesTrack].nameOwedTo
                     << " " << owes[owesTrack].amtPaidToOthers << endl;
                owes[owesTrack].amtPaidToOthers = isOwed[owedTrack].amtOwedToPerson;
                owes[owesTrack].amtOwedToOthers =
                        owes[owesTrack].amtOwedToOthers - isOwed[owedTrack].amtOwedToPerson;

                isOwed[owedTrack].amtOwedToPerson =
                        isOwed[owedTrack].amtOwedToPerson - owes[owesTrack].amtPaidToOthers;


            } else if (owes[owesTrack].amtOwedToOthers < isOwed[owedTrack].amtOwedToPerson &&
                       isOwed[owedTrack].amtOwedToPerson != 0) {

                owes[owesTrack].nameOwedTo = isOwed[owedTrack].nameOfPerson;


                cout << owes[owesTrack].nameOfPerson << " is repaying " << owes[owesTrack].nameOwedTo
                     << " " << owes[owesTrack].amtPaidToOthers << endl;
                owes[owesTrack].amtPaidToOthers = owes[owedTrack].amtOwedToOthers;
                owes[owesTrack].amtOwedToOthers = owes[owesTrack].amtOwedToOthers - owes[owesTrack].amtPaidToOthers;

                isOwed[owedTrack].amtOwedToPerson =
                        isOwed[owedTrack].amtOwedToPerson - owes[owesTrack].amtPaidToOthers;


            }
            owedTrack++;

        }
        owesTrack++;
    }


}


int main() {

    ifstream in_stream;

    double paid, sum = 0, avg = 0;
    string name, fileName;

    int count = 0;

    LList *listOriginal = new LList();

    vector<People> final;
    vector<People> owes;
    vector<People> isOwed;

//    cout << "Enter the filename: " << endl;
//    cin >> fileName;

//    in_stream.open(fileName);
    in_stream.open("List3.txt");

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

        in_stream.ignore(9999, ' ');

        getline(in_stream, name);

        Node *temp = new Node(People(paid, name));
        listOriginal->addNodeEnd(temp);

        sum = sum + paid;
        count++;

    }

    in_stream.close();

    avg = sum / count;

    listOriginal->setInitialAmts(avg);

    Node *current = listOriginal->head;
    while (current != nullptr) {
        if (current->person.amtOwedToOthers == 0 && current->person.amtOwedToPerson == 0) {
            final.push_back(current->person);
        } else if (current->person.amtOwedToOthers != 0 && current->person.amtOwedToPerson == 0) {
            owes.push_back(current->person);
        } else {
            isOwed.push_back(current->person);
        }

        current = current->next;
    }

    printVect(final);

    cout << "In the end, you should have all spent around " << avg;

}