#include <iostream>
#include "Node.h"
using namespace std;

void head_delete(Node **head){
    cout << "Test";
}

int main()
{
    Node *head = nullptr;

    head_insert(&head, "First");
    head_insert(&head, "Second");
    head_insert(&head, "Third");

    cout << "Initial list: ";
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "END" << endl;

    head_delete(&head);
    cout << "After deleting head: ";
    current = head;
    while (current != nullptr)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "END (expected: Second -> First -> END)" << endl;

    head_delete(&head);
    cout << "After deleting head again: ";
    current = head;
    while (current != nullptr)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "END (expected: First -> END)" << endl;

    head_delete(&head);
    cout << "After deleting head again: ";
    current = head;
    while (current != nullptr)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "END (expected: END)" << endl;

    head_delete(&head);
    cout << "After deleting from empty list: ";
    current = head;
    while (current != nullptr)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "END (expected: END)" << endl;

    return 0;
}