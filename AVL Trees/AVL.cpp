#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    int height;
    Node(int data_)
    {
        data = data_;
        left = right = NULL;
        height = 1;
    }
};

Node *root = NULL;

class AVL
{
public:
    int height(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        return node->height;
    }

    int balanceFactor(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        return height(node->left) - height(node->right);
    }

    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));
        return x;
    }

    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));
        return y;
    }

    Node *insert(Node *node, int data)
    {
        if (node == NULL)
        {
            return new Node(data);
        }
        if (data < node->data)
        {
            node->left = insert(node->left, data);
        }
        else if (data > node->data)
        {
            node->right = insert(node->right, data);
        }
        else
        {
            return node;
        }
        node->height = 1 + max(height(node->left), height(node->right));
        int balance = balanceFactor(node);
        if (balance > 1 && data < node->left->data)
        {
            return rightRotate(node);
        }
        if (balance < -1 && data > node->right->data)
        {
            return leftRotate(node);
        }
        if (balance > 1 && data > node->left->data)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && data < node->right->data)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }
    void insert(int data)
    {
        root = insert(root, data);
    }
    void inorder(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
    void Search(int data)
    {
        Node *temp = root;
        while (temp != NULL)
        {
            if (temp->data == data)
            {
                cout << "Data found" << endl;
                return;
            }
            else if (temp->data > data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        cout << "Data not found" << endl;
    }
};

int main()
{
    AVL tree;
    int choice,element;
    while (1)
    {
        cout << "1. Insert"<<endl;
        cout << "2. Delete"<<endl;
        cout << "3. Inorder"<<endl;
        cout << "4. Search"<<endl;
        cout << "5. Exit"<<endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter data: ";
            cin >> element;
            tree.insert(element);
            break;
        case 2:
            break;
        case 3:
            tree.inorder(root);
            break;
        case 4:
            cout << "Enter Element to search: ";
            cin >> element;
            tree.Search(element);
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } 
    return 0;
}
