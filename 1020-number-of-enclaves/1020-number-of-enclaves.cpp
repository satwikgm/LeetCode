class Solution {
public:
    int bfs(vector<vector<int>>& grid , int a , int b , bool visited[501][501])
    {
        int m=grid.size();
        int n=grid[0].size();
        
        int c=1;
        
        queue<pair<int,int>> q;
        q.push({a,b});

        visited[a][b]=1;

        bool fl=0;

        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;
            visited[i][j]=1;
            if(i-1<0 || j-1<0 || i+1>=m || j+1>=n)
            {
                fl=1;
            }
            if(i-1>=0 && !visited[i-1][j] && grid[i-1][j])
            {
                q.push({i-1,j});
                visited[i-1][j]=1;
                c++;
            }
            if(j-1>=0 && !visited[i][j-1] && grid[i][j-1])
            {
                q.push({i,j-1});
                visited[i][j-1]=1;
                c++;
            }
            if(i+1<m && !visited[i+1][j] && grid[i+1][j])
            {
                q.push({i+1,j});
                visited[i+1][j]=1;
                c++;
            }
            if(j+1<n && !visited[i][j+1] && grid[i][j+1])
            {
                q.push({i,j+1});
                visited[i][j+1]=1;
                c++;
            }
        }

        if(fl)
        {
            return c;
        }

        return 0;
    }
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        int c=0;

        bool visited[501][501];
        memset(visited,0,sizeof(visited));

        int ones=0;
        int ans=0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    ones++;
                    if(!visited[i][j])
                    {
                        ans+=bfs(grid,i,j,visited);
                    }
                }
            }
        }
        return ones-ans;
    }
};