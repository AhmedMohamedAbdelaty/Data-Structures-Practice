#include "BinaryTree.cpp" // this is needed to avoid linker error, remove it if you get an error
#include "BinaryTree.h"
#include <iostream>
using namespace std;

int main()
{

    BinaryTree tree(1);
    tree.add({ 2, 4, 7 }, "LLL");
    tree.add({ 2, 4, 8 }, "LLR");
    tree.add({ 2, 5, 9 }, "LRR");
    tree.add({ 3, 6, 10 }, "RRL");
    tree.print_inorder(tree); // 7 4 8 2 5 9 1 3 10 6 
    cout << endl;
    tree.print_preorder(tree); // 1 2 4 7 8 5 9 3 6 10
    cout << endl;
    tree.print_postorder(tree); // 7 8 4 9 5 2 10 6 3 1
    cout << endl;
    return 0;
}