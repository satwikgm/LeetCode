class Solution {
public:
    #define pi pair<int,int>
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        bool vis[points.size()];
        memset(vis,0,sizeof(vis));

        priority_queue<pi,vector<pi>,greater<pi>> pq;

        pq.push({0,0});   // Distance , Index
     
        int sum=0;

        while(!pq.empty())
        {
            auto p = pq.top();
            pq.pop();

            int wt = p.first;
            int index = p.second;

            int x1 = points[index][0];
            int y1 = points[index][1];

            if(vis[index])
            {
                continue;
            }
            vis[index]=1;
            sum += wt;
            for(int i=0;i<points.size();i++)
            {
                int x=points[i][0];
                int y=points[i][1];
                if(!vis[i])
                {
                    pq.push({    abs(x-x1)+abs(y-y1) , i    });
                }
            }
        }

        return sum;
    }
};
