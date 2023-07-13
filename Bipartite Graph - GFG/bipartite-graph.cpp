//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool fun(int start , vector<int> adj[] , int color[] , int V)
    {
        queue<int> q;
        q.push(start);
        color[start]=0;
        while(q.size())
        {
            auto node = q.front();
            q.pop();
            for(auto it : adj[node])
            {
                if(color[it]==-1)
                {
                    q.push(it);
                    if(color[node]==0)
                    {
                        color[it]=1;
                    }
                    else
                    {
                        color[it]=0;
                    }
                }
                else
                {
                    if(color[it]==color[node])
                    {
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
	bool isBipartite(int V, vector<int>adj[])
	{
	    int color[V];
	    memset(color,-1,sizeof(color));
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1)
	        {
	            if(fun(i,adj,color,V))
	            {
	                return 0;
	            }
	        }
	    }
	    return 1;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends