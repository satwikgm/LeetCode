class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        vector<int> adj[n];
        for(int i=0;i<n;i++)
        {
            if(manager[i]==-1)
                continue;
            adj[manager[i]].push_back(i);
        }
        queue<pair<int,int>> q;
        q.push({headID,0});
        int ans=0;
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            for(auto it : adj[p.first])
            {
                q.push({it,p.second+informTime[p.first]});
                ans = max(ans , p.second+informTime[p.first]);
            }
        }
        return ans;
    }
};