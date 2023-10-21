#include "DoublyLinkedList.cpp" // this is needed to avoid linker error, remove it if you get an error
#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

int main()
{
    DoublyLinkedList list;
    list.insert_sorted(5); // 5
    list.insert_sorted(3); // 3 5
    list.insert_sorted(4); // 3 4 5
    list.insert_sorted(1); // 1 3 4 5
    list.insert_sorted(2); // 1 2 3 4 5
    list.insert_sorted(6); // 1 2 3 4 5 6

    list.print(); // 1 2 3 4 5 6

    list.debug();

    list.delete_front(); // 2 3 4 5 6
    list.delete_front(); // 3 4 5 6

    list.delete_node_with_key(6); // 3 4 5
    list.delete_node_with_key(3); // 4 5


    list.debug();

    return 0;
}