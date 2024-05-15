#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> ranks;

int findPar(int node) {
    if (node == parent[node]) {
        return node;
    }
    return parent[node] = findPar(parent[node]); // Path compression
}

void smartUnion(int u, int v) {
    u = findPar(u);
    v = findPar(v);
    if (ranks[u] < ranks[v]) {
        parent[u] = v;
    } 
    else if (ranks[v] < ranks[u]) {
        parent[v] = u;
    } 
    else {
        parent[v] = u;
        ranks[u]++;
    }
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    parent.resize(n);
    ranks.resize(n, 0);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }

    int choice;
    do {
        cout << "\nMenu:\n1. Find\n2. Union\n3. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int node;
                cout << "Enter the value of the node for find operation: ";
                cin >> node;
                cout << "Parent of " << node << ": " << findPar(node) << endl;
                break;
            }
            case 2: {
                int u, v;
                cout << "Enter values for u and v (separated by space) for union operation: ";
                cin >> u >> v;
                smartUnion(u, v);
                cout << "Union performed." << endl;
                break;
            }
            case 3:
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 3);

    return 0;
}
