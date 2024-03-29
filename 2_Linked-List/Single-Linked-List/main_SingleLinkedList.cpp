#include "SingleLinkedList.cpp" // this is needed to avoid linker error, remove it if you get an error
#include "SingleLinkedList.h"
#include <iostream>
using namespace std;

int main()
{
    SingleLinkedList list;
    for (int i = 1; i <= 10; i++) {
        list.insert_end(i);
    }
    list.print();
    cout << "search(2): " << list.search_improved(2) << endl;
    list.print();
    cout << "search(3): " << list.search_improved(3) << endl;
    list.print();

    // Delete head
    list.delete_first_node();
    list.print();

    // Delete tail
    list.delete_last_node();
    list.print();

    // Delete nth node , n = 3
    list.delete_nth_node(3);
    list.print();

    list.debug_verify_data_integrity();
    cout << "All tests passed!" << endl;

    return 0;
}