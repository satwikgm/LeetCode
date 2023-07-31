class Solution {
public:
    int funn(string s1,string s2,int m,int n)
    {
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++) dp[0][i] = dp[0][i-1] + s2[i-1];
        for(int i=1;i<=m;i++) dp[i][0] = dp[i-1][0] + s1[i-1];
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = min(s1[i-1]+dp[i-1][j] , s2[j-1]+dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    int minimumDeleteSum(string s1, string s2) {
        return funn(s1,s2,s1.size(),s2.size());
    }
};