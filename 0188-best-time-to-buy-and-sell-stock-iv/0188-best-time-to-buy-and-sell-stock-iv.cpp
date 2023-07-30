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
    int maxProfit(int k, vector<int>& prices) 
    {
        vector<vector<vector<int>>> dp(prices.size()+1 , vector<vector<int>>(2,vector<int>(k+1,-1)));
        return fun(prices,1,k,0,prices.size(),dp);
    }
};