//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src)
    {
        bool visited[N];
        memset(visited,0,sizeof(visited));
        vector<int> dist(N,-1);
        queue<pair<int,int>> q;
        q.push({src,0});
        visited[src]=1;
        vector<int> adj[N];
        for(auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();
            int node = p.first;
            int dis = p.second;
            visited[node]=1;
            dist[node]=dis;
            for(auto it : adj[node])
            {
                if(!visited[it])
                {
                    q.push({it,dis+1});
                    visited[it]=1;
                }
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends