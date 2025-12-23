#include <iostream>
#include "Node.h"
using namespace std;

void head_delete(Node **head)
{
    cout << "current head: "<< (*head)->data << endl;
    cout << endl;
    //(*head)->next;
    Node *temporary_holder = *head;
    *head = temporary_holder->next;
    delete temporary_holder;        
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
    cout << "head in main: " << head << endl;

    cout << "Initial list:" << endl;
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "END" << endl << endl;

    head_delete(&head);
    
    cout << "After deleting head:" << endl;
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