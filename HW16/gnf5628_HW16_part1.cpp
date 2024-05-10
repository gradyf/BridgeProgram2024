#include <iostream>
#include <fstream>
#include <list>


using namespace std;

const bool pascalChecker(ifstream &in_file) {
    char symb;
    list<char> tracker;

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
        cout << " was a Success!" << endl;
    }
    else {
        cout << " was incorrect!" << endl;
    }

}


int main() {
    ifstream in_stream;

    string test = "P1_1.txt";

    in_stream.open(test);

    if(in_stream.fail()) {
        cout << "The program failed to open the text file.";
        exit(1);

    }
    else {

        cout << test;
        checkerOutput(in_stream);

    }



    in_stream.close();

    cout << "----------NEXT TEST----------" << endl;

    test = "P1_2.txt";

    in_stream.open(test);

    if(in_stream.fail()) {
        cout << "The program failed to open the text file.";
        exit(1);

    }
    else {

        cout << test;
        checkerOutput(in_stream);

    }

    in_stream.close();





}
