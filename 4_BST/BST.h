#ifndef BST_H
#define BST_H
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node()
    {
        data = 0;
        left = nullptr;
        right = nullptr;
    }
    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node* root;

    Node* insertHelper(Node* node, int value);
    bool searchHelper(Node* node, int value);
    void displayHelper(Node* node);

public:
    BST();
    BST(int value);
    Node* ROOT()
    {
        return root;
    }
    void insert(int value);

    bool search(int value);

    bool search_iterative(int value);

    void display();
};

#endif
