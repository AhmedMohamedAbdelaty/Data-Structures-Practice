#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int dt)
        : data(dt)
        , next(nullptr)
    {
    }
};

class SingleLinkedList {
private:
    Node* head;
    Node* tail;

public:
    SingleLinkedList();
    ~SingleLinkedList();
    void insert(int dt);
    void remove(int dt);
    void print();
};

#endif
