//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool fun(vector<int> adj[] , int s , bool visited[])
    {
        queue<pair<int,int>> q;
        q.push({s,-1});
        visited[s]=1;
        while(!q.empty())
        {
            int current = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto it : adj[current])
            {
                if(!visited[it])
                {
                    q.push({it,current});
                    visited[it]=1;
                }
                else if(it != parent)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) 
    {
        bool visited[V];
        memset(visited,0,sizeof(visited));
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(fun(adj,i,visited))
                {
                    return true;
                }
            }
        }
        
        return false;
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