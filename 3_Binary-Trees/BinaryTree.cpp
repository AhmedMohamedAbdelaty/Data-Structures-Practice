#include "BinaryTree.h"
#include <cassert> // for assert
#include <iostream>
using namespace std;

// constructor
BinaryTree::BinaryTree(int dt = 0)
{
    this->data = dt;
    this->left = nullptr;
    this->right = nullptr;
}

void BinaryTree::add(vector<int> values, string path)
{
    assert(path.size() == values.size());
    BinaryTree* current = this;
    for (int i = 0; i < path.size(); i++) {
        if (path[i] == 'L') {
            if (current->left == nullptr) {
                current->left = new BinaryTree(values[i]);
            } else
                assert(current->left->data == values[i]);
            current = current->left;
        } else {
            if (current->right == nullptr) {
                current->right = new BinaryTree(values[i]);
            } else
                assert(current->right->data == values[i]);
            current = current->right;
        }
    }
}

void BinaryTree::print_inorder(BinaryTree tree)
{
    if (tree.left != nullptr)
        print_inorder(*tree.left);
    cout << tree.data << " ";
    if (tree.right != nullptr)
        print_inorder(*tree.right);
}

void BinaryTree::print_preorder(BinaryTree tree)
{
    cout << tree.data << " ";
    if (tree.left != nullptr)
        print_preorder(*tree.left);
    if (tree.right != nullptr)
        print_preorder(*tree.right);
}

void BinaryTree::print_postorder(BinaryTree tree)
{
    if (tree.left != nullptr)
        print_postorder(*tree.left);
    if (tree.right != nullptr)
        print_postorder(*tree.right);
    cout << tree.data << " ";
}