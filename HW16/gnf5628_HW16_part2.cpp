//
// Created by Gray Forrester on 5/8/24.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<class T>
class vectQueue {

    vector<T> data;


public:

    int front;
    int back;

    vectQueue() : data(), front(0), back(0) {}


    T top() const {
        return data[front];
    }

    int queueSize() const {
        return back - front;
    }

    int size() const {
        return data.size();
    }

    bool isQueueEmpty() {

        return queueSize() == 0;
    }

    void clearQueue() {

        front = 0;
        back = 0;

    }

    void enqueue(T newData) {

        cout << "Enqueue: " << newData << endl;

        if (this->queueSize() <= data.size()) {
            data.push_back(newData);
        } else {
            data[back] = newData;

        }

        back++;

    }

    T dequeue() {

        if (isQueueEmpty()) {
            cout << "Error: The Queue is empty; you can not dequeue." << endl;
        } else {
            T temp = data[front];
            front++;
            cout << "Dequeue: " << temp << endl;

            if (front == back) {
                clearQueue();
                data.clear();
            }

            return temp;
        }

    }

    T operator[](int index) {
        return data[index];
    }

    void printTest() {

        cout << "Test vector size: " << this->size() << endl;
        cout << "Test queue size: " << this->queueSize() << endl;
        cout << "Front Index: " << this->front << endl;
        cout << "Back Index: " << this->back-1 << endl;

        if (!isQueueEmpty()) {
            cout << "Top: " << top() << endl;
        } else {
            cout << "There is not a top since the Queue is empty." << endl;
        }

        if (isQueueEmpty()) {
            cout << "Front value: NULL " << endl;
            cout << "Back value: NULL" << endl;


        } else {
            cout << "Front value: " << data[this->front] << endl;
            cout << "Back value: " << data[this->back-1] << endl;

        }


//
        cout << "Queue loop: ";
        for (int x = this->back - 1; x >= this->front; x--) {
            cout << data[x] << " ";

        }

        cout << endl;

        cout << "Vector loop: ";
        for (int x = 0; x < this->size(); x++) {
            cout << data[x] << " ";

        }

        cout << endl << endl;
    }

};


int main() {

    vectQueue<int> test;

    test.printTest();

    test.enqueue(6);

    test.printTest();

    test.enqueue(10);

    test.printTest();

    test.enqueue(12);

    test.printTest();

    cout << test.dequeue() << endl;

    test.printTest();

    cout << test.dequeue() << endl;

    test.printTest();

    cout << test.dequeue() << endl;

    test.printTest();

    test.enqueue(74);

    test.printTest();

    test.enqueue(15);

    test.printTest();

    test.enqueue(25);

    test.printTest();

    test.enqueue(90);

    test.printTest();

    test.enqueue(-5);

    test.printTest();

    test.dequeue();

    test.printTest();

    test.dequeue();

    test.printTest();

    test.enqueue(100);

    test.printTest();

    test.dequeue();

    test.printTest();

    test.dequeue();

    test.printTest();

    test.dequeue();

    test.printTest();

    test.dequeue();

    test.printTest();

    test.dequeue();

    test.printTest();

    test.dequeue();

    test.printTest();


}