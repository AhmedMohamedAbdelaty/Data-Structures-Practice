#include "SingleLinkedList.h"

SingleLinkedList::SingleLinkedList()
    : head(nullptr)
    , tail(nullptr)
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
}

void SingleLinkedList::remove(int dt)
{
    Node* current = head;
    Node* previous = nullptr;
    while (current != nullptr) {
        if (current->data == dt) {
            if (previous == nullptr) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            if (current == tail) {
                tail = previous;
            }
            delete current;
            return;
        }
        previous = current;
        current = current->next;
    }
}

void SingleLinkedList::print()
{
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}