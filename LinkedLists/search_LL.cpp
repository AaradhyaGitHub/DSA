#include <iostream>
#include "Node.h"
using namespace std;

bool search_list(Node *head, string to_find)
{
    Node *current = head;
    while (current != nullptr)
    {
        if (current->data == to_find)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

int main()
{
    Node *home = new Node("Home");
    Node *library = new Node("Library");
    Node *coffeeShop = new Node("Coffee Shop");
    Node *park = new Node("Park");

    home->next = library;
    library->next = coffeeShop;
    coffeeShop->next = park;
    park->next = nullptr;

    cout << "Linked List: ";
    Node *current = home;
    while (current != nullptr)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "END" << endl
         << endl;

    // Test cases
    cout << "Test 1: search_list(home, \"Home\") = "
         << (search_list(home, "Home") ? "true" : "false")
         << " (expected: true)" << endl;

    cout << "Test 2: search_list(home, \"Library\") = "
         << (search_list(home, "Library") ? "true" : "false")
         << " (expected: true)" << endl;

    cout << "Test 3: search_list(home, \"Park\") = "
         << (search_list(home, "Park") ? "true" : "false")
         << " (expected: true)" << endl;

    cout << "Test 4: search_list(home, \"School\") = "
         << (search_list(home, "School") ? "true" : "false")
         << " (expected: false)" << endl;

    Node *emptyList = nullptr;
    cout << "Test 5: search_list(nullptr, \"Home\") = "
         << (search_list(emptyList, "Home") ? "true" : "false")
         << " (expected: false)" << endl;

    cout << "Test 6: search_list(home, \"Lib\") = "
         << (search_list(home, "Lib") ? "true" : "false")
         << " (expected: false)" << endl;

    delete home;
    delete library;
    delete coffeeShop;
    delete park;

    return 0;
}