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
        if (node == nullptr) // ← Fixed: was checking root instead of node
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
    }

    Node *deleteOneChildHelper(Node *node, int val)
    {
        if (node == nullptr)
        {
            cout << val << " does not exist. Nothing deleted" << endl;
            return nullptr;
        }

        if (val < node->data)
        {
            node->left = deleteOneChildHelper(node->left, val);
        }
        else if (val > node->data)
        {
            node->right = deleteOneChildHelper(node->right, val);
        }
        else
        {
            bool hasOnlyLeft = (node->left != nullptr && node->right == nullptr);
            bool hasOnlyRight = (node->right != nullptr && node->left == nullptr);

            if (hasOnlyLeft || hasOnlyRight)
            {
                Node *temp = (hasOnlyLeft) ? node->left : node->right;
                delete node;
                return temp;
            }

            else
            {
                cout << "❌ Node has 0 or 2 children. Nothing deleted." << endl;
                return node;
            }
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
    }

    void deleteOneChild(int val)
    {
        if (root == nullptr)
        {
            cout << "❌ Tree is empty!" << endl;
            return;
        }
        root = deleteOneChildHelper(root, val);
    }

    vector<int> inOrderSearch()
    {
        if (root == nullptr)
        {
            cout << "❌ Empty tree!" << endl;
            return {};
        }

        cout << "\n🔍 In-Order Traversal" << endl;
        cout << "========================" << endl;

        vector<int> result;
        inOrderSearchHelper(root, result);

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

    tree.inOrderSearch();

    cout << "🗑️ Deleting node 3 (has ONE child: left = 1)...\n"
         << endl;
    tree.deleteOneChild(3);

    cout << "After deletion:" << endl;
    tree.inOrderSearch();

    cout << "🗑️ Deleting node 20 (has ONE child: right = 25)...\n"
         << endl;
    tree.deleteOneChild(20);

    cout << "After deletion:" << endl;
    tree.inOrderSearch();

    return 0;
}

/*
1. is node nullptr -> value not found
2. if/else if -> drill down left and right
3. else -> store hasOnlyLeft and hasOnlyRight:
    i) left is not empty and right is empty -> left exists
    ii) right is not empty and left is empty -> right exists

4. If either left or right exists:

        Set temp conditionally based on hasOnlyLeft. We know exactly one of
        hasOnlyLeft or hasOnlyRight must be true because of the || condition above,
        so checking hasOnlyLeft tells us which child exists.

5. else -> node has 0 or 2 children. Nothing to delete
*/