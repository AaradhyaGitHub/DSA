#include <iostream>
#include <vector>
using namespace std;

// ========== Nodemon for auto compile + file watch + auto execution ==========
nodemon --exec 'g++ -std=c++11 postorder.cpp -o postorder && ./postorder' --ext cpp

// ========== POINTERS & REFERENCES ==========

int x = 10;
int *ptr = &x; // ptr stores ADDRESS of x
int &ref = x;  // ref is ALIAS for x (not new memory)

*ptr = 20;    // DEREFERENCE: change value at address
cout << *ptr; // Read value at address

// Node pointers
Node *head = new Node(5); // Create node on heap
head->next = nullptr;     // Arrow: access member through pointer
(*head).next = nullptr;   // Same thing (verbose)

delete head; // Free memory

// ========== DOUBLE POINTERS (why they exist) ==========

void changeHead(Node **head)
{
    *head = new Node(99); // Change what head POINTS TO
}

Node *myHead = new Node(1);
changeHead(&myHead); // Pass ADDRESS of pointer

// ========== CONST & REFERENCES ==========

void printList(const vector<int> &arr)
{
    // const: can't modify arr
    // &: pass by reference (no copy, faster)
}

// ========== CLASS BASICS ==========

class Stack
{
private:
    Node *head; // Private member
public:
    Stack() { head = nullptr; } // Constructor
    ~Stack() { /* cleanup */ }  // Destructor

    void push(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
};

// ========== COMMON GOTCHAS ==========

// BAD: Dangling pointer
Node *temp = head;
delete temp;
temp->data; // CRASH! temp points to freed memory

// GOOD: Null after delete
delete temp;
temp = nullptr;

// BAD: Memory leak
head = new Node(5);
head = new Node(10); // Lost reference to first node!

// GOOD: Delete before reassigning
delete head;
head = new Node(10);