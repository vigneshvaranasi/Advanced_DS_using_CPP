#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cout<<"Enter the number of nodes and edges: ";
    cin>>n>>m;
    vector<int> adj[n];
    vector<int> indegree(n,0);
    cout<<"Enter the edges: ";
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(auto it:adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
            {
                q.push(it);
            }
        }
    }
    cout<<"Topological Sort: ";
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    return 0;
}
/* 
5 6
1 2
1 4
2 4
2 3
4 3
4 5
 */

