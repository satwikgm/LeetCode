class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) 
    {
        vector<pair<int,double>> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({ edges[i][1] , succProb[i] });
            adj[edges[i][1]].push_back({ edges[i][0] , succProb[i] });
        }
        priority_queue<pair<int,double>> pq;
        pq.push({start,1.0});
        vector<double> probab(n,0.0);
        probab[start]=1.0;
        while(!pq.empty())
        {
            auto node = pq.top().first;
            auto prob = pq.top().second;
            pq.pop();
            for(auto i : adj[node])
            {
                if(probab[i.first] < i.second*prob)
                {
                    probab[i.first] = i.second*prob;
                    pq.push({ i.first , (double)i.second*(double)prob });       
                }
            }
        }
        return probab[end];
    }
};