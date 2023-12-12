#include "BST.cpp" // this is needed to avoid linker error, remove it if you get an error
#include "BST.h"
#ifndef ONLINE_JUDGE
#include "../debug.h"
#else
#define deb(x...)
#endif
#include <iostream>
using namespace std;

bool isBST(Node* root, int minValue = INT_MIN, int maxValue = INT_MAX)
{
    if (root == nullptr) {
        return true;
    }

    if (root->data < minValue || root->data > maxValue) {
        return false;
    }

    return isBST(root->left, minValue, root->data - 1) && isBST(root->right, root->data + 1, maxValue);
}

int main()
{
    // Creating a BST
    BST bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);

    deb(isBST(bst.ROOT())); // true

    // Creating non-bst
    BST non_bst(10);
    non_bst.ROOT()->left = new Node(5);
    non_bst.ROOT()->right = new Node(15);
    non_bst.ROOT()->left->left = new Node(3);
    non_bst.ROOT()->left->right = new Node(20); // Not a valid BST

    deb(isBST(non_bst.ROOT())); // false

    return 0;
}