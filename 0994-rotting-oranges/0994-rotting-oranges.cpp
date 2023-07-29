class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        int ones=0;
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    ones++;
                }
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        
        
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,1,-1};
        
        int ans=0;
        
        while(q.size())
        {
            int count = q.size();
            if(!ones)
            {
                return ans;
            }
            ans++;
            for(int k=0;k<count;k++)
            {
                auto p = q.front();
                q.pop();
                int i = p.first;
                int j = p.second;
                grid[i][j]=0;
                for(int ctr=0;ctr<4;ctr++)
                {
                    int nr = i + dx[ctr];
                    int nc = j + dy[ctr];
                    if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc]==1)
                    {
                        ones--;
                        q.push({nr,nc});
                        grid[nr][nc]=0;
                    }
                }
            }
            
        }
        if(ones)
            return -1;
        return ans;
    }
};