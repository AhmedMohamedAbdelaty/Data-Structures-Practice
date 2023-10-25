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
    // all index are 0-based
    SingleLinkedList();
    ~SingleLinkedList();
    void insert_end(int dt);
    int search(int value);
    int search_improved(int value);
    // for Data Integrity
    void debug_verify_data_integrity();

    Node* get_nth_node(int n);
    void delete_first_node();
    void delete_last_node();
    void delete_nth_node(int n);
    void print();
};

#endif
