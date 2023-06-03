class Solution {
public:
    int fun(vector<int> &arr1 , vector<int> &arr2 , int m , int n)
    {
        // if(m==0 || n==0)
        // {
        //     return 0;
        // }
        // if(arr1[m-1] == arr2[n-1])
        // {
        //     return 1 + fun(arr1,arr2,m-1,n-1);
        // }
        // return max(fun(arr1,arr2,m-1,n) , fun(arr1,arr2,m,n-1));
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(arr1[i-1] == arr2[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) 
    {
        return fun(nums1,nums2,nums1.size(),nums2.size());
    }
};