#include <iostream>
#include "Node.h"
using namespace std;

// TODO: Write your head_insert function here
// Function name: head_insert
// Purpose: Insert a new node at the BEGINNING of the list
// Parameters: Node **head (pointer to pointer), string new_data
// Returns: void (modifies the list directly)
// Note: Use Node** because you're changing what head points to!

void head_insert(Node **head, string new_data)
{
    Node *new_head = new Node(new_data);
    new_head->next = *head;
    *head = new_head;
}

int main()
{
    // Start with empty list
    Node *head = nullptr;

    cout << "Initial list (empty): ";
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "END" << endl
         << endl;

         

    // Test Case 1: Insert into empty list
    head_insert(&head, "First");
    cout << "Test 1 - After inserting 'First': ";
    current = head;

    while (current != nullptr)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "END (expected: First -> END)" << endl;

    /*

    // Test Case 2: Insert at head of existing list
    head_insert(&head, "Second");
    cout << "Test 2 - After inserting 'Second': ";
    current = head;
    while (current != nullptr)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "END (expected: Second -> First -> END)" << endl;

    // Test Case 3: Insert another at head
    head_insert(&head, "Third");
    cout << "Test 3 - After inserting 'Third': ";
    current = head;
    while (current != nullptr)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "END (expected: Third -> Second -> First -> END)" << endl;

    // Test Case 4: Multiple inserts
    head_insert(&head, "Fourth");
    head_insert(&head, "Fifth");
    cout << "Test 4 - After inserting 'Fourth' and 'Fifth': ";
    current = head;
    while (current != nullptr)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "END (expected: Fifth -> Fourth -> Third -> Second -> First -> END)" << endl;

    // Clean up memory (delete all nodes)
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
        */

    return 0;
}
