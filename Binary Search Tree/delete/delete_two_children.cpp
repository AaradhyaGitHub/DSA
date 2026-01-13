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

        if (node == nullptr)
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

    Node *deleteChildren(Node *node, int val)
    {
        if (node == nullptr){
            cout << "C"
        }

    }

    void inOrderHelper(Node *node, vector<int> &result)
    {
        if (node == nullptr)
        {
            cout << " ❌ Reached the end - returning" << endl;
            return;
        }

        cout << "   📍 Visiting node: " << node->data << endl;
        inOrderHelper(node->left, result);

        cout << "   ✅ Adding " << node->data << " to result" << endl;
        result.push_back(node->data);

        inOrderHelper(node->right, result);
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
    }

    vector<int> inOrder()
    {

        if (root == nullptr)
        {
            cout << "❌ Empty tree!" << endl;
            return {};
        }

        cout << "\n🔍 In-Order Traversal" << endl;
        cout << "========================" << endl;

        vector<int> result;
        inOrderHelper(root, result);

        cout << "📊 Result: ";
        for (int val : result)
        {
            cout << val << " ";
        }
        cout << "\n"
             << endl;

        return result;
    }

    ~BST()
    {
        destroyTree(root);
    }
};

int main()
{
    BST tree;

    cout << "Building this tree:" << endl;
    cout << "       10" << endl;
    cout << "      /  \\" << endl;
    cout << "     5    15" << endl;
    cout << "    /      \\" << endl;
    cout << "   3       20" << endl;
    cout << "  /         \\" << endl;
    cout << " 1          25\n"
         << endl;

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(20);
    tree.insert(1);
    tree.insert(25);

    cout << "✨ Tree built!\n"
         << endl;

    tree.inOrder();

    return 0;
}