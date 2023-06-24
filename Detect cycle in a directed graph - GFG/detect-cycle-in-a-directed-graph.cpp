//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool fun(vector<int> adj[] , int s , bool visited[] , bool recSt[])
    {
        visited[s]=1;
        recSt[s]=1;
        for(int i : adj[s])
        {
            if(!visited[i])
            {
                if(fun(adj,i,visited,recSt))
                {
                    return 1;
                }
            }
            else if(recSt[i]==1)
            {
                return 1;
            }
        }
        recSt[s]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) 
    {
        bool visited[V];
        memset(visited,0,sizeof(visited));
        
        bool recSt[V];
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(fun(adj,i,visited,recSt))
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

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends