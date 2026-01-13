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
            cout << "❌ " << val << " already exists! Skipping..." << endl;
        }

        return node;
    };

    Node *deleteLeafHelper(Node *node, int val)
    {
        if (node == nullptr)
        {
            cout << "Value to delete does not exist or is not a leaf!" << endl;
            return nullptr;
        }

        if (node->data == val && node->left == nullptr && node->right == nullptr)
        {
            cout << "Node to delete: " << val << " found!" << endl;
            int temp = node->data;
            delete node;
            cout << temp << " was successfully deleted..." << endl;
            return nullptr;
        };

        if (val < node->data)
        {
            node->left = deleteLeafHelper(node->left, val);
        }
        else if (val > node->data)
        {
            node->right = deleteLeafHelper(node->right, val);
        }

        return node;
    }

    void inOrderSearchHelper(Node *node, vector<int> &result)
    {
        if (node == nullptr)
        {
            cout << "   🚫 Reached nullptr - returning" << endl;
            return;
        }

        cout << "   📍 Visiting node: " << node->data << endl;
        inOrderSearchHelper(node->left, result);

        cout << "   ✅ Adding " << node->data << " to result" << endl;
        result.push_back(node->data);

        inOrderSearchHelper(node->right, result);
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

    vector<int> inOrderSearch()
    {
        if (root == nullptr)
        {
            cout << "❌ Empty tree, cannot traverse!" << endl;
            return {};
        }

        cout << "\n🔍 Starting In-Order Traversal" << endl;
        cout << "================================================\n"
             << endl;

        vector<int> result;
        inOrderSearchHelper(root, result);

        cout << "\n================================================" << endl;
        cout << "✨ Traversal complete!" << endl;
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

    tree.inOrderSearch();

    cout << "🗑️ Deleting the leaf now...\n"
         << endl;

    tree.deleteLeaf(1);

    cout << "🗑️ After deleteing the leaf...\n"
         << endl;
    tree.inOrderSearch();

    tree.deleteLeaf(99);
    return 0;
}