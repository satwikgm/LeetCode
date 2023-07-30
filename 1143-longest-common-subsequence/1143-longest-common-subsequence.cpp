class Solution {
public:
    int fun(string s1 , string s2 , int m , int n)
    {
        if(m==0 || n==0) return 0;
        if(s1[m-1] == s2[n-1])
        {
            return 1+fun(s1,s2,m-1,n-1);
        }
        return max(fun(s1,s2,m-1,n) , fun(s1,s2,m,n-1));
    }
    int lcs(string s1 , string s2 , int m , int n)
    {
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
    int longestCommonSubsequence(string text1, string text2) 
    {
        int m = text1.size();
        int n = text2.size();
        return lcs(text1,text2,m,n);
    }
};