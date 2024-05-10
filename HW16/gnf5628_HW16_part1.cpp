#include <iostream>
#include <fstream>
#include <list>

using namespace std;

template<class T>
class Stack {
    list<T> data;

public:
    void push(T newItem) {
        data.push_back(newItem);
    }

    void pop() {
        return data.pop_back();
    }

    T top() const {
        return data.back();
    }

    bool isEmpty() const {
        return data.size() == 0;
    }

    int size() const {
        return data.size();
    }

    void clear() {
        data.clear();
    }

};

const bool pascalChecker(ifstream &in_file) {
    char symb;
    string beg_end;
    Stack<char> tracker;

    while (in_file >> beg_end) {
        if (beg_end == "begin") {
            while (in_file >> symb) {
                if (symb == 'e') {
                    in_file >> beg_end;
                    if (beg_end == "end") {
                        if (tracker.isEmpty()) {
                            return true;
                        } else {
                            return false;
                        }
                    } else {
                        in_file.putback('e');
                    }
                } else if (symb == '{' || symb == '(' || symb == '[' || symb == '}' || symb == ')' || symb == ']') {
                    if (symb == '{' || symb == '(' || symb == '[') {
                        cout << "Pushing: " << symb << endl;
                        tracker.push(symb);
                    } else if (symb == '}' && tracker.top() == '{') {
                        cout << "Popping: " << symb << endl;
                        tracker.pop();
                    } else if (symb == ']' && tracker.top() == '[') {
                        cout << "Popping: " << symb << endl;
                        tracker.pop();
                    } else if (symb == ')' && tracker.top() == '(') {
                        cout << "Popping: " << symb << endl;
                        tracker.pop();
                    } else {
                        cout << "Pushing: " << symb << endl;
                        tracker.push(symb);
                    }


                }
            }
        }
    }

    if (tracker.isEmpty()) {
        return true;
    } else {
        return false;
    }

}


void checkerOutput(ifstream &in_file) {


    if (pascalChecker(in_file)) {
        cout << " was a Success!" << endl;
    } else {
        cout << " was incorrect!" << endl;
    }

}


int main() {
    ifstream in_stream;

    string test = "P1_1.txt";

    in_stream.open(test);

    if (in_stream.fail()) {
        cout << "The program failed to open the text file.";
        exit(1);

    } else {

        cout << test << endl;
        checkerOutput(in_stream);

    }


    in_stream.close();

    cout << "----------NEXT TEST----------" << endl;

    test = "P1_2.txt";

    in_stream.open(test);

    if (in_stream.fail()) {
        cout << "The program failed to open the text file.";
        exit(1);

    } else {

        cout << test << endl;
        checkerOutput(in_stream);

    }

    in_stream.close();

    cout << "----------NEXT TEST----------" << endl;

    test = "P1_3.txt";

    in_stream.open(test);

    if (in_stream.fail()) {
        cout << "The program failed to open the text file.";
        exit(1);

    } else {

        cout << test << endl;
        checkerOutput(in_stream);

    }

    in_stream.close();

    cout << "----------NEXT TEST----------" << endl;

    test = "P1_4.txt";

    in_stream.open(test);

    if (in_stream.fail()) {
        cout << "The program failed to open the text file.";
        exit(1);

    } else {

        cout << test << endl;
        checkerOutput(in_stream);

    }

    in_stream.close();


}
