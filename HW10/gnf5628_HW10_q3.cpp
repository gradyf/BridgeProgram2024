//
// Created by Gray Forrester on 3/19/24.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void main1(vector<int> &vect, int search);
void main2(int arr[], int arrSize, int search);

int main(){

    int input, search, arrSize = 0;

    vector<int> numVect;

    int numArr[0];

    cout << "Please enter a sequence of positive integers, each in a separate line.";
    cout << endl << "End your input by typing -1." << endl;

    while (true) {
        cin >> input;

        if (input < 0) {
            break;
        }

        numVect.push_back(input);

    }

    cout << "Please enter a number you want to search." << endl;
    cin >> search;

    main1(numVect, search);
    main2(numArr, arrSize, search);

}

void main1(vector<int> &vect, int search) {
    vector<int> output;
    bool inList = false;

    for (int x = 0; x < vect.size(); x++) {
        if (vect[x] == search) {
            output.push_back(x);
        }
    }

    for (int x = 0; x < output.size(); x++) {
        if (output[x] == search) {
            inList = true;
        }
    }

    if (inList) {
        cout << search << " shows in lines ";
        for (int x = 0; x < output.size(); x++) {
            if (x == output.size() - 1) {
                cout << output[x] + 1 << ".";
            } else {
                cout << output[x] + 1 << ", ";
            }
        }
    }
    else{
        cout << search << " is not in the list.";
    }


}




void main2(int arr[], int arrSize, int search) {

    string output;

    for (int x = 0; x < arrSize; x++) {
        if (arr[x] == search) {
            output += to_string(x+1);
        }
    }

//    cout <<  search << " shows in lines " << output;


}
