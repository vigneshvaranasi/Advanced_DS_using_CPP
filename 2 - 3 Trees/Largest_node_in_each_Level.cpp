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
    void display() { display(root, "Root", 0); }

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
            return new Node(data);

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

    void findMaxInLevels()
    {
        if (!root)
            return;
        queue<Node *> q;
        q.push(root);
        int level = 1;
        while (!q.empty())
        {
            int n = q.size();
            int maxVal = INT_MIN; 
            for (int i = 0; i < n; ++i)
            {
                Node *node = q.front();
                q.pop();
                maxVal = max(maxVal, node->data);
                if (node->left)
                    q.push(node->left);
                if (node->middle)
                    q.push(node->middle);
                if (node->right)
                    q.push(node->right);
            }
            cout << "Max in Level " << level++ << " : " << maxVal << endl;
        }
    }
};

int main()
{
    TwoThreeTree tree;
    int element;
    while (1)
    {
        cout << "1. Insert\n2. Display\n3. Find Max in Levels\n4. Exit\n";
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
            tree.display();
            cout << endl;
            break;
        case 3:
            tree.findMaxInLevels();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
        }
    }
}
