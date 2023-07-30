class Solution {
public:
    int fun(vector<int> &a , int buy , int k , int i , int n , vector<vector<vector<int>>> &dp)
    {
        if(n==i || k==0)
        {
            return 0;
        }
        if(dp[i][buy][k] != -1)
            return dp[i][buy][k];
        if(buy)
        {
            return dp[i][buy][k] = max(  -a[i] + fun(a,0,k,i+1,n,dp)
                        ,  0 + fun(a,1,k,i+1,n,dp) );
        }
        else
        {
            return dp[i][buy][k] = max(  a[i] + fun(a,1,k-1,i+1,n,dp)
                        ,  fun(a,0,k,i+1,n,dp) );
        }
    }
    int funn(vector<int> &a , int k)
    {
        int n=a.size();
        int dp[n+1][2][k+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=1;buy>=0;buy--)
            {
                for(int lim=k;lim>0;lim--)
                {
                    if(buy)
                    {
                        dp[i][buy][lim]=max(-a[i]+dp[i+1][0][lim],
                                            0+dp[i+1][1][lim]);
                    }
                    else
                    {
                        dp[i][buy][lim]=max(a[i]+dp[i+1][1][lim-1],
                                            0+dp[i+1][0][lim]);
                    }
                }
            }
        }
        return dp[0][1][k];
    }
    int maxProfit(int k, vector<int>& prices) 
    {
        return funn(prices,k);
        vector<vector<vector<int>>> dp(prices.size()+1 , vector<vector<int>>(2,vector<int>(k+1,-1)));
        return fun(prices,1,k,0,prices.size(),dp);
    }
};