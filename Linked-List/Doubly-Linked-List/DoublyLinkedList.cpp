#include "DoublyLinkedList.h"
#include <cassert> // for assert

DoublyLinkedList::DoublyLinkedList()
    : head { nullptr }
    , tail { nullptr }
    , length { 0 }
{
}

DoublyLinkedList::~DoublyLinkedList()
{
    Node* current { head };
    while (current != nullptr) {
        Node* next { current->next };
        delete current;
        current = next;
    }
    head = tail = nullptr;
    length = 0;
}

void DoublyLinkedList::print_reversed()
{
    cout << "Length: " << length << endl;
    cout << "Reversed: ";
    Node* current { tail };
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
}
void DoublyLinkedList::link(Node* first, Node* second)
{
    // link two nodes together (first -> second)
    if (first)
        first->next = second;
    if (second)
        second->prev = first;
}
void DoublyLinkedList::embed_after(Node* node_before, int data)
{
    // embed a new node after a given node
    if (!node_before) {
        cout << "Error: node_before is nullptr" << endl;
        return;
    }
    Node* middle_node = new Node(data);
    Node* node_after = node_before->next;
    link(node_before, middle_node);
    link(middle_node, node_after);

    length++;
}
void DoublyLinkedList::insert_end(int data)
{
    Node* new_node = new Node(data);
    if (head == nullptr) {
        head = tail = new_node;
    } else {
        link(tail, new_node);
        tail = new_node;
    }

    length++;
}
void DoublyLinkedList::insert_front(int data)
{
    Node* new_node = new Node(data);
    if (head == nullptr) {
        head = tail = new_node;
    } else {
        link(new_node, head);
        head = new_node;
    }

    length++;
}
void DoublyLinkedList::insert_sorted(int data)
{
    if (head == nullptr || head->data >= data) {
        insert_front(data);
        return;
    }
    if (tail->data <= data) {
        insert_end(data);
        return;
    }
    Node* current = head;
    while (current != nullptr && current->data < data) {
        current = current->next;
    }
    Node* new_node = new Node(data);
    link(current->prev, new_node);
    link(new_node, current);

    length++;
}

void DoublyLinkedList::delete_node(Node* node)
{
    if (!node)
        return;
    link(node->prev, node->next);
    delete node;
    length--;
}
void DoublyLinkedList::delete_front()
{
    if (!head)
        return;
    Node* new_head = head->next;
    delete_node(head);
    head = new_head;

    // Integirty check
    if (head == nullptr || !length)
        tail = nullptr;
    else
        head->prev = nullptr;
}
void DoublyLinkedList::delete_end()
{
    if (!tail)
        return;
    Node* new_tail = tail->prev;
    delete_node(tail);
    tail = new_tail;

    // Integirty check
    if (tail == nullptr || !length)
        head = nullptr;
    else
        tail->next = nullptr;
}
void DoublyLinkedList::delete_node_with_key(int value)
{
    if (!head || !length) {
        cout << "Error: Empty List" << endl;
        return;
    }
    if (head->data == value) {
        delete_front();
    } else {
        Node* current = head;
        while (current != nullptr && current->data != value) {
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Error: value not found" << endl;
            return;
        }
        if (current == tail) {
            delete_end();
        } else {
            delete_node(current);
        }
    }
}

void DoublyLinkedList::print()
{
    cout << "Length: " << length << endl;
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void DoublyLinkedList::debug()
{
    // print a table of all nodes with  index, data, next , head ,tail
    if (head == nullptr) {
        cout << "Empty List" << endl;
        return;
    }
    cout << "Length: " << length << endl;
    cout << "index\tdata\tnext" << endl;
    Node* current = head;
    int index = 0;
    while (current != nullptr) {
        cout << index << "\t" << current->data << "\t";
        if (current == tail) {
            cout << "nullptr";
        } else {
            cout << current->next->data;
        }
        cout << endl;
        current = current->next;
        index++;
    }
    cout << endl;
}