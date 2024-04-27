//
// Created by Gray Forrester on 4/25/24.
//
#include <iostream>
#include <string>

using namespace std;

template<class T>
class LListNode {
    T data;
    LListNode<T>* next;
public:
    LListNode(T newdata = T(), LListNode<T> *newNext = nullptr) : data(newdata), next(newNext) {}

    friend class LList<T>;
};

template<class T>
class LList {
    LListNode<T> *head;

    LListNode<T> *recursiveCopy(LListNode<T> *rhs);

public:
    LList() : head(nullptr) {}

    LList(const LList &rhs) : head(nullptr) { *this = rhs; }

    LList<T> &operator=(const LList<T> &rhs);

    ~LList() { clear(); }

    void insertAtHead(T newdata);

    T removeFromHead();

    bool isEmpty() const { return head == nullptr };

    void clear();

    void insertAtEnd(T newdata);

    void insertAtPoint(LListNode<T> *ptr, T newdata);

    int size() const;
};


int main() {

}