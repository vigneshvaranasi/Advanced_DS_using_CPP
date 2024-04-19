#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void bellmanFord(int n, vector<vector<int>>& edges, int src) {
    vector<int> dist(n + 1, INT_MAX);
    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (auto edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    cout << "Shortest distances from source node " << src << " to all other nodes:\n";
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }
}

int main() {
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(3));
    cout << "Enter the edges (start node, end node, weight):\n";
    for (int i = 0; i < m; i++)
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    int src;
    cout << "Enter the source node: ";
    cin >> src;

    bellmanFord(n, edges, src);

    return 0;
}
