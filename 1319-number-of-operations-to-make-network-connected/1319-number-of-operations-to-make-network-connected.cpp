class Solution {
public:
    void bfs(vector<int> adj[] , bool vis[] ,int i)
    {
        queue<int> q;
        q.push(i);
        vis[i]=1;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto it : adj[node])
            {
                if(!vis[it])
                {
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        if(connections.size()<n-1)
        {
            return -1;
        }
        vector<int> adj[n];
        for(auto it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans=0;
        bool vis[n];
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                ans++;
                bfs(adj,vis,i);
            }
        }
        return ans-1;
    }
};