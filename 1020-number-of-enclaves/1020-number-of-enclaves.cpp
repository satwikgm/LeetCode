class Solution {
public:
    int totalOnes=0;
    int boundaryOnes=0;
    bool fun(vector<vector<int>>& grid , int i , int j , int &ones , bool vis[501][501])
    {
        bool fl=0;
        
        int m=grid.size();
        int n=grid[0].size();
        
        queue<pair<int,int>> q;
        q.push({i,j});
        
        if(i==0 || j==0 || i==m-1 || j==n-1)
        {
            fl=1;
        }
        
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        
        while(q.size())
        {
            auto p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;
            if(i==0 || j==0 || i==m-1 || j==n-1)
            {
                fl=1;
            }
            vis[i][j]=1;
            for(int k=0;k<4;k++)
            {
                int di = i + dx[k];
                int dj = j + dy[k];
                if(di>=0 && di<m && dj>=0 && dj<n && !vis[di][dj] && grid[di][dj]==1)
                {
                    q.push({di,dj});
                    vis[di][dj]=1;
                    ones++;
                    if(di==0 || dj==0 || di==m-1 || dj==n-1)
                    {
                        fl=1;;
                    }
                }
            }
        }
        return fl;
    }
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int m=grid.size(),n=grid[0].size();
        bool vis[501][501];
        memset(vis,0,sizeof(vis));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                {
                   totalOnes++; 
                }
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && grid[i][j])
                {
                    int ones=1;
                    if(fun(grid,i,j,ones,vis))
                    {
                        boundaryOnes += ones;
                    }
                }
            }
        }
        return totalOnes - boundaryOnes;
    }
};