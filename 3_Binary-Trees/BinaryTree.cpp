#include "BinaryTree.h"
#include <cassert> // for assert
#include <iostream>
using namespace std;
// constructor 
template <typename T>
BinaryTree<T>::BinaryTree()
    : root(nullptr)
{
}

template <typename T>
void BinaryTree<T>::print_inorder(Node<T>* root)
{
    if (!root)
        return;
    print_inorder(root->left);
    cout << root->data << " ";
    print_inorder(root->right);
}

template <typename T>
void BinaryTree<T>::print_postorder(Node<T>* root)
{
    if (!root)
        return;
    print_postorder(root->left);
    print_postorder(root->right);
    cout << root->data << " ";
}

template <typename T>
void BinaryTree<T>::print_preorder(Node<T>* root)
{
    if (!root)
        return;
    cout << root->data << " ";
    print_preorder(root->left);
    print_preorder(root->right);
}