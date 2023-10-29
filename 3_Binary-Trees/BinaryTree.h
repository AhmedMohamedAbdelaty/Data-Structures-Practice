#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T>* left;
    Node<T>* right;
    Node(T data)
        : data(data)
        , left(nullptr)
        , right(nullptr)
    {
    }
    Node()
        : data(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
};

template <typename T>
class BinaryTree {
private:
    Node<T>* root;

public:
    BinaryTree()
        : root(nullptr)
    {
    }
    void print_inorder(Node<T>* root);
    void print_postorder(Node<T>* root);
    void print_preorder(Node<T>* root);
};

#endif
