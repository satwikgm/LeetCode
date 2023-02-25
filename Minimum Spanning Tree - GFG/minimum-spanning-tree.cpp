//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	#define pi pair<int,int>
    int spanningTree(int V, vector<vector<int>> adj[])
    {
         priority_queue<pi,vector<pi>,greater<pi>> pq;
         pq.push({0,0});
         
         bool visited[V];
         memset(visited,0,sizeof(visited));
         
         int ans=0;
         
         while(!pq.empty())
         {
             auto p = pq.top();
             pq.pop();
             int weight = p.first;
             int node = p.second;
             if(visited[node])
             {
                 continue;
             }
             visited[node]=1;
             ans += weight;
             for(auto it : adj[node])
             {
                 int adjNode = it[0];
                 int wt = it[1];
                 if(!visited[adjNode])
                 {
                     pq.push({wt,adjNode});
                 }
             }
         }
         return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends