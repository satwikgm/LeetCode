class Solution {
public:
    #define pi pair<int,int>
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<vector<int>> adj[n];
        for(auto it : times)
        {
            adj[it[0] - 1].push_back({it[1]-1 , it[2]});
        }

        vector<int> dist(n,1e9);
        dist[k-1]=0;
        
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        pq.push({0,k-1});       // dist node       
        
        while(pq.size())
        {
            auto p = pq.top();
            pq.pop();
            int dis = p.first;
            int node = p.second;
            for(auto it : adj[node])
            {
                int wt = it[1];
                int adjNode = it[0];
                if(dist[adjNode] > dis + wt)
                {
                    dist[adjNode] = dis+wt;
                    pq.push({dist[adjNode] , adjNode});
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(dist[i]==1e9)
            {
                return -1;
            }
            ans=max(ans,dist[i]);
        }
        
        return ans;
        
    }   
};