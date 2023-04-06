class Solution {
public:
    int fun(vector<vector<int>>& grid, int a,int b, bool visited[101][101])
    {
        int m=grid.size();
        int n=grid[0].size();
        visited[a][b]=1;
        queue<pair<int,int>> q;
        q.push({a,b});
        bool fl=0;
        if(a==0 || b==0 || a==m-1 || b==n-1)
        {
            fl=1;
        }
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;
            visited[i][j]=1;
            if(i==0 || j==0 || i==m-1 || j==n-1)
            {
                fl=1;
            }
            // if(i-1==0 && grid[i-1][j]==0)
            // {
            //     fl=1;
            // }
            // if(j-1==0 && grid[i][j-1]==0)
            // {
            //     fl=1;
            // }
            // if(i+1==m-1 && grid[i+1][j]==0)
            // {
            //     fl=1;
            // }
            // if(j+1==n-1 && grid[i][j+1]==0)
            // {
            //     fl=1;
            // }
            if(i-1>=0 && grid[i-1][j]==0 && !visited[i-1][j])
            {
                q.push({i-1,j});
                visited[i-1][j]=1;
            }
            if(i+1<m && grid[i+1][j]==0 && !visited[i+1][j])
            {
                q.push({i+1,j});
                visited[i+1][j]=1;
            }
            if(j-1>=0 && grid[i][j-1]==0 && !visited[i][j-1])
            {
                q.push({i,j-1});
                visited[i][j-1]=1;
            }
            if(j+1<n && grid[i][j+1]==0 && !visited[i][j+1])
            {
                q.push({i,j+1});
                visited[i][j+1]=1;
            }
        }
        if(fl)
        {
            return 0;
        }
        return 1;
    }
    int closedIsland(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         if(i==0 || j==0 || i==m-1 || j==n-1)
        //         {
        //             grid[i][j]=1;
        //         }
        //     }
        // }
        
        bool visited[101][101];
        memset(visited,0,sizeof(visited));

        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    if(!visited[i][j])
                    {
                        ans += fun(grid,i,j,visited);
                    }
                }
            }
        }
        return ans;
    }
};