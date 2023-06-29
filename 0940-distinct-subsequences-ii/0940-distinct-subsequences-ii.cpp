class Solution {
public:
    int fun(string s)
    {
        int mod=1e9+7;
        int n=s.size();
        long long dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        unordered_map<char,int> m;
        for(int i=1;i<=n;i++)
        {
            if(m.find(s[i-1]) == m.end())
            {
                dp[i] = 2*dp[i-1]%mod;
            }
            else
            {
                dp[i] = (2*dp[i-1] - dp[m[s[i-1]] - 1])%mod;
            }
            m[s[i-1]]=i;
        }
        while(dp[n] <= 0)
        {
            dp[n] = dp[n] + mod;
        }
        return dp[n];
    }
    int distinctSubseqII(string s) 
    {
        return fun(s)-1;
    }
};