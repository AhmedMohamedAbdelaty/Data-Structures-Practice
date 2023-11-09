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
    void print_postorder(BinaryTree tree);
    void BFS(BinaryTree tree);
};

#endif
