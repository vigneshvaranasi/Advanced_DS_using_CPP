#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *middle, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->middle = this->right = NULL;
    }
};
class TwoThreeTree
{
public:
    Node *root;
    TwoThreeTree() { root = NULL; }
    void insert(int data) { root = insert(root, data); }
    void search(int data) { search(root, data); }
    void display()
    {
        display(root, "Root", 0);
    }
    void display(Node *root, string relation, int level)
    {
        if (!root)
            return;
        cout << string(level * 4, ' ') << relation << " Node = " << root->data << endl;
        if (root->left)
            display(root->left, "Left", level + 1);
        if (root->middle)
            display(root->middle, "Middle", level + 1);
        if (root->right)
            display(root->right, "Right", level + 1);
    }

    Node *insert(Node *root, int data)
    {
        if (!root)
        {
            return new Node(data);
        }

        if (!root->left)
        {
            if (!root->middle)
            {
                if (data < root->data)
                {
                    root->middle = new Node(root->data);
                    root->data = data;
                }
                else
                {
                    root->middle = new Node(data);
                }
            }
            else
            {
                if (data < root->data)
                {
                    root->left = new Node(data);
                }
                else if (data > root->data && data < root->middle->data)
                {
                    root->left = new Node(root->data);
                    root->data = data;
                }
                else
                {
                    root->left = new Node(root->data);
                    root->data = root->middle->data;
                    root->middle->data = data;
                }
            }
        }
        else
        {
            if (data < root->data)
            {
                root->left = insert(root->left, data);
            }
            else if (data > root->data && (!root->middle || data < root->middle->data))
            {
                root->middle = insert(root->middle, data);
            }
            else
            {
                root->right = insert(root->right, data);
            }
        }

        return root;
    }
    void remove(int data) { root = remove(root, data); }

    Node *remove(Node *root, int data)
    {
        if (!root)
            return NULL;

        if (root->data == data)
        {
            if (root->right)
            {
                Node *minNode = findMin(root->right);
                root->data = minNode->data;
                root->right = remove(root->right, minNode->data);
            }
            else if (root->middle)
            {
                Node *minNode = findMin(root->middle);
                root->data = minNode->data;
                root->middle = remove(root->middle, minNode->data);
            }
            else if (root->left)
            {
                Node *minNode = findMin(root->left);
                root->data = minNode->data;
                root->left = remove(root->left, minNode->data);
            }
            else
            {
                delete root;
                return NULL;
            }
        }
        else if (root->data > data)
        {
            root->left = remove(root->left, data);
        }
        else if (root->middle && root->middle->data <= data)
        {
            root->middle = remove(root->middle, data);
        }
        else
        {
            root->right = remove(root->right, data);
        }

        return root;
    }

    Node *findMin(Node *node)
    {
        while (node->left)
            node = node->left;
        return node;
    }
    void search(Node *root, int data)
    {
        if (!root)
        {
            cout << "Not Found" << endl;
            return;
        }

        if (root->data == data)
        {
            cout << "Found" << endl;
            return;
        }

        if (root->left && data < root->data)
        {
            search(root->left, data);
        }
        else if (root->middle && data >= root->data && (!root->right || data < root->right->data))
        {
            search(root->middle, data);
        }
        else if (root->right && data >= root->right->data)
        {
            search(root->right, data);
        }
        else
        {
            cout << "Not Found" << endl;
        }
    }
};
int main()
{
    TwoThreeTree tree;
    int element;
    while (1)
    {
        cout << "1. Insert\n2. Remove\n3. Search\n4. Display\n5. Exit\n";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter element to insert: ";
            cin >> element;
            tree.insert(element);
            break;
        case 2:
            cout << "Enter element to remove: ";
            cin >> element;
            tree.remove(element);
            break;
        case 3:
            cout << "Enter element to search: ";
            cin >> element;
            tree.search(element);
            break;
        case 4:
            tree.display();
            cout << endl;
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
        }
    }
}