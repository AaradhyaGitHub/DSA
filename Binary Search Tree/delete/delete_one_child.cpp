#include <iostream>
#include <vector>
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

    Node *insertHelper(Node *node, int val)
    {
        if (root == nullptr)
        {
            return new Node(val);
        }

        if (val < node->data)
        {
            node->left = insertHelper(node->left, val);
        }
        else if (val > node->data)
        {
            node->right = insertHelper(node->right, val);
        }
        else
        {
            cout << "Value already exists! Skipping..." << endl;
        }

        return node;
    }

public:
    void insert(int val)
    {
        root = insertHelper(root, val);
    }
};

int main()
{
    return 0;
}