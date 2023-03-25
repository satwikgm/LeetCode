class Solution {
public:
    #define ll long long
    long long fun(vector<ll> adj[] , int n , int i , vector<bool> &visited)
    {
        queue<ll> q;
        q.push(i);
        long long c=1;
        visited[i]=1;
        while(!q.empty())
        {
            ll node = q.front();
            q.pop();
            for(auto it : adj[node])
            {
                if(!visited[it])
                {
                    visited[it]=1;
                    q.push(it);
                    c++;
                }
            }
        }
        return c;
    }
    long long countPairs(int n, vector<vector<int>>& edges) 
    {
        long long ans=0;
        vector<ll> adj[n];
        for(auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> visited(n,0);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                ll c = fun(adj,n,i,visited);
                ans += c*(n-c);
            }
        }
        return ans/2;
    }
};