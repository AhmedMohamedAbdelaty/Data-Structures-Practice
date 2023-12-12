#include "BST.h"
#include <algorithm>
#include <cassert> // for assert
#include <iostream>
#include <vector>
using namespace std;

// Implementation of the BST class

BST::BST()
{
    root = nullptr;
}

BST::BST(int value)
{
    root = new Node(value);
}

Node* BST::insertHelper(Node* node, int value)
{
    if (node == nullptr) {
        return new Node(value);
    }
    if (value < node->data) {
        node->left = insertHelper(node->left, value);
    } else {
        node->right = insertHelper(node->right, value);
    }
    return node;
}

bool BST::searchHelper(Node* node, int value)
{
    if (node == nullptr) {
        return false;
    }

    if (node->data == value) {
        return true;
    } else if (value < node->data) {
        return searchHelper(node->left, value);
    } else {
        return searchHelper(node->right, value);
    }
}

void BST::displayHelper(Node* node)
{
    if (node != nullptr) {
        displayHelper(node->left);
        cout << node->data << " ";
        displayHelper(node->right);
    }
}

void BST::insert(int value)
{
    root = insertHelper(root, value);
}

bool BST::search(int value)
{
    return searchHelper(root, value);
}

bool BST::search_iterative(int value)
{
    Node* curr = root;
    while (curr) {
        if (curr->data == value)
            return true;
        else if (value < curr->data) {
            curr = curr->left;
        } else
            curr = curr->right;
    }
    return false;
}

void BST::display()
{
    displayHelper(root);
}
