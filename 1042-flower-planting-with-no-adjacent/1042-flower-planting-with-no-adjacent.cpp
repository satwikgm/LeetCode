class Solution {
public:
    bool isSafe(int col , vector<int> adj[] , int node , vector<int> ans)
    {
        for(auto it : adj[node])
        {
            if(ans[it]==col)
            {
                return 0;
            }
        }
        return 1;
    }
    bool fun(int n , int node , vector<int> &ans , vector<int> adj[]  )
    {
        if(node==n)
        {
            return 1;
        }
        for(int col=1;col<=4;col++)
        {
            if(isSafe(col , adj , node , ans))
            {
                ans[node]=col;
                if(fun(n,node+1,ans,adj))
                {
                    return 1;
                }
                ans[node]=0;
            }
        }
        return 0;
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) 
    {
        vector<int> ans(n,0);
        vector<int> adj[n];
        for(auto it : paths)
        {
            adj[it[0]-1].push_back(it[1]-1);
            adj[it[1]-1].push_back(it[0]-1);
        }
        if(fun(n,0,ans,adj))
        {
            return ans;
        }
        return {};
    }
};