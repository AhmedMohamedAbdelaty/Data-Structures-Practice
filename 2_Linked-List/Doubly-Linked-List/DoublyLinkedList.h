#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
using namespace std;

struct Node {
    int data {};
    Node* next {};
    Node* prev {};

    Node(int data)
        : data { data }
        , next { nullptr }
        , prev { nullptr }
    {
    }
    void set(Node* next, Node* prev)
    {
        this->next = next;
        this->prev = prev;
    }
};

class DoublyLinkedList {
private:
    Node* head {};
    Node* tail {};
    int length {};

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void link(Node* first, Node* second);
    void embed_after(Node* node_before, int data);
    void insert_end(int data);
    void insert_front(int data);
    void insert_sorted(int data);

    void delete_node(Node* node); // connect prev and next nodes then delete the node
    void delete_front();
    void delete_end();
    void delete_node_with_key(int key);

    void print_reversed();
    void print();

    void debug();
};

#endif
