#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *middle, *right;
    Node(int data) {
        this->data = data;
        this->left = this->middle = this->right = NULL;
    }
};

class TwoThreeTree {
public:
    Node *root;
    TwoThreeTree() { root = NULL; }

    void insert(int data) { root = insert(root, data); }
    void display() { display(root, "Root", 0); }

    void display(Node *root, string relation, int level) {
        if (!root) return;
        cout << string(level * 4, ' ') << relation << " Node = " << root->data << endl;
        if (root->left) display(root->left, "Left", level + 1);
        if (root->middle) display(root->middle, "Middle", level + 1);
        if (root->right) display(root->right, "Right", level + 1);
    }

    Node *insert(Node *root, int data) {
        if (!root) return new Node(data);

        if (!root->left) {
            if (!root->middle) {
                if (data < root->data) {
                    root->middle = new Node(root->data);
                    root->data = data;
                } else {
                    root->middle = new Node(data);
                }
            } else {
                if (data < root->data) {
                    root->left = new Node(data);
                } else if (data > root->data && data < root->middle->data) {
                    root->left = new Node(root->data);
                    root->data = data;
                } else {
                    root->left = new Node(root->data);
                    root->data = root->middle->data;
                    root->middle->data = data;
                }
            }
        } else {
            if (data < root->data) {
                root->left = insert(root->left, data);
            } else if (data > root->data && (!root->middle || data < root->middle->data)) {
                root->middle = insert(root->middle, data);
            } else {
                root->right = insert(root->right, data);
            }
        }

        return root;
    }

    void printPaths() {
        vector<int> path;
        printPaths(root, path);
    }

    void printPaths(Node *root, vector<int> &path) {
        if (!root) return;
        path.push_back(root->data);
        if (!root->left && !root->middle && !root->right) {
            // Leaf node reached, print the path
            printPath(path);
        } else {
            printPaths(root->left, path);
            printPaths(root->middle, path);
            printPaths(root->right, path);
        }
        path.pop_back();
    }

    void printPath(const vector<int> &path) {
        for (int i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i < path.size() - 1) cout << " -> ";
        }
        cout << endl;
    }
};

int main() {
    TwoThreeTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(20);
    tree.insert(15);
    tree.insert(25);
    tree.insert(3);
    tree.insert(7);

    cout << "All possible paths from root to leaf nodes:" << endl;
    tree.printPaths();

    return 0;
}
