#include <iostream>
#include "Node.h"
using namespace std;

void delete_by_value(Node **head, string val_to_delete)
{
    Node *current = *head;
    while (current != nullptr)
    {
        cout << current->data << endl;;
        if(current->data == val_to_delete){
            cout << "Found city to delete: " << val_to_delete << endl;
            Node *temp = current;
            //copy of node to delete

            current->prev->next = temp->next;
            current->next->prev = temp->prev;

            delete temp;

        }
        current = current->next;
    }
}

int main()
{
    Node *el_cerrito = new Node("El Cerrito");
    Node *albany = new Node("Albany");
    Node *berkeley = new Node("Berkeley");
    Node *emeryville = new Node("Emeryville");
    Node *oakland = new Node("Oakland");
    Node *san_francisco = new Node("San Francisco");

    el_cerrito->prev = nullptr;
    el_cerrito->next = albany;

    albany->prev = el_cerrito;
    albany->next = berkeley;

    berkeley->prev = albany;
    berkeley->next = emeryville;

    emeryville->prev = berkeley;
    emeryville->next = oakland;

    oakland->prev = emeryville;
    oakland->next = san_francisco;

    san_francisco->prev = oakland;
    san_francisco->next = nullptr;

    Node *head = el_cerrito;

    cout << "Initial list:" << endl;
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "END" << endl
         << endl;

    delete_by_value(&head, "Berkeley");

    cout << "After deleting Berkeley:" << endl;
    current = head;
    while (current != nullptr)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "END" << endl;

    // Clean up memory
    current = head;
    while (current != nullptr)
    {
        Node *temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}