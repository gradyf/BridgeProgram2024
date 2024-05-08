#include <iostream>
#include <fstream>
#include <list>


using namespace std;

template <typename T>
bool pascalChecker(ifstream &in_file) {
    char symb;
    list<T> tracker;

    while (in_file >> symb) {
        if (symb == '[') {
            tracker.push_back(symb);
        } else if (symb == '{') {
            tracker.push_back(symb);
        } else if (symb == '(') {
            tracker.push_back(symb);
        } else if (symb == ']') {
            tracker.pop_back();
        } else if (symb == '}') {
            tracker.pop_back();
        } else if (symb == '(') {
            tracker.pop_back();
        }

    }

    if (tracker.empty()) {
        return true;
    } else {
        return false;
    }

}

void checkerOutput(ifstream &in_file) {

    if (pascalChecker(in_file)) {
        cout << in_file."Success!";
    }
    else {

    }

}


int main() {
    ifstream in_stream;

    in_stream.open("P1_1.txt");

    if(in_stream.fail()) {
        cout << "The program failed to open the text file.";
        exit(1);

    }
    else {

//        cout << "success";
        cout << pascalChecker(in_stream);

    }

    in_stream.close();





}
