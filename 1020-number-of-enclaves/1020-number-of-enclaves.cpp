class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    ans++;
                    if((i==0 || j==0 || i==m-1 || j==n-1))
                    {
                        q.push({i,j});
                    }
                }
            }
        }
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,1,-1};
        while(q.size())
        {
            auto p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;
            if(grid[i][j]==0)
                continue;
            --ans;
            grid[i][j]=0;
            for(int k=0;k<4;k++)
            {
                int nr = i+dx[k] , nc = j+dy[k];
                if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc]==1)
                {
                    q.push({nr,nc});
                }
            }
        }
        return ans;
    }
};