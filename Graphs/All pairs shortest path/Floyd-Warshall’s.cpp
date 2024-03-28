#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cout<<"Enter the number of vertices and edges: ";
    cin>>n>>m;
    vector<vector<int>> dist(n+1,vector<int>(n+1,INT_MAX));
    for(int i=1;i<=n;i++)
        dist[i][i]=0;
    cout<<"Enter the edges and their weights: \n";
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        dist[u][v]=w;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX)
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    cout<<"The shortest distance matrix is: \n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<dist[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}