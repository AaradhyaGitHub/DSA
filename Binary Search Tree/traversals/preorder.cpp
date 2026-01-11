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
            cout << node->data << " already exists in the tree! Skipping..." << endl;
        }

        return node;
    }

    void preOrderSearchHelper(Node *node, vector<int> &result)
    {
        if (node == nullptr)
        {
            cout << "   🚫 Reached nullptr - returning" << endl;
            return;
        }

        cout << "  📍 Visiting node: " << node->data << endl;

        cout << "  ➕ Adding " << node->data << " to result" << endl;
        result.push_back(node->data);

        cout << "  ⬅️ Going LEFT from " << node->data << endl;
        preOrderSearchHelper(node->left, result);

        cout << "  ➡️ Going RIGHT from " << node->data << endl;
        preOrderSearchHelper(node->right, result);
    };

    void destroyTree(Node *node)
    {
        if (node != nullptr)
        {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }
    // helper functiions + deconstructor

public:
    BST()
    {
        root = nullptr;
    }

    void insert(int val)
    {
        root = insertHelper(root, val);
    }

    vector<int> preOrderSearch()
    {
        if (root == nullptr)
        {
            cout << "❌ Empty tree, cannot traverse!" << endl;
            return {};
        }
        cout << "\n🔍 Starting Pre-Order Traversal (Root → Left → Right)" << endl;
        cout << "================================================\n"
             << endl;

        vector<int> result;
        preOrderSearchHelper(root, result);

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
    };

    ~BST()
    {
        destroyTree(root);
    }
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

    cout << "Running post order search\n"
         << endl;
    
    tree.preOrderSearch();

    return 0;
}