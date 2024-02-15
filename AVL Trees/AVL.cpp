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

    Node* rightRotate(Node* currentNode) {
        Node* leftChild = currentNode->left;
        Node* rightSubtreeOfLeftChild = leftChild->right;
        leftChild->right = currentNode;
        currentNode->left = rightSubtreeOfLeftChild;
        currentNode->height = max(height(currentNode->left), height(currentNode->right)) + 1;
        leftChild->height = max(height(leftChild->left), height(leftChild->right)) + 1;
        return leftChild;
    }

    Node* leftRotate(Node* currentNode) {
        Node* rightChild = currentNode->right;
        Node* leftSubtreeOfRightChild = rightChild->left;
        rightChild->left = currentNode;
        currentNode->right = leftSubtreeOfRightChild;
        currentNode->height = max(height(currentNode->left), height(currentNode->right)) + 1;
        rightChild->height = max(height(rightChild->left), height(rightChild->right)) + 1;
        return rightChild;
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
    Node * Delete(Node *node, int data)
    {
        if (node == NULL)
        {
            return node;
        }
        if (data < node->data)
        {
            node->left = Delete(node->left, data);
        }
        else if (data > node->data)
        {
            node->right = Delete(node->right, data);
        }
        else
        {
            if (node->left == NULL || node->right == NULL)
            {
                Node *temp = node->left ? node->left : node->right;
                if (temp == NULL)
                {
                    temp = node;
                    node = NULL;
                }
                else
                {
                    *node = *temp;
                }
                free(temp);
            }
            else
            {
                Node *temp = node->right;
                while (temp->left != NULL)
                {
                    temp = temp->left;
                }
                node->data = temp->data;
                node->right = Delete(node->right, temp->data);
            }
        }
        if (node == NULL)
        {
            return node;
        }
        node->height = 1 + max(height(node->left), height(node->right));
        int balance = balanceFactor(node);
        if (balance > 1 && balanceFactor(node->left) >= 0)
        {
            return rightRotate(node);
        }
        if (balance > 1 && balanceFactor(node->left) < 0)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && balanceFactor(node->right) <= 0)
        {
            return leftRotate(node);
        }
        if (balance < -1 && balanceFactor(node->right) > 0)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }
    void Delete(int data)
    {
        root = Delete(root, data);
    }
};

int main()
{
    AVL tree;
    int choice,element;
    while (1)
    {
        cout << "\n1. Insert\n2. Delete\n3. Inorder\n4. Search\n5. Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter data: ";
            cin >> element;
            tree.insert(element);
            break;
        case 2:
            cout << "Enter data: ";     
            cin >> element;
            tree.Delete(element);   
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
