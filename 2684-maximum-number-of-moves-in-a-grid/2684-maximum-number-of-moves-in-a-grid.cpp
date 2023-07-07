class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int dp[m][n];
        memset(dp,0,sizeof(dp));
        for(int j=1;j<n;j++)
        {
            for(int i=0;i<m;i++)
            {
                if(i-1>=0 && j-1>=0 && grid[i][j] > grid[i-1][j-1])
                {
                    if(j==1)
                    {
                        dp[i][j] = max(dp[i][j] , 1+dp[i-1][j-1]);
                    }
                    else if(dp[i-1][j-1]!=0)
                    {
                        dp[i][j] = max(dp[i][j] , 1+dp[i-1][j-1]);    
                    }
                }
                if(i+1<m && j-1>=0 && grid[i][j] > grid[i+1][j-1])
                {
                    if(j==1)
                    {
                        dp[i][j] = max(dp[i][j] , 1+dp[i+1][j-1]);
                    }
                    else if(dp[i+1][j-1]!=0)
                        dp[i][j] = max(dp[i][j] , 1+dp[i+1][j-1]);
                }
                if(j-1>=0 && grid[i][j] > grid[i][j-1])
                {
                    if(j==1)
                    {
                        dp[i][j] = max(dp[i][j] , 1+dp[i][j-1]);
                    }
                    else if(dp[i][j-1]!=0)
                        dp[i][j] = max(dp[i][j] , 1+dp[i][j-1]);
                }
            }
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};