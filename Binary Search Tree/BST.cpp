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

    Node *insertHelper(Node *node, int val)
    {
        if (node == nullptr)
        {
            cout << "   🌱 Created new node with value: " << val << endl;
            return new Node(val);
        }

        if (val < node->data)
        {
            cout << "   ⬅️  " << val << " < " << node->data << " → Going LEFT" << endl;
            node->left = insertHelper(node->left, val);
        }
        else if (val > node->data)
        {
            cout << "   ➡️  " << val << " > " << node->data << " → Going RIGHT" << endl;
            node->right = insertHelper(node->right, val);
        }
        else
        {
            cout << "   ⚠️  Value " << val << " already exists! Skipping..." << endl;
        }

        return node;
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
        cout << "🌳 Inserting " << val << " into BST..." << endl;
        root = insertHelper(root, val);
        cout << "   ✅ Insert complete!" << endl;
        cout << "________________________________________" << endl;
    }

    ~BST()
    {
        destroyTree(root);
    }
};

int main()
{
    cout << "\n╔════════════════════════════════════════╗" << endl;
    cout << "║   Binary Search Tree - Insert Demo    ║" << endl;
    cout << "╚════════════════════════════════════════╝\n" << endl;

    BST tree;

    cout << "Building this tree:" << endl;
    cout << "       5" << endl;
    cout << "      / \\" << endl;
    cout << "     3   7" << endl;
    cout << "    / \\" << endl;
    cout << "   1   4\n" << endl;

    cout << "--- Starting insertions ---\n" << endl;

    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(4);

    cout << "\n✨ Tree construction complete!" << endl;
    cout << "   Rule enforced: Left < Parent < Right\n" << endl;

    // tree.search(3);
    // tree.search(1);
    // tree.search(5);
    // tree.search(10);

    return 0;
}