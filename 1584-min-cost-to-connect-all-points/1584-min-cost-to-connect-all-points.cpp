class Solution {
public:
    #define pi pair<int,int>
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        bool vis[points.size()];
        memset(vis,0,sizeof(vis));
        
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        pq.push({0,0});  // Dist , Index
        
        int ans=0;
        while(!pq.empty())
        {
            auto p = pq.top();
            pq.pop();
            int dis = p.first;
            int idx = p.second;
            if(vis[idx])
            {
                continue;
            }
            ans+=dis;
            vis[idx]=1;
            
            int x = points[idx][0];
            int y = points[idx][1];
            
            for(int i=0;i<points.size();i++)
            {
                if(vis[i])
                {
                    continue;
                }
                pq.push({ abs(points[i][0]-x)+abs(points[i][1]-y) , i});
            }
        }
        return ans;
    }
};