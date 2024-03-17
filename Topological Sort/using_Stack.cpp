#include<bits/stdc++.h>
using namespace std;

void topologicalSortUtil(int v, vector<int> adj[], bool visited[], stack<int> &Stack) {
    visited[v] = true;
    for (auto i = adj[v].rbegin(); i != adj[v].rend(); ++i) {
        if (!visited[*i]) {
            topologicalSortUtil(*i, adj, visited, Stack);
        }
    }
    Stack.push(v);
}

void topologicalSort(int n, vector<int> adj[]) {
    stack<int> Stack;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            topologicalSortUtil(i, adj, visited, Stack);
        }
    }

    cout << "Topological Sort: ";
    while (!Stack.empty()) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
    cout << endl;

    delete[] visited;
}

int main() {
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    vector<int> adj[n];

    cout << "Enter the edges: ";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    topologicalSort(n, adj);

    return 0;
}
