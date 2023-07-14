class Solution {
public:
    #define ppi pair<int,pair<int,int>> 
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> adj[n];         // from to dist
        for(auto it : flights)
        {
            adj[it[0]].push_back({it[1] , it[2]});
        }
        priority_queue<ppi,vector<ppi>,greater<ppi>> pq;
        pq.push({0, {0,src}});          // dist stops node 
        vector<int> stop(n,INT_MAX);
        while(pq.size())
        {
            auto p = pq.top();
            pq.pop();
            int dis = p.first;
            int stops = p.second.first;
            int node = p.second.second;
            if(stops > stop[node] || stops>k+1)
            {
                continue;
            }
            stop[node] = stops;
            if(node == dst)
            {
                return dis;
            }
            for(auto it : adj[node])
            {
                pq.push( {dis+it[1], {stops+1 ,it[0]} });
            }
        }
        return -1;
    }
};