#include<bits/stdc++.h>
using namespace std;
class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
        DisjointSet ds(n);
    while (true) {
        int x, y;
        cout << "Enter two elements to perform union operation (or enter -1 to stop): ";
        cin >> x;
        if (x == -1)
            break;
        cin >> y;
        ds.unionSets(x, y);
    }
    while (true) {
        int x, y;
        cout << "Enter two elements to check if they are in the same set (or enter -1 to stop): ";
        cin >> x;
        if (x == -1)
            break;
        cin >> y;
        cout << "Are " << x << " and " << y << " in the same set? " << (ds.find(x) == ds.find(y) ? "Yes" : "No") << endl;
    }  
  return 0;
}
