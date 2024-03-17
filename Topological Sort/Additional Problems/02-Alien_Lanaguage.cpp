#include<bits/stdc++.h>
using namespace std;

void buildGraph(vector<string>& words, unordered_map<char, unordered_set<char>>& graph) {
    for (int i = 0; i < words.size() - 1; ++i) {
        string word1 = words[i];
        string word2 = words[i + 1];
        int minLength = min(word1.length(), word2.length());
        for (int j = 0; j < minLength; ++j) {
            if (word1[j] != word2[j]) {
                graph[word1[j]].insert(word2[j]);
                break;
            }
        }
    }
}

vector<char> alienOrder(vector<string>& words) {
    unordered_map<char, unordered_set<char>> graph;
    buildGraph(words, graph);
    unordered_map<char, int> indegree;
    for (const auto& kvp : graph) {
        for (char c : kvp.second) {
            indegree[c]++;
        }
    }
    queue<char> q;
    for (const auto& kvp : graph) {
        if (indegree.find(kvp.first) == indegree.end()) {
            q.push(kvp.first);
        }
    }
    vector<char> order;
    while (!q.empty()) {
        char u = q.front();
        q.pop();
        order.push_back(u);
        for (char v : graph[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }
    if (order.size() != graph.size()) {
        return {}; 
    }
    return order;
}
int main() {
    vector<string> words1 = {"baa", "abcd", "abca", "cab", "cad"};
    vector<char> order1 = alienOrder(words1);
    cout << "Order of characters is: ";
    for (char c : order1) {
        cout << c << " ";
    }
    cout << endl;
    vector<string> words2 = {"caa", "aaa", "aab"};
    vector<char> order2 = alienOrder(words2);
    cout << "Order of characters is: ";
    for (char c : order2) {
        cout << c << " ";
    }
    cout << endl;
    return 0;
}
