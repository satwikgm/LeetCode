class Solution {
public:
    #define v vector
    int fun(int i , int j1 , int j2 , vector<vector<int>>& grid , int m , int n , v<v<v<int>>> &dp)
    {
        if(i<0 || i>=m || j1<0 || j1>=n || j2<0 || j2>=n)
        {
            return -1e9;
        }
        if(i==m-1)
        {
            if(j1==j2)
            {
                return grid[i][j1];
            }
            else
            {
                return grid[i][j1]+grid[i][j2];
            }
        }
        if(dp[i][j1][j2] != -1)
        {
            return dp[i][j1][j2];
        }
        int ans=INT_MIN;
        for(int dj1=-1;dj1<=1;dj1++)
        {
            for(int dj2=-1;dj2<=1;dj2++)
            {
                int temp;
                if(j1==j2)
                {
                    temp = grid[i][j1] + fun(i+1,j1+dj1,j2+dj2,grid,m,n,dp);
                }
                else
                {
                    temp = grid[i][j1]+grid[i][j2]+fun(i+1,j1+dj1,j2+dj2,grid,m,n,dp);
                }
                ans=max(ans,temp);
            }
        }
        return dp[i][j1][j2] = ans;
    }
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        v<v<v<int>>> dp(m,v<v<int>>(n,v<int>(n,-1)));
        return fun(0,0,n-1,grid,m,n,dp);
    }
};