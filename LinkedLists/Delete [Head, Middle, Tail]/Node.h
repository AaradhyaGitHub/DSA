#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

class Node
{
public:
    string data;
    Node *prev;
    Node *next;

    Node(string value)
    {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

#endif