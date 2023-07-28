class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size() , n = grid[0].size();
        int ans=0;
        queue<pair<int,int>> q;
        bool vis[m][n];
        memset(vis,0,sizeof(vis));
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,1,-1};
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    vis[i][j]=1;
                    q.push({i,j});
                    ans++;
                    while(q.size())
                    {
                        auto p = q.front();
                        q.pop();
                        int x = p.first;
                        int y = p.second;
                        for(int k=0;k<4;k++) {
                            int nx = x+dx[k];
                            int ny = y+dy[k];
                            if(nx>=0 && ny>=0 && nx<m && ny<n && !vis[nx][ny] && grid[nx][ny]=='1')
                            {
                                q.push({nx,ny});
                                vis[nx][ny]=1;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};