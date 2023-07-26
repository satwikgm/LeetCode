class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dp[m][n];
        memset(dp,0,sizeof(dp));
        dp[0][0] = grid[0][0];
        for(int i=1;i<n;i++) dp[0][i] = grid[0][i] + dp[0][i-1];
        for(int i=1;i<m;i++) {
            for(int j=0;j<n;j++) {
                dp[i][j]=grid[i][j];
                if(j>0) {
                    dp[i][j] += min(dp[i-1][j] , dp[i][j-1]);
                } else {
                    dp[i][j] += dp[i-1][j];
                }
            }
        }
        return dp[m-1][n-1];
    }
};