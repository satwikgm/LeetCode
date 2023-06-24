//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool fun(vector<int> adj[] , int s , bool vis[] , int par , int V)
    {
        vis[s]=1;
        for(auto it : adj[s])
        {
            if(!vis[it])
            {
                vis[it]=1;
                if(fun(adj,it,vis,s,V))
                {
                    return 1;
                }
            }
            else if(it != par)
            {
                return 1;
            }
        }
        return 0;
    }
    bool isCycle(int V, vector<int> adj[]) 
    {
        bool vis[V];
        memset(vis,0,sizeof(vis));
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                vis[i]=1;
                if(fun(adj,i,vis,-1,V))
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