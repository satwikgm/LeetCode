class Solution {
public:
    bool fun(int n , vector<int> adj[n] , bool vis[n] , int i)
    {
        queue<int> q;
        q.push(i);
        int nodes = 1 , edges = 0;
        vis[i]=1;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto it : adj[node])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    q.push(it);
                    nodes++;
                }
                edges++;
            }
        }
        if(nodes<=2)
            return 1;
        return (edges/2 == (nodes*(nodes-1))/2);
        
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) 
    {
        if(edges.size()==0)
        {
            return n;
        }
        bool vis[n];
        memset(vis,0,sizeof(vis));
        vector<int> adj[n];
        for(auto i : edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(fun(n,adj,vis,i))
                    ans++;
            }
        }
        return ans;
    }
};