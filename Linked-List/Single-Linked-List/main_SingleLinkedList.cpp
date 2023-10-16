#include "SingleLinkedList.cpp" // this is needed to avoid linker error, remove it if you get an error error
#include "SingleLinkedList.h"
#include <iostream>
using namespace std;

int main()
{
    SingleLinkedList list;
    list.insert_end(1);
    list.insert_end(1);
    list.insert_end(1);
    list.insert_end(1);
    // print:
    // 1 2 3
    list.print();
}