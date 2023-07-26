class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int m = triangle.size();
        int n = triangle[m-1].size();
        int dp[m][n];
        dp[0][0]=triangle[0][0];
        for(int i=1;i<m;i++)
        {
            for(int j=i;j>=0;j--)
            {
                if(i==j)
                {
                    dp[i][j] = triangle[i][j] + dp[i-1][j-1];
                }
                else
                {
                    int x=INT_MAX;
                    if(j-1>=0) {
                        x=dp[i-1][j-1];
                    }
                    dp[i][j] = triangle[i][j] + min(dp[i-1][j] , x);
                }
            }
        }
        int mn=INT_MAX;
        for(int i=0;i<n;i++)
        {
            mn=min(mn,dp[m-1][i]);
        }
        return mn;
    }
};