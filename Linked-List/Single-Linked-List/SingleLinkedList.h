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
    int length = 0;

public:
    SingleLinkedList();
    ~SingleLinkedList();
    void insert_end(int dt);
    int search(int value);
    int search_improved(int value);
    // for Data Integrity
    void debug_verify_data_integrity();
    void print();
};

#endif
