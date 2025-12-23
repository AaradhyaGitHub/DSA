#include <iostream>
#include "Node.h"
using namespace std;

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
    cout << "END" << endl;

    delete home;
    delete library;
    delete coffeeShop;
    delete park;

    return 0;
}

// pseudo code to setup a LL implementation.
/*

1. create a new class with the class Node.

2. defined the public attributes
   i)  it will have a data prop which is a built-in data type like string data or int data
   ii) it will have a pointer of the same type i.e Node pointing to nothing initially.

3. define the constructor. This is a function to give life to data and node variables.
   i)  note that the parameter type here should match the type of data i.e string
   ii) we don't know what the next should point to so safe to leave it nullptr

4. Call the Node constructor function with new keyword and pass it the data it needs.
5. Assign a pointer of type whatever constructor you just called so Node.

6. Set the links.
   i)  now that we have individual Nodes, we can make a chain by linking things in the order we want.
   ii) ensure that the last node point to nullptr.

7. To traverse, we need a traversor. Best to call it current.
  i)  Think like you are starting at home
  ii) current = current->next; it's helpful to read this right to left:
      a) current = head so current->next = head->next = Library.
      b) current becomes Library. This is the traversal.

8. While current is not nullptr, make current hop from one pointer to another.
*/