#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cout<<"Enter the number of nodes and edges: ";
    cin>>n>>m;
    vector<pair<int,int>> adj[n+1];
    cout<<"Enter the edges (start node, end node, weight): ";
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int src;
    cout<<"Enter the source node: ";
    cin>>src;
    vector<int> dist(n+1,INT_MAX);
    dist[src]=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(auto it:adj[j])
            {
                int v=it.first;
                int weight=it.second;
                if(dist[j]!=INT_MAX && dist[j]+weight<dist[v])
                {
                    dist[v]=dist[j]+weight;
                }
            }
        }
    }
    cout<<"Shortest distance from source node "<<src<<" to all other nodes is: ";
    for(int i=1;i<=n;i++)
    {
        if(dist[i]==INT_MAX)
            cout<<"INF ";
        else
            cout<<dist[i]<<" ";
    }
    return 0;
}