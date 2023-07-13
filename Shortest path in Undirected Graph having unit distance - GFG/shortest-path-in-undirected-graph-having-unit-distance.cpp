//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    #define pi pair<int,int>
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src)
    {
        vector<int> adj[N];
        bool vis[N]={0};
        for(auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> ans(N,1e9);
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        pq.push({0,src});
        vis[src]=1;
        ans[src]=0;
        vis[src]=1;
        while(pq.size())
        {
            auto p = pq.top();
            pq.pop();
            int dis = p.first;
            int node = p.second;
            ans[node]=dis;
            for(auto it : adj[node])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    pq.push({dis+1,it});
                }
            }
        }
        for(int i=0;i<N;i++)
        {
            if(ans[i]==1e9)
            {
                ans[i]=-1;
            }
        }
        return ans;
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