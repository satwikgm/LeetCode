//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    #define pi pair<int,int>
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> ans(V,INT_MAX);
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        pq.push({0,S});     // dis node
        ans[S]=0;
        while(pq.size())
        {
            auto p = pq.top();
            pq.pop();
            int node = p.second;
            int dis = p.first;
            // ans[node]=dis;
            for(auto it : adj[node])
            {
                int nod = it[0];
                int dist = it[1];
                if(dis+dist < ans[nod])
                {
                    ans[nod] = dis+dist;
                    pq.push({ans[nod] , nod});
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends