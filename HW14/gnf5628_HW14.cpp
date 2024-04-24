#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T>
vector<T> minMax(vector<T> vect) {
    vector<T> answer;
    if (vect.size() == 1) {
        answer.push_back(vect[0]);
        answer.push_back(vect[0]);
        return answer;
    } else if (vect.size() == 2) {
        if (vect[0] < vect[1]) {
            answer.push_back(vect[0]);
            answer.push_back(vect[1]);
            return answer;
        } else {
            answer.push_back(vect[1]);
            answer.push_back(vect[0]);
            return answer;
        }
    } else {
        T mid = vect.size() / 2;
        T rightLow = mid + 1;

        vector<T> leftVect;
        for (int x = 0; x < mid; x++) {
            leftVect.push_back(vect[x]);
        }

        vector<T> rightVect;
        for (int x = mid; x < vect.size(); x++) {
            rightVect.push_back(vect[x]);
        }

        vector<T> leftAns;
        vector<T> rightAns;

        leftAns = minMax(leftVect);
        rightAns = minMax(rightVect);

//        cout << endl << "Low Comp: Comparing " << leftAns[0] << " against " << rightAns[0] << endl;

        if (leftAns[0] < rightAns[0]) {
//            cout << leftAns[0] << " is less than  " << rightAns[0] << endl;

            answer.push_back(leftAns[0]);
        } else {
//            cout << rightAns[0] << " is less than  " << leftAns[0] << endl;

            answer.push_back(rightAns[0]);
        }

//        cout << endl << "High Comp: Comparing " << leftAns[1] << " against " << rightAns[1] << endl;

        if (leftAns[1] > rightAns[1]) {

//            cout << leftAns[1] << " is greater than  " << rightAns[0] << endl;

            answer.push_back(leftAns[1]);
        } else {
//            cout << rightAns[1] << " is greater than  " << leftAns[0] << endl;

            answer.push_back(rightAns[1]);
        }

        return answer;

    }

}


template<typename T2>
void fillVect(vector<T2> &vect, T2 arr[], int arrSize) {
    for (int x = 0; x < arrSize; x++) {
        vect.push_back(arr[x]);
    }
}


template<typename T3>
void printVect(vector<T3> &vect) {
    for (int x = 0; x < vect.size(); x++) {
        cout << vect[x] << " ";
    }
    cout << endl;
}

template<typename T4>
void testFunc(vector<T4> &vect, T4 arr[], int arrSize) {
    fillVect(vect, arr, arrSize);
    printVect(vect);
    vector<T4> answerVect = minMax(vect);
    printVect(answerVect);
}


int main() {

    cout << "Vector 1, size 8" << endl;
    vector<int> vect1;
    int arr1[] = {100, 5, 1, 6, 102, -1, 6, 0};
    int arr1Size = 8;
    fillVect(vect1, arr1, arr1Size);
    printVect(vect1);
    vector<int> answerVect1 = minMax(vect1);
    printVect(answerVect1);

    cout << endl;

    cout << "Vector 2, size 1" << endl;

    vector<int> vect2;
    int arr2[] = {100};
    int arr2Size = 1;
    fillVect(vect2, arr2, arr2Size);
    printVect(vect2);
    vector<int> answerVect2 = minMax(vect2);
    printVect(answerVect2);

    cout << endl;

    cout << "Vector 3, size 2" << endl;

    vector<int> vect3;
    int arr3[] = {100, 50};
    int arr3Size = 2;
    fillVect(vect3, arr3, arr3Size);
    printVect(vect3);
    vector<int> answerVect3 = minMax(vect3);
    printVect(answerVect3);

    cout << endl;

    cout << "Vector 4, size 7" << endl;

    vector<int> vect4;
    int arr4[] = {100, 504, 241, 54, 2521, 2, 0};
    int arr4Size = 7;
    fillVect(vect4, arr4, arr4Size);
    printVect(vect4);
    vector<int> answerVect4 = minMax(vect4);
    printVect(answerVect4);

    cout << endl;

    cout << "Vector 5, size 8" << endl;

    vector<int> vect5;
    int arr5[] = {100, 504, 1000, 200, 12, 2, 0, 11};
    int arr5Size = 8;
    fillVect(vect5, arr5, arr5Size);
    printVect(vect5);
    vector<int> answerVect5 = minMax(vect5);
    printVect(answerVect5);

    cout << endl;

    cout << "Vector 6, size 7" << endl;

    vector<int> vect6;
    int arr6[] = {100, 100, 100, 100, 100, 100, 100};
    int arr6Size = 7;
    fillVect(vect6, arr6, arr6Size);
    printVect(vect6);
    vector<int> answerVect6 = minMax(vect6);
    printVect(answerVect6);

    cout << endl;


    cout << "Vector 7, size 8" << endl;

    vector<int> vect7;
    int arr7[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int arr7Size = 8;
    fillVect(vect7, arr7, arr7Size);
    printVect(vect7);
    vector<int> answerVect7 = minMax(vect7);
    printVect(answerVect7);

    cout << endl;


    cout << "Vector 8, size 8" << endl;

    vector<int> vect8;
    int arr8[] = {7, 6, 5, 4, 3, 2, 1, 0};
    int arr8Size = 8;
    fillVect(vect8, arr8, arr8Size);
    printVect(vect8);
    vector<int> answerVect8 = minMax(vect8);
    printVect(answerVect8);

    cout << endl;


    cout << "Vector 9, size 8" << endl;

    vector<int> vect9;
    int arr9[] = {4, 3, 2, 1, 2, 3, 4, 3};
    int arr9Size = 8;
    fillVect(vect9, arr9, arr9Size);
    printVect(vect9);
    vector<int> answerVect9 = minMax(vect9);
    printVect(answerVect9);

    cout << endl;


    cout << "Vector 10, size 7" << endl;

    vector<double> vect10;
    double arr10[] = {4.1, 3.9, 2.0, 1.5, 2.1, 3.6, 4.4};
    int arr10Size = 7;
    fillVect(vect10, arr10, arr10Size);
    printVect(vect10);
    vector<double> answerVect10 = minMax(vect10);
    printVect(answerVect10);

    cout << endl;


    cout << "Vector 11, size 8" << endl;

    vector<double> vect11;
    double arr11[] = {4.1, 3.1, 2.1, 1.1, 2.0, 3.1, 4.1, 3.1};
    int arr11Size = 8;
    fillVect(vect11, arr11, arr11Size);
    printVect(vect11);
    vector<double> answerVect11 = minMax(vect11);
    printVect(answerVect11);

    cout << endl;

    cout << "Vector 13, size 8" << endl;

    vector<char> vect13;
    char arr13[] = {'y', 't', 'd', 'a', 'e', 'b', 'x', 'p'};
    int arr13Size = 8;
    fillVect(vect13, arr13, arr13Size);
    printVect(vect13);
    vector<char> answerVect13 = minMax(vect13);
    printVect(answerVect13);

    cout << endl;

    cout << "Vector 14, size 8" << endl;

    vector<char> vect14;
    char arr14[] = {'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z'};
    int arr14Size = 8;
    fillVect(vect14, arr14, arr14Size);
    printVect(vect14);
    vector<char> answerVect14 = minMax(vect14);
    printVect(answerVect14);

    cout << endl;

    cout << "Vector 15, size 2" << endl;

    vector<char> vect15;
    char arr15[] = {'t', 'b'};
    int arr15Size = 2;
    fillVect(vect15, arr15, arr15Size);
    printVect(vect15);
    vector<char> answerVect15 = minMax(vect15);
    printVect(answerVect15);

    cout << endl;

    cout << "Vector 16, size 1" << endl;

    vector<char> vect16;
    char arr16[] = {'t'};
    int arr16Size = 1;
    fillVect(vect16, arr16, arr16Size);
    printVect(vect16);
    vector<char> answerVect16 = minMax(vect16);
    printVect(answerVect16);


    cout << endl;

    cout << "Vector 17, size 7" << endl;

    vector<int> vect17;
    int arr17[] = {7, 6, 5, 4, 3, 2, 1};
    int arr17Size = 7;
    fillVect(vect17, arr17, arr17Size);
    printVect(vect17);
    vector<int> answerVect17 = minMax(vect17);
    printVect(answerVect17);

    cout << endl;

    cout << "Vector 18, size 7" << endl;

    vector<double> vect18;
    double arr18[] = {7.6, 6.1, 5.0, 4.51, 3.623, 1.110, 1.111};
    int arr18Size = 7;
    testFunc(vect18, arr18, arr18Size);

    cout << endl;


}



