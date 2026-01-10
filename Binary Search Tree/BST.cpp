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

    Node *insertHelper(Node *node, int val){
        if(node == nullptr){
            return new Node(val);
        }

        if (val < node->data){
            node->left = insertHelper(node->left, val);
        }
        else if(val > node->data){
            node->right = insertHelper(node->right, val);
        }

        return node;
    }

public:
    BST()
    {
        root = nullptr;
    }
    void insert(int val)
    {
        if (root == nullptr)
        {
            root = new Node(val);
            return;
        }

        else
        {
            if (val < root->data)
            {
                if (root->left == nullptr)
                {
                    root->left = new Node(val);
                }
                else
                {
                    insert(root->left->data);
                }
            }
        }
    };
    ~BST();
};

int main()
{
    BST tree;

    return 0;
}