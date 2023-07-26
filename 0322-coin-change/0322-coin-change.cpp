class Solution {
public:
    int coinChange(vector<int>& a, int amount) 
    {
        int n=a.size();
        int dp[n+1][amount+1];
        dp[0][0]=0;
        for(int i=1;i<=n;i++)
        {
            dp[i][0]=0;
        }
        for(int i=0;i<=amount;i++)
        {
            dp[0][i]=INT_MAX-1;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(a[i-1] > j)
                {
                    dp[i][j] = dp[i-1][j];
                }
                else
                {
                    dp[i][j] = min(dp[i-1][j] , 1+dp[i][j-a[i-1]]);
                }
            }
        }
        return dp[n][amount]==INT_MAX-1 ? -1 : dp[n][amount];
    }
};