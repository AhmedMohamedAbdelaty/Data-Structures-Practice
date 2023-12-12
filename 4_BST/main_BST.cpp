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
BST createBSTFromSortedVector(const vector<int>& sortedVector, int start, int end)
{
    if (start > end) {
        return BST();
    }

    int mid = (start + end) / 2;
    BST bst(sortedVector[mid]);

    BST leftSubtree = createBSTFromSortedVector(sortedVector, start, mid - 1);
    BST rightSubtree = createBSTFromSortedVector(sortedVector, mid + 1, end);

    bst.ROOT()->left = leftSubtree.ROOT();
    bst.ROOT()->right = rightSubtree.ROOT();

    return bst;
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
    Node* non_bst = new Node(10);
    non_bst->left = new Node(5);
    non_bst->right = new Node(15);
    non_bst->left->left = new Node(3);
    non_bst->left->right = new Node(20); // Not a valid BST

    deb(isBST(non_bst)); // false

    vector<int> v = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    BST bst_from_array = createBSTFromSortedVector(v, 0, v.size() - 1);
    deb(isBST(bst_from_array.ROOT()));
    bst_from_array.display();

    return 0;
}