#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <vector>
using namespace std;

class BinaryTree {
private:
    int data = 0;
    BinaryTree* left = nullptr;
    BinaryTree* right = nullptr;

public:
    BinaryTree(int data);
    void add(vector<int> values, string path);
    void print_inorder(BinaryTree tree);
    void print_preorder(BinaryTree tree);
    void print_preorder_complete(BinaryTree tree); // prints all nodes, even if they are nullptr
    void print_preorder_parenthesis(BinaryTree tree); // prints like this (value (left-subtree) (right-subtree))
    void print_postorder(BinaryTree tree);
    string print_postorder_parenthesis_canonical(BinaryTree tree); // sort and parenthesis
    void BFS(BinaryTree tree);
};

#endif
