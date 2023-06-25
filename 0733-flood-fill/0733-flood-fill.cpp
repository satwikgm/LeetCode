class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int orig=image[sr][sc];
        
        int m=image.size();
        int n=image[0].size();
        
        bool vis[m][n];
        memset(vis,0,sizeof(vis));
        
        queue<pair<int,int>> q;
        q.push({sr,sc});
                
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        
        while(q.size())
        {
            auto p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;
            vis[i][j]=1;
            image[i][j]=color;
            for(int k=0;k<4;k++)
            {
                int di = i + dx[k];
                int dj = j + dy[k];
                if(di>=0 && di<m && dj>=0 && dj<n && image[di][dj] == orig && !vis[di][dj])
                {
                    q.push({di,dj});
                    vis[di][dj]=1;
                }
            }
        }
        return image;
    }
};