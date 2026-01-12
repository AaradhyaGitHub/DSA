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

    Node *insertHelper(Node *node, int val){

    };

    Node *deleteLeafHelper(Node *node, int val){

    }

    void destroyTree(Node *node)
    {
        if (node != nullptr)
        {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    BST()
    {
        root = nullptr;
    }

    void insert(int val)
    {
        root = insertHelper(root, val);
    };

    void deleteLeaf(int val)
    {
        if (root == nullptr)
        {
            cout << "Tree is empty, unable to delete!" << endl;
            return;
        }
        root = deleteLeafHelper(root, val);
    }

    ~BST()
    {
        destroyTree(root);
    };
};

int main()
{
    BST tree;

    cout << "Building this tree:" << endl;
    cout << "       5" << endl;
    cout << "      / \\" << endl;
    cout << "     3   7" << endl;
    cout << "    / \\" << endl;
    cout << "   1   4\n"
         << endl;

    cout << "Building now... \n";
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(4);

    cout << "✨ Tree construction complete!\n"
         << endl;

    cout << "🗑️ Deleting the leaf now...\n"
         << endl;

    return 0;
}