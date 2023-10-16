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

void SingleLinkedList::insert(int dt)
{
    Node* newNode = new Node(dt);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
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