#include "BinaryTree.h"
#include <cassert> // for assert
#include <iostream>
#include <queue>
#include <algorithm>
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
    for (std::size_t i = 0; i < path.size(); i++) {
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

void BinaryTree::print_preorder_complete(BinaryTree tree)
{
    cout << tree.data << " ";
    if (tree.left != nullptr)
        print_preorder_complete(*tree.left);
    else
        cout << "-1 ";
    if (tree.right != nullptr)
        print_preorder_complete(*tree.right);
    else
        cout << "-1 ";
}
void BinaryTree::print_preorder_parenthesis(BinaryTree tree)
{
    cout << "( " << tree.data << " ";
    if (tree.left != nullptr)
        print_preorder_parenthesis(*tree.left);
    else
        cout << "() ";
    if (tree.right != nullptr)
        print_preorder_parenthesis(*tree.right);
    else
        cout << "() ";
    cout << ") ";
}

void BinaryTree::print_postorder(BinaryTree tree)
{
    if (tree.left != nullptr)
        print_postorder(*tree.left);
    if (tree.right != nullptr)
        print_postorder(*tree.right);
    cout << tree.data << " ";
}
string BinaryTree::print_postorder_parenthesis_canonical(BinaryTree tree)
{
    string repr = "(" + to_string(tree.data);
    vector<string> v;
    if (tree.left)
        v.push_back(print_postorder_parenthesis_canonical(*tree.left));
    else
        v.push_back("()");
    if (tree.right)
        v.push_back(print_postorder_parenthesis_canonical(*tree.right));
    else
        v.push_back("()");
    sort(v.begin(), v.end());
    for (int i = 0; i < (int)v.size(); ++i)
        repr += v[i];
    repr += ")";
    return repr;
}

void BinaryTree::BFS(BinaryTree tree)
{
    cout << "BFS: " << endl;
    queue<BinaryTree> q;
    q.push(tree);
    int level = 0;
    while (!q.empty()) {
        int sz = q.size();
        cout << "Level " << level << ": ";
        for (int i = 0; i < sz; i++) {
            BinaryTree current = q.front();
            q.pop();
            cout << current.data << " ";
            if (current.left != nullptr)
                q.push(*current.left);
            if (current.right != nullptr)
                q.push(*current.right);
        }
        level++;
        cout << endl;
    }
}