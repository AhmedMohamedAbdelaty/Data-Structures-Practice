#include "SingleLinkedList.h"

SingleLinkedList::SingleLinkedList()
    : head(nullptr)
    , tail(nullptr)
    , length(0)
{
}

SingleLinkedList::~SingleLinkedList()
{
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    length = 0;
}

void SingleLinkedList::insert_end(int dt)
{
    Node* node = new Node(dt);
    // if head is null, then the list is empty and we need to set head and tail to the new node
    // if head is not null, then we need to set the current tail's next to the new node and set the tail to the new node
    if (head == nullptr) {
        head = node;
        tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
    length++;
}

void SingleLinkedList::print()
{
    cout << "Length: " << length << endl;
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}