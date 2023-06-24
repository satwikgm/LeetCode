//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool fun(vector<int> adj[] , int V , bool vis[] , int i)
    {
        queue<pair<int,int>> q;
        q.push({i,-1});
        vis[i]=1;
        while(!q.empty())
        {
            auto i=q.front();
            int u=i.first;
            int par=i.second;
            q.pop();
            for(auto it : adj[u])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    q.push({it,u});
                }
                else if(it != par)
                {
                    return 1;
                }
            }
        }
        return 0;
    }
    bool isCycle(int V, vector<int> adj[]) 
    {
        // queue<int> q;
        bool vis[V];
        memset(vis,0,sizeof(vis));
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(fun(adj,V,vis,i))
                {
                    return 1;
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends