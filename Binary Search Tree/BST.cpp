#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BST
{
private:
    Node *root;

public:
    BST()
    {
        root = nullptr;
    }

    void search(int val);
    void insert(int val);
    ~BST();

};

int main()
{
    BST tree;

    return 0;
}