class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) 
    {
        int n = arr.size();
        int dp[n] , temp[n];
        dp[0]=1;temp[0]=1;
        int ans=dp[0];
        for(int i=1;i<n;i++)
        {
            dp[i]=1;
            temp[i]=1;
            for(int j=0;j<i;j++)
            {
                if(arr[j] < arr[i])
                {
                    if(1+dp[j] > dp[i])
                    {
                        dp[i] = 1+dp[j];
                        temp[i] = temp[j];
                    }
                    else if(1+dp[j] == dp[i])
                    {
                        temp[i] += temp[j];
                    }
                }
            }
            ans = max(ans , dp[i]);
        }
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i] == ans)
            {
                c += temp[i]; 
            }
        }
        return c;
    }
};