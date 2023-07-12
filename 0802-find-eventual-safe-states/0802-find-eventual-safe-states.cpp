class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n=graph.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++)
        {
            for(auto it : graph[i])
            {
                adj[it].push_back(i);
            }
        }
        queue<int> q;
        vector<int> out(n,0);
        for(int i=0;i<n;i++)
        {
            out[i]=graph[i].size();
            if(out[i]==0)
            {
                q.push(i);
            }
        }
        vector<int> ans;
        while(q.size())
        {
            auto node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node])
            {
                --out[it];
                if(!out[it])
                {
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};