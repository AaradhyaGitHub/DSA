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

    Node *findMin(Node *node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        cout << "successor is " << node->data << endl;
        return node;
    }

    Node *deleteHelper(Node *node, int val)
    {
        if (node == nullptr)
        {
            cout << "Value not found" << endl;
            return nullptr;
        }

        if (val < node->data)
        {
            node->left = deleteHelper(node->left, val);
        }

        else if (val > node->data)
        {
            node->right = deleteHelper(node->right, val);
        }

        else
        {
            // Found the node to delete
            cout << "Found it!\n"
                 << val << " will be deleted!\n" << endl;

            // Case 1: Node with no children (leaf node)
            if (node->left == nullptr && node->right == nullptr)
            {
                delete node;
                return nullptr;
            }

            // Case 2a: Node with only right child
            else if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }

            // Case 2b: Node with only left child
            else if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }

            // Case 3: Node with two children
            else
            {
                Node *successor = findMin(node->right);
                node->data = successor->data;
                node->right = deleteHelper(node->right, successor->data);
            }
        }
        return node;
    }

    void inOrderHelper(Node *node, vector<int> &result)
    {
        if (node == nullptr)
        {
            return;
        }

        inOrderHelper(node->left, result);

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


        vector<int> result;
        inOrderHelper(root, result);

        for (int val : result)
        {
            cout << val << " ";
        }
        cout << "\n"
             << endl;

        return result;
    }

    void deleteNode(int val)
    {
        if (root == nullptr)
        {
            cout << "❌ Tree is empty!" << endl;
            return;
        }
        root = deleteHelper(root, val);
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

    cout << "Tree before deleting:\n";
    tree.inOrder();

    tree.deleteNode(10);

    cout << "Tree after deleting:\n";
    tree.inOrder();

    cout << "\nLet's test more cases:\n" << endl;
    
    cout << "Deleting leaf node (1):\n";
    tree.deleteNode(1);
    tree.inOrder();

    cout << "Deleting node with one child (3):\n";
    tree.deleteNode(3);
    tree.inOrder();

    cout << "Deleting node with two children (15):\n";
    tree.deleteNode(15);
    tree.inOrder();

    return 0;
}